#include <ctype.h>
#include <string.h>

#include "httpparser.h"
#include "api.h"

#define GET "GET"
#define HEAD "HEAD"
#define POST "POST"

void static pct_normalize(Lnode *node);
int static pct_decode_char(char *s, int len, int i);

int
semantics(Lnode *root)
{
    _Token *r, *tok;
    Lnode *node;

	/* Traitement champ "method" */
	tok = searchTree(root, "method");
	node = (Lnode *)tok->node;
	if (strncmp(node->value, GET, strlen(GET))
	&& strncmp(node->value, HEAD, strlen(HEAD))
	&& strncmp(node->value, POST, strlen(POST))) {
        return 501;
	}
	/* Traitement champ "Request-target" */
	tok = searchTree(root, "Request_target");
	node = (Lnode *)tok->node;
	pct_normalize(node);

	/* Traitement champ "HTTP-version" */
	/* Traitement champs d'en-tête */
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
	/*
	ALPHA: (%41-%5A and %61-%7A), DIGIT (%30-%39), hyphen (%2D), period (%2E),
   underscore (%5F), or tilde (%7E)
   */
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