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

    if (start_line(sp, s_end, &cur)){
        freeTree(root);
        return 1;
    }
    i = 0;
    while (1){
	    if (cat(header_field, crlf, sp, s_end, &cur))
	        break;
	    i++;
    }
    if (crlf(sp, s_end, &cur)){
        freeTree(root);
        return 1;
    }
    message_body(sp, s_end, &cur);

    if (*sp != s_end){
        freeTree(root);
        return 1;
    }
    return 0;
}

int
crlf(char **sp, char *s_end, Node ***n)
{
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
}

int
http_message(char **sp, char *s_end, Node ***n)
{
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
}

int
http_name(char **sp, char *s_end, Node ***n)
{
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
}

int
http_version(char **sp, char *s_end, Node ***n)
{
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
}

int
field_content(char **sp, char *s_end, Node ***n)
{
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
}

int
field_name(char **sp, char *s_end, Node ***n)
{
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
}

int
field_value(char **sp, char *s_end, Node ***n)
{
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
}

int
field_vchar(char **sp, char *s_end, Node ***n)
{
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
}

int
last_chunk(char **sp, char *s_end, Node ***n)
{
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
}

int
message_body(char **sp, char *s_end, Node ***n)
{
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
}

int
method(char **sp, char *s_end, Node ***n)
{
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
}

int
obs_fold(char **sp, char *s_end, Node ***n)
{
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
}

int
obs_text(char **sp, char *s_end, Node ***n)
{
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
}

int
origin_form(char **sp, char *s_end, Node ***n)
{
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
}

int
reason_phrase(char **sp, char *s_end, Node ***n)
{
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
}

int
request_line(char **sp, char *s_end, Node ***n)
{
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
}

int
request_target(char **sp, char *s_end, Node ***n)
{
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
}

int
start_line(char **sp, char *s_end, Node ***n)
{
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
}

int
status_code(char **sp, char *s_end, Node ***n)
{
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
}

int
status_line(char **sp, char *s_end, Node ***n)
{
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
}

int
uri(char **sp, char *s_end, Node ***n)
{
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
}

int
hier_part(char **sp, char *s_end, Node ***n)
{
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
}

int
uri_reference(char **sp, char *s_end, Node ***n)
{
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
}

int
absolute_uri(char **sp, char *s_end, Node ***n)
{
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
}

int
relative_ref(char **sp, char *s_end, Node ***n)
{
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
}

int
relative_part(char **sp, char *s_end, Node ***n)
{
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
}

int
scheme(char **sp, char *s_end, Node ***n)
{
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
}

int
absolute_form(char **sp, char *s_end, Node ***n)
{
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
}

int
absolute_path(char **sp, char *s_end, Node ***n)
{
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
}

int
asterisk_form(char **sp, char *s_end, Node ***n)
{
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
}

int
authority_form(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk_data(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk_ext(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk_ext_name(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk_ext_val(char **sp, char *s_end, Node ***n)
{
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
}

int
chunk_size(char **sp, char *s_end, Node ***n)
{
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
}

int
chunked_body(char **sp, char *s_end, Node ***n)
{
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
}

int
authority(char **sp, char *s_end, Node ***n)
{
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
}

int
userinfo(char **sp, char *s_end, Node ***n)
{
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
}

int
host(char **sp, char *s_end, Node ***n)
{
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
}

int
port(char **sp, char *s_end, Node ***n)
{
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
}

int
ip_literal(char **sp, char *s_end, Node ***n)
{
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
}

int
ipvfuture(char **sp, char *s_end, Node ***n)
{
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
}

int
ipv6address(char **sp, char *s_end, Node ***n)
{
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
}

int
h16(char **sp, char *s_end, Node ***n)
{
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
}

int
ls32(char **sp, char *s_end, Node ***n)
{
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
}

int
ipv4address(char **sp, char *s_end, Node ***n)
{
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
}

int
dec_octet(char **sp, char *s_end, Node ***n)
{
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
}

int
reg_name(char **sp, char *s_end, Node ***n)
{
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
}

int
path(char **sp, char *s_end, Node ***n)
{
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
}

int
path_abempty(char **sp, char *s_end, Node ***n)
{
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
}

int
path_absolute(char **sp, char *s_end, Node ***n)
{
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
}

int
path_noscheme(char **sp, char *s_end, Node ***n)
{
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
}

int
path_rootless(char **sp, char *s_end, Node ***n)
{
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
}

int
path_empty(char **sp, char *s_end, Node ***n)
{
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
}

int
segment(char **sp, char *s_end, Node ***n)
{
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
}

int
segment_nz(char **sp, char *s_end, Node ***n)
{
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
}

int
segment_nz_nc(char **sp, char *s_end, Node ***n)
{
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
}

int
pchar(char **sp, char *s_end, Node ***n)
{
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
}

int
query(char **sp, char *s_end, Node ***n)
{
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
}

int
fragment(char **sp, char *s_end, Node ***n)
{
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
}

int
pct_encoded(char **sp, char *s_end, Node ***n)
{
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
}

int
unreserved(char **sp, char *s_end, Node ***n)
{
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
}

int
reserved(char **sp, char *s_end, Node ***n)
{
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
}

int
gen_delims(char **sp, char *s_end, Node ***n)
{
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
}

int
sub_delims(char **sp, char *s_end, Node ***n)
{
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
}

int
language_range(char **sp, char *s_end, Node ***n)
{
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
}

int
alphanum(char **sp, char *s_end, Node ***n)
{
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
}

int
language_tag(char **sp, char *s_end, Node ***n)
{
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
}

int
langtag(char **sp, char *s_end, Node ***n)
{
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
}

int
language(char **sp, char *s_end, Node ***n)
{
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
}

int
extlang(char **sp, char *s_end, Node ***n)
{
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
}

int
script(char **sp, char *s_end, Node ***n)
{
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
}

int
region(char **sp, char *s_end, Node ***n)
{
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
}

int
variant(char **sp, char *s_end, Node ***n)
{
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
}

int
extension(char **sp, char *s_end, Node ***n)
{
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
}

int
singleton(char **sp, char *s_end, Node ***n)
{
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
}

int
privateuse(char **sp, char *s_end, Node ***n)
{
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
}

int
grandfathered(char **sp, char *s_end, Node ***n)
{
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
}

int
irregular(char **sp, char *s_end, Node ***n)
{
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
}

int
regular(char **sp, char *s_end, Node ***n)
{
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
}

int
bws(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (ows(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
connection(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p1, *p2, *p3;

    createnode(*n, "Connection", *sp, 0, NULL, NULL);
    
    cur = &((**n)->child);

    p1 = *sp;
    while (1) {
        p2 = *sp;
        if (comma_s(sp, s_end, &cur)
        || ows(sp, s_end, &cur)) {
            *sp = p2;
            break;
        }
    }
    if (connection_option(sp, s_end, &cur)){
        *sp = p1;
        freeTree(**n);
        **n = NULL;
        return 1;
    }
    while (1) {
        p2 = *sp;
        if (ows(sp, s_end, &cur)
        || comma_s(sp, s_end, &cur)) {
            *sp = p2;
            break;
        }
        p3 = *sp;
        if (ows(sp, s_end, &cur)
        || connection_option(sp, s_end, &cur)){
            *sp = p3;
        }
    }
    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
connection_option(char **sp, char *s_end, Node ***n)
{
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
}

int
content_length(char **sp, char *s_end, Node ***n)
{
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
}

int
host(char **sp, char *s_end, Node ***n)
{
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
}

int
ows(char **sp, char *s_end, Node ***n)
{
    int i;

    for (i = 0; s_end - *sp + 1 > 0 && ((*sp)[i] == ' ' || (*sp)[i] == '\t'); i++) {
        ;
    }
    createnode(*n, "OWS", *sp, i, NULL, NULL);
    *n = &((**n)->sibling);
    *sp += i;
    return 0;
}

int
rws(char **sp, char *s_end, Node ***n)
{
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
}

int
te(char **sp, char *s_end, Node ***n)
{
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
}

int
trailer(char **sp, char *s_end, Node ***n)
{
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
}

int
transfer_encoding(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p1, *p2, *p3;

    createnode(*n, "Transfer-Encoding", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p1 = *sp;
    while (1) {
        p2 = *sp;
        if (comma_s(sp, s_end, &cur)
        || ows(sp, s_end, &cur)) {
            *sp = p2;
            break;
        }
    }
    if (transfer_coding(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }
    while (1) {
        p2 = *sp;
        if (ows(sp, s_end, &cur)
        || comma_s(sp, s_end, &cur)) {
            *sp = p2;
            break;
        }
        p3 = *sp;
        if (ows(sp, s_end, &cur)
        || transfer_coding(sp, s_end, &cur))
            *sp = p3;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
upgrade(char **sp, char *s_end, Node ***n)
{
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
}

int
via(char **sp, char *s_end, Node ***n)
{
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
}

int
comment(char **sp, char *s_end, Node ***n)
{
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
}

int
comment(char **sp, char *s_end, Node ***n)
{
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
}

int
connection_option(char **sp, char *s_end, Node ***n)
{
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
}

int
ctext(char **sp, char *s_end, Node ***n)
{
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
}

int
http_uri(char **sp, char *s_end, Node ***n)
{
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
}

int
fragment(char **sp, char *s_end, Node ***n)
{
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
}

int
https_uri(char **sp, char *s_end, Node ***n)
{
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
}

int
fragment(char **sp, char *s_end, Node ***n)
{
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
}

int
partial_uri(char **sp, char *s_end, Node ***n)
{
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
}

int
protocol(char **sp, char *s_end, Node ***n)
{
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
}

int
protocol_name(char **sp, char *s_end, Node ***n)
{
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
}

int
protocol_version(char **sp, char *s_end, Node ***n)
{
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
}

int
pseudonym(char **sp, char *s_end, Node ***n)
{
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
}

int
qdtext(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (htab(sp, s_end, &cur)
    && space(sp, s_end, &cur)
    && exclamation_s(sp, s_end, &cur)) {
        if (s_end - *sp + 1 < 1 || **sp < 0x23 || **sp > 0x5B){
            freeTree(**n);
            **n = NULL;
            return 1;
        }
        createnode(*n, "qdtext", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 0;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
quoted_pair(char **sp, char *s_end, Node ***n)
{
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
}

int
quoted_string(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (dquote(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }
    while (1) {
        if (qdtext(sp, s_end, &cur)
        && quoted_pair(sp, s_end, &cur))
            break;
    }
    if (dquote(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
rank(char **sp, char *s_end, Node ***n)
{
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
}

int
received_by(char **sp, char *s_end, Node ***n)
{
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
}

int
received_protocol(char **sp, char *s_end, Node ***n)
{
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
}

int
t_codings(char **sp, char *s_end, Node ***n)
{
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
}

int
t_ranking(char **sp, char *s_end, Node ***n)
{
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
}

int
tchar(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (exclamation_s(sp, s_end, &cur)
    && hash_s(sp, s_end, &cur)
    && dollar_s(sp, s_end, &cur)
    && percent_s(sp, s_end, &cur)
    && ampersand_s(sp, s_end, &cur)
    && quote_s(sp, s_end, &cur)
    && asterisk_s(sp, s_end, &cur)
    && plus_s(sp, s_end, &cur)
    && minus_s(sp, s_end, &cur)
    && period_s(sp, s_end, &cur)
    && caret_s(sp, s_end, &cur)
    && underscore_s(sp, s_end, &cur)
    && backtick_s(sp, s_end, &cur)
    && vbar_s(sp, s_end, &cur)
    && tilde_s(sp, s_end, &cur)
    && digit(sp, s_end, &cur)
    && alpha(sp, s_end, &cur)) {
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
token(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;
    int i;

    createnode(*n, "token", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    while (1) {
        if (tchar(sp, s_end, &cur)) {
            break;
        }
        i++;
    }
    if (i < 1){
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
trailer_part(char **sp, char *s_end, Node ***n)
{
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
}

int
transfer_coding(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (chunked_s(sp, s_end, &cur)
    && compress_s(sp, s_end, &cur)
    && deflate_s(sp, s_end, &cur)
    && gzip_s(sp, s_end, &cur)
    && transfer_extension(sp, s_end, &cur)) {
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
transfer_extension(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (token(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }
    while (1) {
        p = *sp;
        if (ows(sp, s_end, &cur)
        || semicolon_s(sp, s_end, &cur)
        || ows(sp, s_end, &cur)
        || transfer_parameter(sp, s_end, &cur)) {
            *sp = p;
            break;
        }
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
transfer_parameter(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p = *sp;
    if (token(sp, s_end, &cur)
    || bws(sp, s_end, &cur)
    || equals_s(sp, s_end, &cur)
    || bws(sp, s_end, &cur)
    || token(sp, s_end, &cur) && quoted_string(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }
    
    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
uri_host(char **sp, char *s_end, Node ***n)
{
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
}

int
accept(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_charset(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_encoding(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_language(char **sp, char *s_end, Node ***n)
{
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
}

int
allow(char **sp, char *s_end, Node ***n)
{
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
}

int
content_encoding(char **sp, char *s_end, Node ***n)
{
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
}

int
content_language(char **sp, char *s_end, Node ***n)
{
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
}

int
content_location(char **sp, char *s_end, Node ***n)
{
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
}

int
content_type(char **sp, char *s_end, Node ***n)
{
    Node *cur;

    createnode(*n, "Content-Type", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (media_type(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
date(char **sp, char *s_end, Node ***n)
{
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
}

int
expect(char **sp, char *s_end, Node ***n)
{
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
}

int
gmt(char **sp, char *s_end, Node ***n)
{
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
}

int
http_date(char **sp, char *s_end, Node ***n)
{
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
}

int
imf_fixdate(char **sp, char *s_end, Node ***n)
{
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
}

int
location(char **sp, char *s_end, Node ***n)
{
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
}

int
max_forwards(char **sp, char *s_end, Node ***n)
{
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
}

int
referer(char **sp, char *s_end, Node ***n)
{
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
}

int
retry_after(char **sp, char *s_end, Node ***n)
{
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
}

int
server(char **sp, char *s_end, Node ***n)
{
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
}

int
user_agent(char **sp, char *s_end, Node ***n)
{
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
}

int
vary(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_ext(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_params(char **sp, char *s_end, Node ***n)
{
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
}

int
asctime_date(char **sp, char *s_end, Node ***n)
{
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
}

int
charset(char **sp, char *s_end, Node ***n)
{
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
}

int
codings(char **sp, char *s_end, Node ***n)
{
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
}

int
content_coding(char **sp, char *s_end, Node ***n)
{
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
}

int
date1(char **sp, char *s_end, Node ***n)
{
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
}

int
date2(char **sp, char *s_end, Node ***n)
{
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
}

int
date3(char **sp, char *s_end, Node ***n)
{
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
}

int
day(char **sp, char *s_end, Node ***n)
{
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
}

int
day_name(char **sp, char *s_end, Node ***n)
{
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
}

int
day_name_l(char **sp, char *s_end, Node ***n)
{
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
}

int
delay_seconds(char **sp, char *s_end, Node ***n)
{
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
}

int
hour(char **sp, char *s_end, Node ***n)
{
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
}

int
media_range(char **sp, char *s_end, Node ***n)
{
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
}

int
media_type(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p1, *p2;

    createnode(*n, "media-type", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p1 = *sp;
    if (type(sp, s_end, &cur)
    || slash_s(sp, s_end, &cur)
    || subtype(sp, s_end, &cur)) {
        *sp = p1;
        freeTree(**n);
        **n = NULL;
        return 1;
    }
    while (1){
        p2 = *sp;
        if (ows(sp, s_end, &cur)
        || semicolon_s(sp, s_end, &cur)
        || ows(sp, s_end, &cur)
        || parameter(sp, s_end, &cur)){
            *sp = p2;
            break;
        }
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
minute(char **sp, char *s_end, Node ***n)
{
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
}

int
month(char **sp, char *s_end, Node ***n)
{
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
}

int
obs_date(char **sp, char *s_end, Node ***n)
{
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
}

int
parameter(char **sp, char *s_end, Node ***n)
{
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
}

int
product(char **sp, char *s_end, Node ***n)
{
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
}

int
product_version(char **sp, char *s_end, Node ***n)
{
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
}

int
qvalue(char **sp, char *s_end, Node ***n)
{
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
}

int
rfc850_date(char **sp, char *s_end, Node ***n)
{
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
}

int
second(char **sp, char *s_end, Node ***n)
{
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
}

int
subtype(char **sp, char *s_end, Node ***n)
{
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
}

int
time_of_day(char **sp, char *s_end, Node ***n)
{
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
}

int
type(char **sp, char *s_end, Node ***n)
{
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
}

int
weight(char **sp, char *s_end, Node ***n)
{
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
}

int
year(char **sp, char *s_end, Node ***n)
{
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
}

int
etag(char **sp, char *s_end, Node ***n)
{
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
}

int
if_match(char **sp, char *s_end, Node ***n)
{
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
}

int
if_modified_since(char **sp, char *s_end, Node ***n)
{
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
}

int
if_none_match(char **sp, char *s_end, Node ***n)
{
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
}

int
if_unmodified_since(char **sp, char *s_end, Node ***n)
{
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
}

int
last_modified(char **sp, char *s_end, Node ***n)
{
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
}

int
entity_tag(char **sp, char *s_end, Node ***n)
{
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
}

int
etagc(char **sp, char *s_end, Node ***n)
{
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
}

int
opaque_tag(char **sp, char *s_end, Node ***n)
{
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
}

int
weak(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_ranges(char **sp, char *s_end, Node ***n)
{
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
}

int
content_range(char **sp, char *s_end, Node ***n)
{
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
}

int
if_range(char **sp, char *s_end, Node ***n)
{
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
}

int
range(char **sp, char *s_end, Node ***n)
{
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
}

int
acceptable_ranges(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_content_range(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_range(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_range_resp(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_range_set(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_range_spec(char **sp, char *s_end, Node ***n)
{
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
}

int
byte_ranges_specifier(char **sp, char *s_end, Node ***n)
{
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
}

int
bytes_unit(char **sp, char *s_end, Node ***n)
{
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
}

int
complete_length(char **sp, char *s_end, Node ***n)
{
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
}

int
first_byte_pos(char **sp, char *s_end, Node ***n)
{
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
}

int
last_byte_pos(char **sp, char *s_end, Node ***n)
{
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
}

int
other_content_range(char **sp, char *s_end, Node ***n)
{
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
}

int
other_range_resp(char **sp, char *s_end, Node ***n)
{
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
}

int
other_range_set(char **sp, char *s_end, Node ***n)
{
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
}

int
other_range_unit(char **sp, char *s_end, Node ***n)
{
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
}

int
other_ranges_specifier(char **sp, char *s_end, Node ***n)
{
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
}

int
range_unit(char **sp, char *s_end, Node ***n)
{
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
}

int
suffix_byte_range_spec(char **sp, char *s_end, Node ***n)
{
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
}

int
suffix_length(char **sp, char *s_end, Node ***n)
{
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
}

int
unsatisfied_range(char **sp, char *s_end, Node ***n)
{
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
}

int
age(char **sp, char *s_end, Node ***n)
{
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
}

int
cache_control(char **sp, char *s_end, Node ***n)
{
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
}

int
expires(char **sp, char *s_end, Node ***n)
{
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
}

int
pragma(char **sp, char *s_end, Node ***n)
{
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
}

int
warning(char **sp, char *s_end, Node ***n)
{
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
}

int
cache_directive(char **sp, char *s_end, Node ***n)
{
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
}

int
delta_seconds(char **sp, char *s_end, Node ***n)
{
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
}

int
extension_pragma(char **sp, char *s_end, Node ***n)
{
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
}

int
pragma_directive(char **sp, char *s_end, Node ***n)
{
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
}

int
warn_agent(char **sp, char *s_end, Node ***n)
{
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
}

int
warn_code(char **sp, char *s_end, Node ***n)
{
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
}

int
warn_date(char **sp, char *s_end, Node ***n)
{
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
}

int
warn_text(char **sp, char *s_end, Node ***n)
{
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
}

int
warning_value(char **sp, char *s_end, Node ***n)
{
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
}

int
proxy_authenticate(char **sp, char *s_end, Node ***n)
{
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
}

int
proxy_authorization(char **sp, char *s_end, Node ***n)
{
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
}

int
www_authenticate(char **sp, char *s_end, Node ***n)
{
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
}

int
auth_param(char **sp, char *s_end, Node ***n)
{
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
}

int
auth_scheme(char **sp, char *s_end, Node ***n)
{
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
}

int
challenge(char **sp, char *s_end, Node ***n)
{
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
}

int
credentials(char **sp, char *s_end, Node ***n)
{
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
}

int
authorization(char **sp, char *s_end, Node ***n)
{
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
}

int
token68(char **sp, char *s_end, Node ***n)
{
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
}

int
connection_header(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "Connection-header", *sp, 0, NULL, NULL);

    p = *sp;
    if (connection_s(sp, s_end, &cur)
    || colon_s(sp, s_end, &cur)
    || ows(sp, s_end, &cur)
    || connection(sp, s_end, &cur)
    || ows(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }
    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
content_length_header(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "Content-Length-header", *sp, 0, NULL, NULL);
    
    cur = &((**n)->child);

    p = *sp;
    if (connection_s(sp, s_end, &cur)
    || colon_s(sp, s_end, &cur)
    || ows(sp, s_end, &cur)
    || connection(sp, s_end, &cur)
    || ows(sp, s_end, &cur)) {
        *sp = p;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
content_type_header(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "Content-Type-header", *sp, 0, NULL, NULL);
    
    cur = &((**n)->child);

    p = *sp;
    if (connection_s(sp, s_end, &cur)
    || colon_s(sp, s_end, &cur)
    || ows(sp, s_end, &cur)
    || content_type(sp, s_end, &cur)
    || ows(sp, s_end, &cur)) {
        *sp = p;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
trailer_header(char **sp, char *s_end, Node ***n)
{
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
}

int
transfer_encoding_header(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "rulename", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p = *sp;
    if (transfer_encoding_s(sp, s_end, &cur)
    || colon_s(sp, s_end, &cur)
    || ows(sp, s_end, &cur)
    || transfer_encoding(sp, s_end, &cur)
    || ows(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
upgrade_header(char **sp, char *s_end, Node ***n)
{
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
}

int
via_header(char **sp, char *s_end, Node ***n)
{
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
}

int
age_header(char **sp, char *s_end, Node ***n)
{
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
}

int
expires_header(char **sp, char *s_end, Node ***n)
{
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
}

int
date_header(char **sp, char *s_end, Node ***n)
{
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
}

int
location_header(char **sp, char *s_end, Node ***n)
{
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
}

int
retry_after_header(char **sp, char *s_end, Node ***n)
{
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
}

int
vary_header(char **sp, char *s_end, Node ***n)
{
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
}

int
warning_header(char **sp, char *s_end, Node ***n)
{
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
}

int
cache_control_header(char **sp, char *s_end, Node ***n)
{
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
}

int
expect_header(char **sp, char *s_end, Node ***n)
{
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
}

int
host_header(char **sp, char *s_end, Node ***n)
{
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
}

int
max_forwards_header(char **sp, char *s_end, Node ***n)
{
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
}

int
pragma_header(char **sp, char *s_end, Node ***n)
{
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
}

int
range_header(char **sp, char *s_end, Node ***n)
{
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
}

int
te_header(char **sp, char *s_end, Node ***n)
{
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
}

int
if_match_header(char **sp, char *s_end, Node ***n)
{
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
}

int
if_none_match_header(char **sp, char *s_end, Node ***n)
{
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
}

int
if_modified_since_header(char **sp, char *s_end, Node ***n)
{
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
}

int
if_unmodified_since_header(char **sp, char *s_end, Node ***n)
{
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
}

int
if_range_header(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_header(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_charset_header(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_encoding_header(char **sp, char *s_end, Node ***n)
{
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
}

int
accept_language_header(char **sp, char *s_end, Node ***n)
{
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
}

int
authorization_header(char **sp, char *s_end, Node ***n)
{
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
}

int
proxy_authorization_header(char **sp, char *s_end, Node ***n)
{
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
}

int
referer_header(char **sp, char *s_end, Node ***n)
{
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
}

int
user_agent_header(char **sp, char *s_end, Node ***n)
{
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
}

int
cookie_pair(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "cookie-pair", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p = *sp;
    if (cookie_name(sp, s_end, &cur)
    || equals_s(sp, s_end, &cur)
    || cookie_value(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
cookie_name(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "cookie-name", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    if (token(sp, s_end, &cur)) {
            freeTree(**n);
            **n = NULL;
            return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
cookie_value(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "cookie-value", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p = *sp;
    if (dquote(sp, s_end, &cur)){
        while (1) {
            if (cookie_octet(sp, s_end, &cur)) {
                break;
            }
        }
    } else {
        while (1) {
            if (cookie_octet(sp, s_end, &cur)) {
                break;
            }
        }
        if (dquote(sp, s_end, &cur)) {
            *sp = p;
            freeTree(**n);
            **n = NULL;
            return 1;
        }
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
cookie_octet(char **sp, char *s_end, Node ***n)
{
    if (s_end - *sp + 1 < 1)
        return 1;
    if (**sp == 0x21
    || **sp >= 0x23 && **sp <= 0x2B
    || **sp >= 0x2D && **sp <= 0x3A
    || **sp >= 0x3C && **sp <= 0x5B
    || **sp >= 0x5D && **sp <= 0x7E) {
        createnode(*n, "cookie-octet", *sp, 1, NULL, NULL);
        *n = &((**n)->sibling);
        (*sp)++;
        return 0;
    }
    return 1;
}

int
cookie_header(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "Cookie-header", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p = *sp;
    if (cookie_s(sp, s_end, &cur)
    || ows(sp, s_end, &cur)
    || cookie_string(sp, s_end, &cur)
    || ows(sp, s_end, &cur)) {
        *sp = p;
        freeTree(**n);
        **n = NULL;
        return 1;
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
cookie_string(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p1, *p2;

    createnode(*n, "cookie-string", *sp, 0, NULL, NULL);
        
    cur = &((**n)->child);

    p1 = *sp;
    if (cookie_pair(sp, s_end, &cur)) {
        *sp = p1;
        freeTree(**n);
        **n = NULL;
        return 1;
    }
    while (1) {
        p2 = *sp;
        if (semicolon_s(sp, s_end, &cur)
        || space(sp, s_end, &cur)
        || cookie_pair(sp, s_end, &cur)) {
            *sp = p2;
            break;
        }
    }

    cur = (**n)->child;
    while (cur) {
        (**n)->len += cur->len;
        cur = cur->sibling;
    }
    *n = &((**n)->sibling);
    return 0;
}

int
header_field(char **sp, char *s_end, Node ***n)
{
    Node *cur;
    char *p;

    createnode(*n, "header-field", *sp, 0, NULL, NULL);
    
    cur = &((**n)->child);

    if (connection_header(sp, s_end, &cur)
    && content_length_header(sp, s_end, &cur)
    && content_type_header(sp, s_end, &cur)
    && cookie_header(sp, s_end, &cur)
    && transfer_encoding_header(sp, s_end, &cur)
    && expect_header(sp, s_end, &cur)
    && host_header(sp, s_end, &cur)) {
        p = *sp;
        if (field_name(sp, s_end, &cur)
        || colon_s(sp, s_end, &cur)
        || ows(sp, s_end, &cur)
        || field_value(sp, s_end, &cur)
        || ows(sp, s_end, &cur)) {
            *sp = p;
            freeTree(**n);
            **n = NULL;
            return 1;
        }
    }
    (**n)->len = (**n)->child->len;
    *n = &((**n)->sibling);
    return 0;
}

int
space(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = " ";

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

int
digit(char **sp, char *s_end, Node ***n)
{
    if (s_end - *sp + 1 < 1 || !isdigit(**sp))
        return 1;
    createnode(*n, "DIGIT", *sp, 1, NULL, NULL);
    *n = &((**n)->sibling);
    (*sp)++;
    return 0;
}

int
alpha(char **sp, char *s_end, Node ***n)
{
    if (s_end - *sp + 1 < 1 || !isalpha(**sp))
        return 1;
    createnode(*n, "ALPHA", *sp, 1, NULL, NULL);
    *n = &((**n)->sibling);
    (*sp)++;
    return 0;
}

int
dquote(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "\"";

    if (s_end - *sp + 1 < strlen(s))
        return 1;
    for (i = 0; i < strlen(s); i++){
        if (tolower(s[i]) != tolower((*sp)[i]))
            return 1;
    }
    createnode(*n, "DQUOTE", *sp, strlen(s), NULL, NULL);
    *n = &((**n)->sibling);
    *sp += strlen(s);
    return 0;
}

int
connection_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "Connection";

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

int
colon_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = ":";

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

int
cookie_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "Cookie:";

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

int
semicolon_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = ";";

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

int
exclamation_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "!";

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
int
hash_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "#";

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

int
dollar_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "$";

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

int
percent_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "%";

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

int
ampersand_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "&";

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

int
quote_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "\'";

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

int
asterisk_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "*";

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

int
plus_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "+";

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

int
minus_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "-";

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

int
period_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = ".";

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

int
caret_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "^";

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

int
underscore_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "_";

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

int
backtick_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "`";

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

int
vbar_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "|";

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

int
tilde_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "~";

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

int
equals_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "=";

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

int
transfer_encoding_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "Transfer-Encoding";

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

int
chunked_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "chunked";

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

int
compress_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "compress";

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

int
deflate_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "deflate";

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

int
gzip_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "gzip";

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
