#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"
#include "apr_strings.h"

/* The sample content handler */
static int simple_filter_handler(request_rec *r)
{
    if (r->args) {
        char* rest;
        char* param = apr_strtok(r->args, "&", &rest);
		for (;param; param = apr_strtok(NULL, "&", &rest)) {
            if (!strcmp(param, "allow=true")) {
                return DECLINED;
            }
        }
    }

    r->status = HTTP_FORBIDDEN;
    return OK;
}
