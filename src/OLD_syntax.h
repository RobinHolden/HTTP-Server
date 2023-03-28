#ifndef _OLD_SYNTAX_H_
#define _OLD_SYNTAX_H_

#include "tree.h"

int message(char **sp, char *s_end);
int debut(char **sp, char *s_end, Node ***n);
int fin(char **sp, char *s_end, Node ***n);
int mot(char **sp, char *s_end, Node ***n);
int nombre(char **sp, char *s_end, Node ***n);
int ponct(char **sp, char *s_end, Node ***n);
int separateur(char **sp, char *s_end, Node ***n);
int cat(int (*f1)(char **, char *, Node ***), int (*f2)(char **, char *, Node ***),char **sp, char *s_end, Node ***cur);
/*
nombre = 1*DIGIT
ponct = "," / "." / "!" / "?" / ":"
separateur = SP / HTAB / "-" / "_"
debut = "start"
fin = "fin"
mot = 1*ALPHA separateur
message = debut 2*( mot ponct / nombre separateur ) [ponct] fin LF
*/

#endif
