#ifndef _PHP_SERVER_H_
#define _PHP_SERVER_H_

#include <stdio.h>

#include "fastcgi.h"

#define PHP_RESULT_FILE "tmp.html"

void phptohtml(char *phpfile);

#endif
