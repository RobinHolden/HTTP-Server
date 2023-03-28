#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "syntax.h"
#include "tree.h"
#include "util.h"

int
http_message(char **sp, char *s_end)
{
    int i;
    Node **cur;

    if (*sp > s_end)
        return 1;

    createnode(&root, "HTTP-message", *sp, s_end - *sp + 1, NULL, NULL);
    cur = &(root->child);

    if (start_line(sp, s_end, &cur))
        return 1;
    i = 0;
    while (1){
	    if (cat(header_field, crlf, sp, s_end, &cur))
	        break;
	    i++;
    }
    if (crlf(sp, s_end, &cur))
        return 1;
    message_body(sp, s_end, &cur);

    return 0;
}

int
cat(int (*f1)(char **, char *, Node ***), int (*f2)(char **, char *, Node ***),char **sp, char *s_end, Node ***cur)
{
	char *p;

	p = *sp;

	if (!f1(sp, s_end, cur))
		return 1;
	if (!f2(sp, s_end, cur)){
		*sp = p;
		return 1;
	}
	return 0;
}

int
header_field(char **sp, char *s_end, Node ***n)
{
    ;
}

int
crlf(char **sp, char *s_end, Node ***n)
{
    ;
}