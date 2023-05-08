#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "httpparser.h"
#include "api.h"
#include "semantics.h"
#include "util.h"

void static pct_normalize(Lnode *node);
int static pct_decode_char(char *s, int len, int i);
void static remove_dot_segments(Lnode *node);

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

Request *
semantics(_Token *root)
{
    _Token *tok;
    Lnode *method, *target, *version, *connection, *coding, *length1, *length2;
	Request *req;
	int i;
	
	req = emalloc(sizeof(Request));

	/* Traitement champ "method" */
	printf("Method\n");
	if ((tok = searchTree(root, "method")) == NULL) {
		req->status = 400;
		return req;
	}
	printf("1\n");
	printf("%p\n",tok->node);
	method = (Lnode *)tok->node;
	printf("2\n");
	printf("%p\n",method);
	printf("%p\n", method->value);
	if (!strncmp(method->value, methods[GET], method->len)) {
		printf("21\n");
		req->method = GET;
		printf("22\n");
	} else if (!strncmp(method->value, methods[HEAD], method->len)){
		printf("23\n");
		req->method = HEAD;
	} else {
		printf("24\n");
        req->status = 501;
		return req;
	}
	printf("3\n");
	purgeElement(&tok);
	printf("4\n");

	/* Traitement champ "Request-target" */
	printf("request-target\n");
	if ((tok = searchTree(root, "absolute_path")) == NULL) {
		req->status = 400;
		return req;
	}
	target = (Lnode *)tok->node;
	pct_normalize(target);
	remove_dot_segments(target);
	strncpy(req->target, target->value + 1, target->len);
	req->target[target->len - 1] = '\0';
	purgeElement(&tok);

	/* Traitement champ "HTTP-version" */
	printf("Version\n");
	if ((tok = searchTree(root, "HTTP_version")) == NULL) {
		req->status = 400;
		return req;
	}
	version = (Lnode *)tok->node;
	if (!strncmp(version->value, versions[HTTP1_0], version->len)) {
		req->version = HTTP1_0;
	} else if (!strncmp(version->value, versions[HTTP1_1], version->len)) {
		req->version = HTTP1_1;
	} else {
		req->status = 505;
		return req;
	}
	purgeElement(&tok);

	/* Traitement champs d'en-tête */
	/* Host */
	if (((tok = searchTree(root, "Host_header")) == NULL && req->version == HTTP1_1)
	|| tok->next != NULL) {
		req->status = 400;
		return req;
	}
	purgeElement(&tok);
	/* Content-length */
	if ((tok = searchTree(root, "transfer_coding"))) {
		req->content_length = NULL;
		coding = (Lnode *)tok->node;
		if (strncmp(coding->value, CHUNKED, coding->len)) {
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
				length1 = (Lnode *)tok->node;
				length2 = (Lnode *)tok->next->node;
				if (length1->len != length2->len
				|| strncmp(length1->value, length2->value, length1->len)) {
					req->status = 400;
					return req;
				}
				tok = tok->next;
			}
			purgeElement(&tok);
		}
		req->content_length = length1;
	}
	/* Connexion*/
	if ((tok = searchTree(root, "connection_option"))) {
		do {
			connection = (Lnode *)tok->node;
			if (connection->len == strlen(connections[CLOSE])) {
				for (i = 0; i < connection->len; i++) {
					if (tolower(connection->value[i]) != connections[CLOSE][i])
						break;
				}
				if (i == connection->len) {
					req->connection = CLOSE;
					break;
				}
			} else if (connection->len == strlen(connections[KEEP_ALIVE])) {
				for (i = 0; i < connection->len; i++) {
					if (tolower(connection->value[i]) != connections[KEEP_ALIVE][i])
						break;
				}
				if (i == connection->len) {
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
pct_normalize(Lnode *node)
{
	int i;

	/* While room for pct-encoded */
	for (i = 0; i + 2 < node->len; i++) {
		if (node->value[i] == '%') {
			if (pct_decode_char(node->value, node->len, i))
				node->len -= 2;
		}
	}
}

int static
pct_decode_char(char *s, int len, int i)
{
	char pctencoded[4];
	
	if (isxdigit(s[i + 1]) && isxdigit(s[i + 2])) {
		/* Format string for strtol */
		strncpy(pctencoded, s + i, 3);
		pctencoded[3] = '\0';
		char decoded = strtol(pctencoded + 1, NULL, 16);
		/* If unreserved character */
		if ((decoded >= 0x41 && decoded <= 0x5A)
		 || (decoded >= 0x61 && decoded <= 0x7A)
		 || (decoded >= 0x30 && decoded <= 0x39)
		  || decoded == 0x2D
		  || decoded == 0x2E
		  || decoded == 0x5F
		  || decoded == 0x7E) {
			/* Copy rest of s to the left */
			memmove(s + i + 1, s + i + 3, len - i - 3);
			/* Replace % by correct char */
			s[i] = decoded;
			return 1;
		}
	}
	return 0;
}

/* See RFC 3986 Section 5.2.4.*/
void static
remove_dot_segments(Lnode *node)
{
	int i, j;
	char buf[node->len];
	
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
				j--;
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
				j--;
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
	node->len = j;
}