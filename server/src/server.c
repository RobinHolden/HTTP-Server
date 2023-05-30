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
#include "mime.h"
#include "util.h"

#define PORT 8080
#define CONNECTION "Connection: "
#define CONTENT_LENGTH "Content-Length: "
#define CONTENT_TYPE "Content-Type: "
#define DEFAULT_TYPE "application/octet-stream"
#define CRLF "\r\n"
#define WWW "www"
#define DFLT_TARG "index.html"

int content_type(char *target);

char * const status[] = {
	[200] = "HTTP/1.1 200 OK",
	[400] = "HTTP/1.1 400 Bad Request",
	[404] = "HTTP/1.1 400 Not Found",
	[501] = "HTTP/1.1 501 Not Implemented",
	[505] = "HTTP/1.1 505 HTTP Version Not Supported"
};

int main(int argc, char *argv[])
{
	message *request;
	_Token *root;
	Request *req;
	int fi;
	struct stat st;
	char *body;
	char *length;
	char *target;
	int type;
	int i, j, k;

	while (1) {
		// On attend la reception d'une requete HTTP, request pointera vers une ressource allouée par librequest.
		printf("Waiting for request...\n");
		if ((request = getRequest(PORT)) == NULL)
			return -1;

		// Affichage de debug
		printf("#########################################\nDemande recue depuis le client %d\n", request->clientId);
		printf("Client [%d] [%s:%d]\n", request->clientId, inet_ntoa(request->clientAddress->sin_addr), htons(request->clientAddress->sin_port));
		printf("Contenu de la demande %.*s\n\n", request->len, request->buf);

		if (parseur(request->buf, request->len)) {
			printf("Valid request syntax\n");
			root = getRootTree();
			req = semantics(root);
			printf("Valid request semantics\n");

			/* Open target file */
			if (req->host == -1) {
				req->host = SITE1_FR;
			}
			if (req->target[0] == '\0') {
				req->target = strdup(DFLT_TARG);
			}
			target = emalloc(strlen(WWW) + strlen("/") + strlen(hosts[req->host]) + strlen("/") + strlen(req->target) + 1);
			for (i = 0; i < strlen(WWW); i++) {
				target[i] = WWW[i];
			}
			target[i++] = '/';
			for (j = 0; j < strlen(hosts[req->host]); j++) {
				if (hosts[req->host][j] == '.') {
					target[i + j] = '_';
				} else {
					target[i + j] = hosts[req->host][j];
				}
			}
			target[i + j] = '/';
			j++;
			for (k = 0; k < strlen(req->target); k++) {
				target[i + j + k] = req->target[k];
			}
			target[i + j + k] = '\0';
			//printf("Fetching requested resource: %s\n", target);
			if ((fi = open(target, O_RDWR)) == -1) {
				req->status = 404;
        	} else {
				if (fstat(fi, &st) == -1) /* To obtain file size */
					exit(1);
				if ((body = mmap(NULL, st.st_size, PROT_WRITE, MAP_PRIVATE, fi, 0)) == NULL )
					exit(1);
			}
			printf("Sending status code %d\n", req->status);
			writeDirectClient(request->clientId, status[req->status], strlen(status[req->status]));
			writeDirectClient(request->clientId, CRLF, strlen(CRLF));
			/* Error */
			if (req->status != 200) {
				printf("Client or server error in serving request\n");
				writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				endWriteDirectClient(request->clientId);
				requestShutdownSocket(request->clientId);
			/* Valid */
			} else {
				printf("Server able to serve request\n");
				writeDirectClient(request->clientId, CONNECTION, strlen(CONNECTION));
				writeDirectClient(request->clientId, connections[req->connection], strlen(connections[req->connection]));
				writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				if (req->method == GET) {
					printf("Answering GET request\n");
					writeDirectClient(request->clientId, CONTENT_LENGTH, strlen(CONTENT_LENGTH));
					length = emalloc((int)log10(st.st_size) + 2);
					sprintf(length, "%ld", st.st_size);
					writeDirectClient(request->clientId, length, strlen(length));
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
					free(length);
					/* Content-Type */
					writeDirectClient(request->clientId, CONTENT_TYPE, strlen(CONTENT_TYPE));
					if ((type = content_type(target)) != -1 && content_types[type][1][0] != '\0') {
						//printf("Content-Type: %s\n", content_types[type][1]);
						writeDirectClient(request->clientId, content_types[type][1], strlen(content_types[type][1]));
					} else {
						//printf("Content-Type: %s\n", DEFAULT_TYPE);
						writeDirectClient(request->clientId, DEFAULT_TYPE, strlen(DEFAULT_TYPE));
					}
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));

					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
					/* Write body */
					writeDirectClient(request->clientId, body, st.st_size);
				} else if (req->method == HEAD) {
					printf("Answering HEAD request\n");
					writeDirectClient(request->clientId, CRLF, strlen(CRLF));
				}
				endWriteDirectClient(request->clientId);
				if (req->connection == CLOSE) {
					printf("Closing connection.\n");
					requestShutdownSocket(request->clientId);
				}
			}
			purgeTree(root);
		} else {
			printf("Invalid request syntax\n");
			writeDirectClient(request->clientId, status[400], strlen(status[400]));
			endWriteDirectClient(request->clientId);
			printf("Closing connection.\n");
			requestShutdownSocket(request->clientId);
		}
		// on ne se sert plus de request a partir de maintenant, on peut donc liberer...
		freeRequest(request);
	}
	return (1);
}

int
content_type(char *target)
{
	int i, j;

	while (target && *target != '.') {
		target++;
	}
	if (!target) {
		return -1;
	} else {
		target++;
	}
	for (i = 0; i < N_TYPES; i++) {
		if (strlen(target) == strlen(content_types[i][0])) {
			for (j = 0; j < strlen(target); j++) {
				if (content_types[i][0][j] != target[j])
					break;
			}
			if (j == strlen(target))
				return i;
		}
	}
	return -1;
}
