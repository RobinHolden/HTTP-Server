#ifndef _SYNTAX_H_
#define _SYNTAX_H_

#include "tree.h"

int http_message(char **sp, char *s_end);
int cat(int (*f1)(char **, char *, Node ***), int (*f2)(char **, char *, Node ***),char **sp, char *s_end, Node ***cur);

int header_field(char **sp, char *s_end, Node ***n);
int crlf(char **sp, char *s_end, Node ***n);

#endif