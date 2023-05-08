#include <ctype.h>
#include <string.h>

#include "httpparser.h"
#include "api.h"

#define GET "GET"
#define HEAD "HEAD"
#define POST "POST"

#define HTTP1_0 "HTTP/1.0"
#define HTTP1_1 "HTTP/1.1"

void static pct_normalize(Lnode *node);
int static pct_decode_char(char *s, int len, int i);
void static remove_dot_segments(Lnode *node);

int
semantics(Lnode *root)
{
    _Token *tok;
    Lnode *method, *target, *version, *host, *connection;
	int minor_version;

	/* Traitement champ "method" */
	if ((tok = searchTree(root, "method")) == NULL) {
		return 400;
	}
	method = (Lnode *)tok->node;
	if (strncmp(method->value, GET, method->len)
	&& strncmp(method->value, HEAD, method->len)) {
        return 501;
	}
	purgeElement(&tok);

	/* Traitement champ "Request-target" */
	if ((tok = searchTree(root, "Request_target")) == NULL) {
		return 400;
	}
	target = (Lnode *)tok->node;
	pct_normalize(target);
	remove_dot_segments(target);
	purgeElement(&tok);

	/* Traitement champ "HTTP-version" */
	if ((tok = searchTree(root, "HTTP_version")) == NULL) {
		return 400;
	}
	version = (Lnode *)tok->node;
	if (!strncmp(version->value, HTTP1_0, version->len)) {
		minor_version = 0;
	} else if (!strncmp(version->value, HTTP1_1, version->len)) {
		minor_version = 1;
	} else {
		return 505;
	}
	purgeElement(&tok);

	/* Traitement champs d'en-tête */
	/* Host */
	if ((tok = searchTree(root, "Host_header")) == NULL) {
		 
	}
	host = (Lnode *)tok->node;
	
	return 0;
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