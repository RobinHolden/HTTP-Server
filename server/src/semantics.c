#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "httpparser.h"
#include "api.h"
#include "semantics.h"
#include "util.h"

void static pct_normalize(Node *node);
void static remove_dot_segments(Node *node);

char * const methods[] = {
	[GET] = "GET",
	[HEAD] = "HEAD"
};
char *const versions[] = {
	[HTTP1_0] = "HTTP/1.0",
	[HTTP1_1] = "HTTP/1.1"
};
char *const connections[] = {
	[KEEP_ALIVE] = "keep-alive",
	[CLOSE] = "close"
};
char * const hosts[] = {
	[SITE1_FR] = "site1.fr",
	[SITE2_FR] = "site2.fr"
};

Request *
semantics(_Token *root)
{
    _Token *tok;
    Node method, target, version, connection, coding, length1, length2, host;
	Request *req;
	int i;

	req = emalloc(sizeof(Request));

	req->host = -1;

	/* Traitement champ "method" */
	if ((tok = searchTree(root, "method")) == NULL) {
		req->status = 400;
		return req;
	}
	method.value = getElementValue(tok->node, &method.len);
	if (!strncmp(method.value, methods[GET], method.len)) {
		req->method = GET;
	} else if (!strncmp(method.value, methods[HEAD], method.len)){
		req->method = HEAD;
	} else {
        req->status = 501;
		return req;
	}
	purgeElement(&tok);

	/* Traitement champ "Request-target" */
	if ((tok = searchTree(root, "absolute_path")) == NULL) {
		req->status = 400;
		return req;
	}
	target.value = getElementValue(tok->node, &target.len);
	pct_normalize(&target);
	remove_dot_segments(&target);
	memmove(target.value, target.value + 1, target.len - 1);
	target.value[target.len - 1] = '\0';
	req->target = target.value;
	purgeElement(&tok);

	/* Traitement champ "HTTP-version" */
	if ((tok = searchTree(root, "HTTP_version")) == NULL) {
		req->status = 400;
		return req;
	}
	version.value = getElementValue(tok->node, &version.len);
	if (!strncmp(version.value, versions[HTTP1_0], version.len)) {
		req->version = HTTP1_0;
	} else if (!strncmp(version.value, versions[HTTP1_1], version.len)) {
		req->version = HTTP1_1;
	} else {
		req->status = 505;
		return req;
	}
	purgeElement(&tok);

	/* Traitement champs d'en-tête */
	/* Host */
	if (((tok = searchTree(root, "host")) == NULL && req->version == HTTP1_1)
	|| tok->next != NULL) {
		req->status = 400;
		return req;
	}
	purgeElement(&tok);

	if ((tok = searchTree(root, "reg_name")) != NULL) {
		host.value = getElementValue(tok->node, &host.len);
		for (i = 0; i < N_HOSTS; i++) {
			if (!strncmp(host.value, hosts[i], host.len)) {
				req->host = i;
				break;
			}
		}
	}
	purgeElement(&tok);

	/* Content-length */
	if ((tok = searchTree(root, "transfer_coding"))) {
		req->content_length = NULL;
	coding.value = getElementValue(tok->node, &coding.len);
		if (strncmp(coding.value, CHUNKED, coding.len)) {
			req->status = 400;
			return req;
		}
		if ((tok = searchTree(root, "Content_Length"))) {
			req->status = 400;
			return req;
		}
		purgeElement(&tok);
	} else {
		if ((tok = searchTree(root, "Content_Length"))) {
			while (tok->next != NULL) {
	length1.value = getElementValue(tok->node, &length1.len);
	length2.value = getElementValue(tok->node, &length2.len);
				if (length1.len != length2.len
				|| strncmp(length1.value, length2.value, length1.len)) {
					req->status = 400;
					return req;
				}
				tok = tok->next;
			}
			purgeElement(&tok);
		}
	}

	/* Connexion*/
	if ((tok = searchTree(root, "connection_option"))) {
		do {
	connection.value = getElementValue(tok->node, &connection.len);
			if (connection.len == strlen(connections[CLOSE])) {
				for (i = 0; i < connection.len; i++) {
					if (tolower(connection.value[i]) != connections[CLOSE][i])
						break;
				}
				if (i == connection.len) {
					req->connection = CLOSE;
					break;
				}
			} else if (connection.len == strlen(connections[KEEP_ALIVE])) {
				for (i = 0; i < connection.len; i++) {
					if (tolower(connection.value[i]) != connections[KEEP_ALIVE][i])
						break;
				}
				if (i == connection.len) {
					req->connection = KEEP_ALIVE;
					break;
				}
			}
			tok = tok->next;
		}
		while (tok->next != NULL);
		purgeElement(&tok);
	}
	if (req->connection != CLOSE && req->version == HTTP1_1) {
		req->connection = KEEP_ALIVE;
	}
		if (req->connection != CLOSE && req->connection != KEEP_ALIVE) {
		req->connection = CLOSE;
	}
	req->status = 200;
	return req;
}

void static
pct_normalize(Node *node)
{
	int i;
	char buf[3];

	buf[2] = '\0';

	/* While room for pct-encoded */
	for (i = 0; i + 2 < node->len; i++) {
		if (node->value[i] == '%'
		&& isxdigit(node->value[i + 1])
		&& isxdigit(node->value[i + 2])) {
			/* Format string for strtol */
			strncpy(buf, node->value + i + 1, 2);
			node->value[i] = strtol(buf, NULL, 16);
			/* Copy rest of s to the left */
			memmove(node->value + i + 1, node->value + i + 3, node->len - i - 3);
			node->len -= 2;
		}
	}
}

/* See RFC 3986 Section 5.2.4.*/
void static
remove_dot_segments(Node *node)
{
	int i, j;
	char *buf;

	buf = emalloc(node->len * sizeof(char));

	buf[0] = '\0';
	i = j = 0;
	while (i < node->len) {
		/* A */
		if (i <= node->len - strlen("../")
		&& node->value[i] == '.'
		&& node->value[i + 1] == '.'
		&& node->value[i + 2] == '/') {
			i += strlen("../");
		} else if (i <= node->len - strlen("./")
		&& node->value[i] == '.'
		&& node->value[i + 1] == '/') {
			i += strlen("./");
		/* B */
		} else if (i <= node->len - strlen("/./")
		&& node->value[i] == '/'
		&& node->value[i + 1] == '.'
		&& node->value[i + 2] == '/') {
			i += strlen("/.");
		} else if (i <= node->len - strlen("/.")
		&& node->value[i] == '/'
		&& node->value[i + 1] == '.'
		&& i + 2 == node->len ) {
			i += strlen("/");
			node->value[i + 1] = '/';
		/* C */
		} else if (i <= node->len - strlen("/../")
		&& node->value[i] == '/'
		&& node->value[i + 1] == '.'
		&& node->value[i + 2] == '.'
		&& node->value[i + 3] == '/') {
			i += strlen("/..");
			if (j != 0) {
				while (buf[j] != '/') {
					j--;
				}
			}
		} else if (i <= node->len - strlen("/..")
		&& node->value[i] == '/'
		&& node->value[i + 1] == '.'
		&& node->value[i + 2] == '.'
		&& i + 3 == node->len) {
			i += strlen("/.");
			node->value[i + 2] = '/';
			if (j != 0) {
				while (buf[j] != '/') {
					j--;
				}
			}
		/* D */
		} else if ( i <= node->len - strlen(".")
		&& node->value[i] == '.'
		&& i + 1 == node->len){
			i += strlen(".");
		} else if (i <= node->len - strlen("..")
		&& node->value[i] == '.'
		&& node->value[i + 1] == '.'
		&& i + 2 == node->len) {
			i += strlen("..");
		/* E */
		} else {
			do {
				buf[j] = node->value[i];
				j++;
				i++;
			} while (i < node->len && node->value[i] != '/');
		}
	}
	/* Replace by interpreted string */
	memmove(node->value, buf, j);
	free(buf);
	node->len = j;
}
