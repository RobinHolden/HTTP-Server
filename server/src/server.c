#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>

// for librequest
#include "request.h"

// for parser
#include "httpparser.h" // this will declare internal type used by the parser
#include "api.h"

#include "semantics.h"
#include "util.h"

static char * const status[] = {
	[200] = "HTTP/1.1 200 OK\r\n\r\n",
	[400] = "HTTP/1.1 400 Bad Request\r\n\r\n",
	[501] = "HTTP/1.1 501 Not Implemented\r\n\r\n",
	[505] = "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n"
};
#define CONNECTION "Connection: "
#define CONTENT_LENGTH "Content-Length: "
#define CRLF "\r\n"

int main(int argc, char *argv[])
{
	message *request;
	_Token *root;
	Request *req;
	int fi;
	struct stat st;
	char *body;
	char *length;

	while (1) {
		// On attend la reception d'une requete HTTP, request pointera vers une ressource allouée par librequest.
		if ((request = getRequest(8080)) == NULL)
			return -1;

		// Affichage de debug
		printf("#########################################\nDemande recue depuis le client %d\n", request->clientId);
		printf("Client [%d] [%s:%d]\n", request->clientId, inet_ntoa(request->clientAddress->sin_addr), htons(request->clientAddress->sin_port));
		printf("Contenu de la demande %.*s\n\n", request->len, request->buf);

		if (parseur(request->buf, request->len)) {
			printf("Parsing ok\n");
			root = getRootTree();
			req = semantics(root);
			printf("Semantics ok\n");
			writeDirectClient(request->clientId, status[req->status], strlen(status[req->status]));
			writeDirectClient(request->clientId, CRLF, strlen(CRLF));
			/* Error */
			if (req->status != 200) {
				writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				endWriteDirectClient(request->clientId);
				requestShutdownSocket(request->clientId);
			/* Valid */
			} else {
				writeDirectClient(request->clientId, CONNECTION, strlen(CONNECTION));
				writeDirectClient(request->clientId, connections[req->connection], strlen(connections[req->connection]));
				writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				if (req->method == GET) {
					writeDirectClient(request->clientId, CONTENT_LENGTH, strlen(CONTENT_LENGTH));
					/* Open target file */ 
					if ((fi = open(req->target + 1, O_RDWR)) == -1) {
						perror("open");
						exit(1);
        			}
					if (fstat(fi, &st) == -1) /* To obtain file size */
						exit(1);
					if ((body = mmap(NULL, st.st_size, PROT_WRITE, MAP_PRIVATE, fi, 0)) == NULL )
						exit(1);
					length = emalloc((int)log10(st.st_size) + 1);
					sprintf(length, "%ld", st.st_size);
					writeDirectClient(request->clientId, length, strlen(length));
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
					/* Write body */
					writeDirectClient(request->clientId, body, st.st_size);
				} else if (req->method == HEAD) {
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				}
				endWriteDirectClient(request->clientId);
				if (req->connection == CLOSE) {
					requestShutdownSocket(request->clientId);
				}
			}
			purgeTree(root);
		} else {
			writeDirectClient(request->clientId, status[400], strlen(status[400]));
			endWriteDirectClient(request->clientId);
			requestShutdownSocket(request->clientId);
		}
		// on ne se sert plus de request a partir de maintenant, on peut donc liberer...
		freeRequest(request);
	}
	return (1);
}
