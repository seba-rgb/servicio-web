#include <microhttpd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../fibonacci/fibonacci.h"

#define MENSAJE "<html><body>" \
                       "<h1>Fibonacci</h1>" \
                       "El %d n&uacute;mero es %d." \
                       "</body></html>"

int responder(void *cls, struct MHD_Connection *connection,
              const char *url,
              const char *method, const char *version,
              const char *upload_data,
              size_t *upload_data_size, void **con_cls)
{
    static int numero = 0;
    int f = fibonacci(++numero);
    int tamanio = sizeof (MENSAJE)+log(f)/log(10)+log(numero)/log(10);
    char *page = malloc(tamanio);
    int ret;
    struct MHD_Response *response;
    sprintf(page, MENSAJE, numero, f);
    response = MHD_create_response_from_buffer(strlen(page),
                                               (void *)page, MHD_RESPMEM_MUST_FREE);
    MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_TYPE, "text/html");
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);
    return ret;
}

int main(int argc, char **argv)
{
    struct MHD_Daemon *daemon;
    daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD,
                              8080,
                              NULL,
                              NULL,
                              &responder,
                              NULL,
                              MHD_OPTION_END);
    getchar();
    MHD_stop_daemon(daemon);

    return 0;
}
