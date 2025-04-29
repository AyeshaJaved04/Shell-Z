#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H

#include <netinet/in.h>

void handle_http_request(int client_sock, const char *request, struct sockaddr_in client_addr);

#endif
