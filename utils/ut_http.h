/*
 * Description: 
 *     History: yang@haipo.me, 2017/04/21, create
 */

# ifndef _UT_HTTP_
# define _UT_HTTP_

# include "ut_dict.h"
# include "ut_sds.h"

# include <http_parser.h>

typedef struct http_request_t {
    uint16_t    version_major;
    uint16_t    version_minor;
    uint32_t    method;
    dict_t      *headers;
    sds         url;
    sds         body;
} http_request_t;

typedef struct http_response_t {
    uint32_t    status;
    dict_t      *headers;
    sds         content;
} http_response_t;

http_request_t *http_request_new(void);
int http_request_set_header(http_request_t *request, char *field, char *value);
void http_request_release(http_request_t *request);

http_response_t *http_response_new(void);
int http_response_set_header(http_response_t *response, char *field, char *value);
sds http_response_encode(http_response_t *response);
void http_response_release(http_response_t *response);

# endif

