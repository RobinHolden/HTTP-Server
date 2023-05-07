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

#define ERROR "HTTP/1.0 400 SUCKA\r\n\r\n"
#define REPONSE "HTTP/1.0 200 OK\r\nContent-type: text/plain\r\n\r\nHey Bro why did you send me this:\r\n"

int main(int argc, char *argv[])
{
	message *request;
	int res;
	_Token *r, *tok;
	Lnode *root;

	while (1) {
		// On attend la reception d'une requete HTTP, request pointera vers une ressource allouée par librequest.
		if ((request = getRequest(8080)) == NULL)
			return -1;

		// Affichage de debug
		printf("#########################################\nDemande recue depuis le client %d\n", request->clientId);
		printf("Client [%d] [%s:%d]\n", request->clientId, inet_ntoa(request->clientAddress->sin_addr), htons(request->clientAddress->sin_port));
		printf("Contenu de la demande %.*s\n\n", request->len, request->buf);

		if (res = parseur(request->buf, request->len)) {
			root = getRootTree();
			

			
			// purgeElement(&r);
			purgeTree(root);
		} else {
			writeDirectClient(request->clientId, ERROR, strlen(ERROR));
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