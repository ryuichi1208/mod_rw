static void* create_modulename_server_config(apr_pool_t* p, server_rec* s)
{
    modulename_server_config* conf = apr_palloc(p, sizeof(modulename_sever__config));
    conf->hoge = apr_pstrdup(p, "hogehoge"); // デフォルト値を入れておくとか
    return conf;
}
