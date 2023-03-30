`start`
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);



    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;

`*(rulename)`

    while (1) {
        if (rulename(sp, s_end, &cur)) {
            break;
        }
    }

`*(rulename1 rulename 2)`
    while (1) {
        p = *sp;
        if (rulename1(sp, s_end, &cur)
        || rulename2(sp, s_end, &cur)) {
            *sp = p;
            break;
        }
    }

`*(rulename1 / rulename 2)`
    while (1) {
        if (rulename1(sp, s_end, &cur)
        && rulename2(sp, s_end, &cur))
            break;
    }

`rulename`
    if (rulename(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }

`rulename1 rulename2`

    p = *sp;
    if (rulename1(sp, s_end, &cur)
    || rulename2(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }

`rulename1 / rulename2`
    if (rulename1(sp, s_end, &cur)
    && rulename2(sp, s_end, &cur)) {
        freeTree(**n);
        **n = NULL;
        return 1;
    }

`[rulename1 rulename2]`
    p1 = *sp;
    if (rulename1(sp, s_end, &cur)
    || rulename2(sp, s_end, &cur))
        *sp = p1;

`rulename1 /rulename2 / charset`
    if (rulename1(sp, s_end, &cur)
    && rulename2(sp, s_end, &cur)) {
        if (s_end - *sp + 1 < 1
        || **sp < charset_start || **sp > charset_end){
            freeTree(**n);
            **n = NULL;
            return 1;
        }
        createnode(*n, "rulename", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 0;
    }

`charset`
int
rulename(char **sp, char *s_end, Node ***n)
{
    if (s_end - *sp + 1 < 1)
        return 1;
    if (**sp >= charset_start && **sp <= charset_end) {
        createnode(*n, "rulename", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 0;
    }
    return 1;
}

`"string"`
int
string_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "string";

    if (s_end - *sp + 1 < strlen(s))
        return 1;
    for (i = 0; i < strlen(s); i++){
        if (tolower(s[i]) != tolower((*sp)[i]))
            return 1;
    }
    createnode(*n, s, *sp, strlen(s), NULL, NULL);
    *n = &((**n)->sibling);
    *sp += strlen(s);
    return 0;
}

`cur`
cur : host