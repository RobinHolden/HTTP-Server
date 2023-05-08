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

#include "semantics.h"

static const char * const status[] = {
	[200] = "HTTP/1.1 200 OK\r\n\r\n",
	[400] = "HTTP/1.1 400 Bad Request\r\n\r\n",
	[501] = "HTTP/1.1 501 Not Implemented\r\n\r\n",
	[505] = "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n"
};

int main(int argc, char *argv[])
{
	message *request;
	Lnode *root;
	Request *req;

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
			req = semantics(root);
			if (req->status != 0) {
				writeDirectClient(request->clientId, status[req->status], strlen(status[req->status]));
			} else {
				// Envoi
			}
			// writeDirectClient(request->clientId, status[code], strlen(status[code]));
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
