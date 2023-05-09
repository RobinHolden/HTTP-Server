#ifndef _SEMANTICS_H_
#define _SEMANTICS_H_

#include <string.h>

#include "httpparser.h"

enum methods {
    GET,
    HEAD
};
enum versions {
    HTTP1_0,
    HTTP1_1
};
enum connections {
    KEEP_ALIVE,
    CLOSE
};
extern char * const methods[];
extern char * const versions[];
extern char * const connections[];

#define CHUNKED "chunked"

typedef struct node {
	char *value;
	int len;
} Node;

typedef struct request {
    int method;
    int version;
    int connection;
    Node *content_length;
    char *target;
    int status;
} Request;

Request *semantics(_Token *root);

#endif


