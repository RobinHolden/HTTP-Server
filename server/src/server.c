#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// for librequest
#include "request.h"

// for parser
#include "httpparser.h" // this will declare internal type used by the parser
#include "api.h"

static const char * const status[] = {
	[200] = "HTTP/1.0 200 OK\r\n\r\n",
	[400] = "HTTP/1.0 400 Bad Request\r\n\r\n",
	[501] = "HTTP/1.0 501 Not Implemented\r\n\r\n"
};

int main(int argc, char *argv[])
{
	message *request;
	int code;
	_Token *r, *tok;
	Lnode *root, *node;

	while (1) {
		// On attend la reception d'une requete HTTP, request pointera vers une ressource allouée par librequest.
		if ((request = getRequest(8080)) == NULL)
			return -1;

		// Affichage de debug
		printf("#########################################\nDemande recue depuis le client %d\n", request->clientId);
		printf("Client [%d] [%s:%d]\n", request->clientId, inet_ntoa(request->clientAddress->sin_addr), htons(request->clientAddress->sin_port));
		printf("Contenu de la demande %.*s\n\n", request->len, request->buf);

		if (parseur(request->buf, request->len)) {
			root = getRootTree();
			if ((code = semantics(root)) == 0) {
				;// GOOD
			} else {
				writeDirectClient(request->clientId, status[code], strlen(status[code]));
			}
			// purgeElement(&r);
			purgeTree(root);
		} else {
			writeDirectClient(request->clientId, status[400], strlen(status[400]));
		}
		endWriteDirectClient(request->clientId);
		requestShutdownSocket(request->clientId);
		// on ne se sert plus de request a partir de maintenant, on peut donc liberer...
		freeRequest(request);
	}
	return (1);
}








/*
	writeDirectClient(request->clientId, REPONSE, strlen(REPONSE));


			tok = r;
			while (tok) {
				int l;
				char *s;
				Lnode *node;
				node = (Lnode *)tok->node;
				writeDirectClient(request->clientId, node->value, node->len);
				tok = tok->next;
			}
			*/