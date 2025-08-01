#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include "../include/http_handler.h"
#include "../include/logger.h"

#define BUFFER_SIZE 4096

const char *get_mime_type(const char *path)
{
    if (strstr(path, ".html"))
        return "text/html";
    if (strstr(path, ".css"))
        return "text/css";
    if (strstr(path, ".js"))
        return "application/javascript";
    if (strstr(path, ".png"))
        return "image/png";
    if (strstr(path, ".jpg") || strstr(path, ".jpeg"))
        return "image/jpeg";
    if (strstr(path, ".gif"))
        return "image/gif";
    if (strstr(path, ".ico"))
        return "image/x-icon";
    return "text/plain";
}

void handle_http_request(int client_sock, const char *request, struct sockaddr_in client_addr)
{
    char method[16], path[256], protocol[16];
    sscanf(request, "%15s %255s %15s", method, path, protocol);

    if (strcmp(path, "/") == 0)
    {
        strcpy(path, "/index.html");
    }

    char file_path[512];
    snprintf(file_path, sizeof(file_path), "static%s", path);

    /*
     * =====================================================================
     * --- NEW SERVER LOGIC TO HANDLE DIRECTORY REQUESTS ---
     * =====================================================================
     */

    // Check if the constructed path points to a directory
    struct stat path_stat;
    if (stat(file_path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
    {
        // If the path is a directory, append "/index.html" to serve the default page.
        // using "strncat" to prevent buffer overflows.
        strncat(file_path, "/index.html", sizeof(file_path) - strlen(file_path) - 1);
    }

    // Now, the rest of the function proceeds with the potentially updated file_path

    int file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1)
    {
        const char *not_found_response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>";
        write(client_sock, not_found_response, strlen(not_found_response));
        log_request(inet_ntoa(client_addr.sin_addr), method, path, 404);
        return;
    }

    struct stat file_stat;
    fstat(file_fd, &file_stat);

    char header[BUFFER_SIZE];
    sprintf(header, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %lld\r\n\r\n",
            get_mime_type(file_path), (long long)file_stat.st_size);
    write(client_sock, header, strlen(header));

    char file_buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(file_fd, file_buffer, sizeof(file_buffer))) > 0)
    {
        write(client_sock, file_buffer, bytes_read);
    }

    close(file_fd);
    log_request(inet_ntoa(client_addr.sin_addr), method, path, 200);
}