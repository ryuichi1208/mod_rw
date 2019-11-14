static int orz_handler(request_rec *r)
{
    if (strcmp(r->handler, "orz")) {
        return DECLINED;
    }
    r->content_type = "text/html";

    if (!r->header_only) {
        int i = 0;
        for (i = 0; i <= 100; i++) {
            ap_rputs("orz ", r);
        }
    }
    return OK;
}
