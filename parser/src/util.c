#include <stdlib.h>
#include <stdio.h>

#include <stddef.h>

void
*emalloc(size_t size)
{
	void *p = NULL;

	if ((p = malloc(size)) == NULL){
		perror("malloc");
        exit(1);
    }
	return p;
}