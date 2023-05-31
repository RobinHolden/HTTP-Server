#include <stdio.h>
#include <magic.h>
#include <string.h>

#include "util.h"

char *
content_type(char *filename)
{
    const char *magic_full;
    magic_t magic_cookie;
    char *r;

    /* MAGIC_MIME tells magic to return a mime of the file,
       but you can specify different things	*/
    if (!strcmp(filename + strlen(filename) - strlen(".css"), ".css")) {
        return strdup("text/css; charset=us-ascii");
    }
    if ((magic_cookie = magic_open(MAGIC_MIME)) == NULL) {
        error("magic_open");
    }
    if (magic_load(magic_cookie, NULL) != 0) {
        magic_close(magic_cookie);
        error("magic_load");
    }
    magic_full = magic_file(magic_cookie, filename);
    printf("%s\n", magic_full);
    r = strdup(magic_full);
    magic_close(magic_cookie);
    return r;
}
