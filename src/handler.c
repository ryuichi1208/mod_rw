#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"


/* The sample content handler */
static int hoge_handler(request_rec *r)
{
    if (strcmp(r->handler, "hoge")) {
        return DECLINED;
    }
    r->content_type = "text/html";

    if (!r->header_only)
        ap_rputs("The sample page from mod_hoge.c\n", r);
    return OK;
}

static void hoge_register_hooks(apr_pool_t *p)
{
    ap_hook_handler(hoge_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA hoge_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    NULL,                  /* table of config file commands       */
    hoge_register_hooks  /* register hooks                      */
};
