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
	[200] = "HTTP/1.1 200 OK\r\n\r\n",
	[400] = "HTTP/1.1 400 Bad Request\r\n\r\n",
	[501] = "HTTP/1.1 501 Not Implemented\r\n\r\n",
	[505] = "HTTP/1.1 505 HTTP Version Not Supported\r\n\r\n"
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

/* Content-length :
   3.  If a Transfer-Encoding header field is present and the chunked
       transfer coding (Section 4.1) is the final encoding, the message
       body length is determined by reading and decoding the chunked
       data until the transfer coding indicates the data is complete.

    	If a Transfer-Encoding header field
       is present in a request and the chunked transfer coding is not
       the final encoding, the message body length cannot be determined
       reliably; the server MUST respond with the 400 (Bad Request)
       status code and then close the connection.

       If a message is received with both a Transfer-Encoding and a
       Content-Length header field, might indicate an attempt to
       perform request smuggling (Section 9.5) or response splitting
       (Section 9.4) and ought to be handled as an error. --> 400

   4.  If a message is received without Transfer-Encoding and with
       either multiple Content-Length header fields having differing
       field-values or a single Content-Length header field having an
       invalid value --> 400

   5.  If a valid Content-Length header field is present without
       Transfer-Encoding, its decimal value defines the expected message
       body length in octets. If body ends before content-length --> 400

   6.  If this is a request message and none of the above are true, then
       the message body length is zero (no message body is present).
*/

/*
 Host: 
	1.1 : obligatoire --> 400 sinon
	1.0 --> pas obl
	plusieurs host: --> 400
*/

/* Connection 
o  If the "close" connection option is present, the connection will
      not persist after the current response; else,

   o  If the received protocol is HTTP/1.1 (or later), the connection
      will persist after the current response; else,

   o  If the received protocol is HTTP/1.0, the "keep-alive" connection
      option is present, the recipient is not a proxy, and the recipient
      wishes to honor the HTTP/1.0 "keep-alive" mechanism, the
      connection will persist after the current response; otherwise,

   o  The connection will close after the current response.
*/



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