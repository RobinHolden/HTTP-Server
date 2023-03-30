`start`
    Node *cur;
    char *p;

    createnode(*n, "header-field", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

`end`
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

`(rulename1 rulename2)`

    p1 = *sp;
    if (rulename1(sp, s_end, &cur)
    || rulename2(sp, s_end, &cur)) {
        *sp = p1;
    }

`rulename`
    if (rulename(sp, s_end, &cur)) {
            free(**n);
            **n = NULL;
            return 1;
    }

`"string"`
    int i;
    const char *s;

    s = "string";

    if (s_end - *sp + 1 < strlen(s))
        return 1;
    for (i = 0; i < strlen(s); i++){
        if (s[i] != tolower((*sp)[i]))
            return 1;
    }
    *sp += strlen(s);
    return 0;
