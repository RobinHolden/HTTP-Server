#ifndef _PHP_SERVER_H_
#define _PHP_SERVER_H_

#include <stdio.h>

#include "fastcgi.h"

#define PHP_RESULT_FILE "tmp.html"

void phptohtml(char *phpfile);

size_t readSocket(int fd,char *buf,size_t len);
void readData(int fd,FCGI_Header *h,size_t *len);
void writeSocket(int fd,FCGI_Header *h,unsigned int len);
void writeLen(int len, char **p);
int addNameValuePair(FCGI_Header *h,char *name,char *value);
void sendGetValue(int fd);
void sendBeginRequest(int fd,unsigned short requestId,unsigned short role,unsigned char flags);
void sendAbortRequest(int fd,unsigned short requestId);
void sendWebData(int fd,unsigned char type,unsigned short requestId,char *data,unsigned int len);
static int createSocket(int port);

#endif
