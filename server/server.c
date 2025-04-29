#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#include "../include/http_handler.h"
#include "../include/utilities.h"

#define PORT 8080
#define BUFFER_SIZE 4096
#define MAX_CONNECTIONS 10

void show_loading_spinner(const char *message, int duration_ms)
{
    const char spinner[] = "|/-\\";
    int spinner_index = 0;
    int steps = duration_ms / 60; // 100ms per frame

    printf("\n  %s ", message);
    fflush(stdout);

    for (int i = 0; i < steps; ++i)
    {
        printf("\b%c", spinner[spinner_index]);
        fflush(stdout);
        spinner_index = (spinner_index + 1) % 4;
        usleep(90000); // 100ms
    }

    printf("\b✅\n"); // Success checkmark
}

void server_running(long ms)
{
    printf("\n  \033[1;32mNEXIS \033[0;32mv1.0.0  \033[0;30mready in \033[1;37m%ld \033[0;37mms\n\n", ms);
    RESET();
    printf("  \033[1;32m➜  \033[1;37mLocal:   \033[0;36mhttp://localhost:%d/\n", PORT);
    // RESET();
    printf("  \033[0;32m➜  \033[1;30mNetwork: \033[0;30muse \033[1;37m--host \033[0;30mto expose\n");
    printf("  \033[0;32m➜  \033[0;30mLogs:    \033[1;37mlogs/server.log\n\n");
}

void *handle_client(void *arg)
{
    int client_sock = *(int *)arg;
    free(arg);

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    getpeername(client_sock, (struct sockaddr *)&client_addr, &client_len);

    char buffer[BUFFER_SIZE];
    int bytes_read = read(client_sock, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0)
    {
        perror("Read error");
        close(client_sock);
        return NULL;
    }
    buffer[bytes_read] = '\0';

    handle_http_request(client_sock, buffer, client_addr);
    close(client_sock);
    return NULL;
}

int main()
{
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    int server_sock, *client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, MAX_CONNECTIONS) < 0)
    {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    /* ---------------- Server Running ---------------- */
    usleep(300000); // Sleep 300ms (0.3s)
    gettimeofday(&end_time, NULL);
    long seconds = end_time.tv_sec - start_time.tv_sec;
    long useconds = end_time.tv_usec - start_time.tv_usec;
    long total_ms = (seconds * 1000) + (useconds / 1000);
    show_loading_spinner("Starting Nexis server ", 1200);
    server_running(total_ms);
    /* ------------------------------------------------- */
    while (1)
    {
        client_sock = malloc(sizeof(int));
        *client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (*client_sock < 0)
        {
            perror("Accept failed");
            free(client_sock);
            continue;
        }

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)client_sock) != 0)
        {
            perror("Thread creation failed");
            free(client_sock);
        }
        pthread_detach(thread);
    }

    close(server_sock);
    return 0;
}
