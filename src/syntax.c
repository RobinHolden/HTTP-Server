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
crlf(char **sp, char *s_end, Node ***n)
{
    ;
}

int
http_message(char **sp, char *s_end, Node ***n)
{
    ;
}

int
http_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
http_version(char **sp, char *s_end, Node ***n)
{
    ;
}

int
field_content(char **sp, char *s_end, Node ***n)
{
    ;
}

int
field_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
field_value(char **sp, char *s_end, Node ***n)
{
    ;
}

int
field_vchar(char **sp, char *s_end, Node ***n)
{
    ;
}

int
last_chunk(char **sp, char *s_end, Node ***n)
{
    ;
}

int
message_body(char **sp, char *s_end, Node ***n)
{
    ;
}

int
method(char **sp, char *s_end, Node ***n)
{
    ;
}

int
obs_fold(char **sp, char *s_end, Node ***n)
{
    ;
}

int
obs_text(char **sp, char *s_end, Node ***n)
{
    ;
}

int
origin_form(char **sp, char *s_end, Node ***n)
{
    ;
}

int
reason_phrase(char **sp, char *s_end, Node ***n)
{
    ;
}

int
request_line(char **sp, char *s_end, Node ***n)
{
    ;
}

int
request_target(char **sp, char *s_end, Node ***n)
{
    ;
}

int
start_line(char **sp, char *s_end, Node ***n)
{
    ;
}

int
status_code(char **sp, char *s_end, Node ***n)
{
    ;
}

int
status_line(char **sp, char *s_end, Node ***n)
{
    ;
}

int
uri(char **sp, char *s_end, Node ***n)
{
    ;
}

int
hier_part(char **sp, char *s_end, Node ***n)
{
    ;
}

int
uri_reference(char **sp, char *s_end, Node ***n)
{
    ;
}

int
absolute_uri(char **sp, char *s_end, Node ***n)
{
    ;
}

int
relative_ref(char **sp, char *s_end, Node ***n)
{
    ;
}

int
relative_part(char **sp, char *s_end, Node ***n)
{
    ;
}

int
scheme(char **sp, char *s_end, Node ***n)
{
    ;
}

int
absolute_form(char **sp, char *s_end, Node ***n)
{
    ;
}

int
absolute_path(char **sp, char *s_end, Node ***n)
{
    ;
}

int
asterisk_form(char **sp, char *s_end, Node ***n)
{
    ;
}

int
authority_form(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk_data(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk_ext(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk_ext_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk_ext_val(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunk_size(char **sp, char *s_end, Node ***n)
{
    ;
}

int
chunked_body(char **sp, char *s_end, Node ***n)
{
    ;
}

int
authority(char **sp, char *s_end, Node ***n)
{
    ;
}

int
userinfo(char **sp, char *s_end, Node ***n)
{
    ;
}

int
host(char **sp, char *s_end, Node ***n)
{
    ;
}

int
port(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ip_literal(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ipvfuture(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ipv6address(char **sp, char *s_end, Node ***n)
{
    ;
}

int
h16(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ls32(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ipv4address(char **sp, char *s_end, Node ***n)
{
    ;
}

int
dec_octet(char **sp, char *s_end, Node ***n)
{
    ;
}

int
reg_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path_abempty(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path_absolute(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path_noscheme(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path_rootless(char **sp, char *s_end, Node ***n)
{
    ;
}

int
path_empty(char **sp, char *s_end, Node ***n)
{
    ;
}

int
segment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
segment_nz(char **sp, char *s_end, Node ***n)
{
    ;
}

int
segment_nz_nc(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pchar(char **sp, char *s_end, Node ***n)
{
    ;
}

int
query(char **sp, char *s_end, Node ***n)
{
    ;
}

int
fragment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pct_encoded(char **sp, char *s_end, Node ***n)
{
    ;
}

int
unreserved(char **sp, char *s_end, Node ***n)
{
    ;
}

int
reserved(char **sp, char *s_end, Node ***n)
{
    ;
}

int
gen_delims(char **sp, char *s_end, Node ***n)
{
    ;
}

int
sub_delims(char **sp, char *s_end, Node ***n)
{
    ;
}

int
language_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
alphanum(char **sp, char *s_end, Node ***n)
{
    ;
}

int
language_tag(char **sp, char *s_end, Node ***n)
{
    ;
}

int
langtag(char **sp, char *s_end, Node ***n)
{
    ;
}

int
language(char **sp, char *s_end, Node ***n)
{
    ;
}

int
extlang(char **sp, char *s_end, Node ***n)
{
    ;
}

int
script(char **sp, char *s_end, Node ***n)
{
    ;
}

int
region(char **sp, char *s_end, Node ***n)
{
    ;
}

int
variant(char **sp, char *s_end, Node ***n)
{
    ;
}

int
extension(char **sp, char *s_end, Node ***n)
{
    ;
}

int
singleton(char **sp, char *s_end, Node ***n)
{
    ;
}

int
privateuse(char **sp, char *s_end, Node ***n)
{
    ;
}

int
grandfathered(char **sp, char *s_end, Node ***n)
{
    ;
}

int
irregular(char **sp, char *s_end, Node ***n)
{
    ;
}

int
regular(char **sp, char *s_end, Node ***n)
{
    ;
}

int
bws(char **sp, char *s_end, Node ***n)
{
    ;
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
        free(**n);
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
    ;
}

int
content_length(char **sp, char *s_end, Node ***n)
{
    ;
}

int
host(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ows(char **sp, char *s_end, Node ***n)
{
    while (s_end - *sp + 1 > 0 && (*sp == ' ' || *sp == '\t')) {
        (*sp)++;
    }
    return 0;
}

int
rws(char **sp, char *s_end, Node ***n)
{
    ;
}

int
te(char **sp, char *s_end, Node ***n)
{
    ;
}

int
trailer(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_encoding(char **sp, char *s_end, Node ***n)
{
    ;
}

int
upgrade(char **sp, char *s_end, Node ***n)
{
    ;
}

int
via(char **sp, char *s_end, Node ***n)
{
    ;
}

int
comment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
comment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
connection_option(char **sp, char *s_end, Node ***n)
{
    ;
}

int
ctext(char **sp, char *s_end, Node ***n)
{
    ;
}

int
http_uri(char **sp, char *s_end, Node ***n)
{
    ;
}

int
fragment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
https_uri(char **sp, char *s_end, Node ***n)
{
    ;
}

int
fragment(char **sp, char *s_end, Node ***n)
{
    ;
}

int
partial_uri(char **sp, char *s_end, Node ***n)
{
    ;
}

int
protocol(char **sp, char *s_end, Node ***n)
{
    ;
}

int
protocol_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
protocol_version(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pseudonym(char **sp, char *s_end, Node ***n)
{
    ;
}

int
qdtext(char **sp, char *s_end, Node ***n)
{
    ;
}

int
quoted_pair(char **sp, char *s_end, Node ***n)
{
    ;
}

int
quoted_string(char **sp, char *s_end, Node ***n)
{
    ;
}

int
rank(char **sp, char *s_end, Node ***n)
{
    ;
}

int
received_by(char **sp, char *s_end, Node ***n)
{
    ;
}

int
received_protocol(char **sp, char *s_end, Node ***n)
{
    ;
}

int
t_codings(char **sp, char *s_end, Node ***n)
{
    ;
}

int
t_ranking(char **sp, char *s_end, Node ***n)
{
    ;
}

int
tchar(char **sp, char *s_end, Node ***n)
{
    ;
}

int
token(char **sp, char *s_end, Node ***n)
{
    ;
}

int
trailer_part(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_coding(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_extension(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_extension(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_parameter(char **sp, char *s_end, Node ***n)
{
    ;
}

int
uri_host(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_charset(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_encoding(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_language(char **sp, char *s_end, Node ***n)
{
    ;
}

int
allow(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_encoding(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_language(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_location(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_type(char **sp, char *s_end, Node ***n)
{
    ;
}

int
date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
expect(char **sp, char *s_end, Node ***n)
{
    ;
}

int
gmt(char **sp, char *s_end, Node ***n)
{
    ;
}

int
http_date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
imf_fixdate(char **sp, char *s_end, Node ***n)
{
    ;
}

int
location(char **sp, char *s_end, Node ***n)
{
    ;
}

int
max_forwards(char **sp, char *s_end, Node ***n)
{
    ;
}

int
referer(char **sp, char *s_end, Node ***n)
{
    ;
}

int
retry_after(char **sp, char *s_end, Node ***n)
{
    ;
}

int
server(char **sp, char *s_end, Node ***n)
{
    ;
}

int
user_agent(char **sp, char *s_end, Node ***n)
{
    ;
}

int
vary(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_ext(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_params(char **sp, char *s_end, Node ***n)
{
    ;
}

int
asctime_date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
charset(char **sp, char *s_end, Node ***n)
{
    ;
}

int
codings(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_coding(char **sp, char *s_end, Node ***n)
{
    ;
}

int
date1(char **sp, char *s_end, Node ***n)
{
    ;
}

int
date2(char **sp, char *s_end, Node ***n)
{
    ;
}

int
date3(char **sp, char *s_end, Node ***n)
{
    ;
}

int
day(char **sp, char *s_end, Node ***n)
{
    ;
}

int
day_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
day_name_l(char **sp, char *s_end, Node ***n)
{
    ;
}

int
delay_seconds(char **sp, char *s_end, Node ***n)
{
    ;
}

int
hour(char **sp, char *s_end, Node ***n)
{
    ;
}

int
media_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
media_type(char **sp, char *s_end, Node ***n)
{
    ;
}

int
minute(char **sp, char *s_end, Node ***n)
{
    ;
}

int
month(char **sp, char *s_end, Node ***n)
{
    ;
}

int
obs_date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
parameter(char **sp, char *s_end, Node ***n)
{
    ;
}

int
product(char **sp, char *s_end, Node ***n)
{
    ;
}

int
product_version(char **sp, char *s_end, Node ***n)
{
    ;
}

int
qvalue(char **sp, char *s_end, Node ***n)
{
    ;
}

int
rfc850_date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
second(char **sp, char *s_end, Node ***n)
{
    ;
}

int
subtype(char **sp, char *s_end, Node ***n)
{
    ;
}

int
time_of_day(char **sp, char *s_end, Node ***n)
{
    ;
}

int
type(char **sp, char *s_end, Node ***n)
{
    ;
}

int
weight(char **sp, char *s_end, Node ***n)
{
    ;
}

int
year(char **sp, char *s_end, Node ***n)
{
    ;
}

int
etag(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_match(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_modified_since(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_none_match(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_unmodified_since(char **sp, char *s_end, Node ***n)
{
    ;
}

int
last_modified(char **sp, char *s_end, Node ***n)
{
    ;
}

int
entity_tag(char **sp, char *s_end, Node ***n)
{
    ;
}

int
etagc(char **sp, char *s_end, Node ***n)
{
    ;
}

int
opaque_tag(char **sp, char *s_end, Node ***n)
{
    ;
}

int
weak(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_ranges(char **sp, char *s_end, Node ***n)
{
    ;
}

int
content_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
acceptable_ranges(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_content_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_range_resp(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_range_set(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_range_spec(char **sp, char *s_end, Node ***n)
{
    ;
}

int
byte_ranges_specifier(char **sp, char *s_end, Node ***n)
{
    ;
}

int
bytes_unit(char **sp, char *s_end, Node ***n)
{
    ;
}

int
complete_length(char **sp, char *s_end, Node ***n)
{
    ;
}

int
first_byte_pos(char **sp, char *s_end, Node ***n)
{
    ;
}

int
last_byte_pos(char **sp, char *s_end, Node ***n)
{
    ;
}

int
other_content_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
other_range_resp(char **sp, char *s_end, Node ***n)
{
    ;
}

int
other_range_set(char **sp, char *s_end, Node ***n)
{
    ;
}

int
other_range_unit(char **sp, char *s_end, Node ***n)
{
    ;
}

int
other_ranges_specifier(char **sp, char *s_end, Node ***n)
{
    ;
}

int
range_unit(char **sp, char *s_end, Node ***n)
{
    ;
}

int
suffix_byte_range_spec(char **sp, char *s_end, Node ***n)
{
    ;
}

int
suffix_length(char **sp, char *s_end, Node ***n)
{
    ;
}

int
unsatisfied_range(char **sp, char *s_end, Node ***n)
{
    ;
}

int
age(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cache_control(char **sp, char *s_end, Node ***n)
{
    ;
}

int
expires(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pragma(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warning(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cache_directive(char **sp, char *s_end, Node ***n)
{
    ;
}

int
delta_seconds(char **sp, char *s_end, Node ***n)
{
    ;
}

int
extension_pragma(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pragma_directive(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warn_agent(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warn_code(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warn_date(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warn_text(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warning_value(char **sp, char *s_end, Node ***n)
{
    ;
}

int
proxy_authenticate(char **sp, char *s_end, Node ***n)
{
    ;
}

int
proxy_authorization(char **sp, char *s_end, Node ***n)
{
    ;
}

int
www_authenticate(char **sp, char *s_end, Node ***n)
{
    ;
}

int
auth_param(char **sp, char *s_end, Node ***n)
{
    ;
}

int
auth_scheme(char **sp, char *s_end, Node ***n)
{
    ;
}

int
challenge(char **sp, char *s_end, Node ***n)
{
    ;
}

int
credentials(char **sp, char *s_end, Node ***n)
{
    ;
}

int
authorization(char **sp, char *s_end, Node ***n)
{
    ;
}

int
token68(char **sp, char *s_end, Node ***n)
{
    ;
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
        free(**n);
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

    createnode(*n, "header-field", *sp, 0, NULL, NULL);
    
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
    ;
}

int
trailer_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
transfer_encoding_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
upgrade_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
via_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
age_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
expires_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
date_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
location_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
retry_after_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
vary_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
warning_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cache_control_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
expect_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
host_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
max_forwards_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
pragma_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
range_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
te_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_match_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_none_match_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_modified_since_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_unmodified_since_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
if_range_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_charset_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_encoding_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
accept_language_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
authorization_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
proxy_authorization_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
referer_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
user_agent_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_pair(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_name(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_value(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_octet(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_header(char **sp, char *s_end, Node ***n)
{
    ;
}

int
cookie_string(char **sp, char *s_end, Node ***n)
{
    ;
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
            free(**n);
            **n = NULL;
            return 1;
        }
    }
    (**n)->len = (**n)->child->len;
    *n = &((**n)->sibling);
    return 0;
}

int
connection_s(char **sp, char *s_end, Node ***n)
{
    int i;
    const char *s;

    s = "connection";

    if (s_end - *sp + 1 < strlen(s))
        return 1;
    for (i = 0; i < strlen(s); i++){
        if (s[i] != tolower((*sp)[i]))
            return 1;
    }
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
        if (s[i] != tolower((*sp)[i]))
            return 1;
    }
    *sp += strlen(s);
    return 0;
}