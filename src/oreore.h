module AP_MODULE_DECLARE_DATA modulename_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                            /* create per-dir    config structures */
    NULL,                            /* merge  per-dir    config structures */
    create_modulename_server_config, /* create per-server config structures */
    NULL,                            /* merge  per-server config structures */
    modulename_cmd,                  /* table of config file commands       */
    modulename_register_hooks        /* register hooks                      */
};
