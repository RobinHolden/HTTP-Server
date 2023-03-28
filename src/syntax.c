#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "syntax.h"
#include "tree.h"
#include "util.h"

int
message(char **sp, char *s_end)
{
    int i;
    Node **cur;

    i = 0;
    createnode(&root, "message", *sp, s_end - *sp + 1, NULL, NULL);
    cur = &(root->child);

    if (*sp > s_end)
        return 0;
    if (!debut(sp, s_end, NULL))
        return 0;
    while (1){
	    if (!cat(mot, ponct, sp, s_end, &cur)){
	        if (!cat(nombre, separateur, sp, s_end, &cur)){
		        break;
	        }
	    }
	    i++;
    }
    if (i < 2)
        return 0;
    ponct(sp, s_end, &cur);
    if (!fin(sp, s_end, NULL))
        return 0;
    if (**sp != '\n')
        return 0;
    return 1;
}

int
cat(int (*f1)(char **, char *, Node ***), int (*f2)(char **, char *, Node ***),char **sp, char *s_end, Node ***cur)
{
	char *p;

	p = *sp;

	if (!f1(sp, s_end, cur))
		return 0;
	if (!f2(sp, s_end, cur)){
		*sp = p;
		return 0;
	}
	return 1;
}

int
debut(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "start";

    if (s_end - *sp + 1 < strlen(s))
        return 0;
    for (i = 0; i < strlen(s); i++){
        if (s[i] != tolower((*sp)[i]))
            return 0;
    }
    *sp += strlen(s);
    return 1;
}

int
fin(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "fin";

    if (s_end - *sp + 1 < strlen(s))
        return 0;
    for (i = 0; i < strlen(s); i++){
        if (s[i] != tolower((*sp)[i]))
            return 0;
    }
    *sp += strlen(s);
    return 1;
}

int
mot(char **sp, char *s_end, Node ***n)
{
    int i;
    char *s;
    Node **cur;

    s = *sp;

    for (i = 0; s <= s_end ; i++){
        if (!isalpha(*s))
            break;
        s++;
    }
    if (i == 0)
        return 0;
    createnode(*n, "mot", *sp, i + 1, NULL, NULL);
    *sp += i;

    cur = &((**n)->child);
    if (!separateur(sp, s_end, &cur)){
        *sp -= i;
        free(**n);
	    **n = NULL;
        return 0;
    }
    *n = &((**n)->sibling);
    return 1;
}

int
nombre(char **sp, char *s_end , Node ***n)
{
    int i;
    char *s;

    s = *sp;

    for (i = 0; s <= s_end ; i++){
        if (!isdigit(*s))
            break;
        s++;
    }
    if (i == 0)
        return 0;
    createnode(*n, "nombre", *sp, i, NULL, NULL);
    *n = &((**n)->sibling);
    *sp += i;
    return 1;
}

int
ponct(char **sp, char *s_end, Node ***n)
{
    if (*sp > s_end)
        return 0;
    switch(**sp){
    case ',': /* FALLTHROUGH */
    case '.':
    case '!':
    case '?':
    case ':':
        createnode(*n, "ponct", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 1;
    default:
        return 0;
    }
}

int
separateur(char **sp, char *s_end, Node ***n)
{
    if (*sp > s_end)
        return 0;
    switch(**sp){
    case ' ': /* FALLTHROUGH */
    case '\t':
    case '-':
    case '_':
        createnode(*n, "separateur", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 1;
    default:
        return 0;
    }
}
