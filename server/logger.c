#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include "../include/logger.h"

#define LOG_FILE "logs/server.log"
#define TIME_THRESHOLD 2

pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

void log_request(const char *client_ip, const char *method, const char *path, int status_code)
{
    // Store the last request time
    static time_t last_request_time = 0;
    time_t now = time(NULL);

    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file)
        return;

    pthread_mutex_lock(&log_mutex);

    // Insert a separator if time difference is greater than the threshold
    if (last_request_time > 0 && (now - last_request_time) > TIME_THRESHOLD) {
        fprintf(log_file, "\n");
    }

    // Update last request time
    last_request_time = now;

    // Get formatted time
    struct tm *tm_info = localtime(&now);
    char time_buf[26];
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);

    // write logs to file
    fprintf(log_file, "[%s] Client IP: %s | Method: %s | Requested: %s | Status: %d\n", 
            time_buf, client_ip, method, path, status_code);
    
    pthread_mutex_unlock(&log_mutex);
    fclose(log_file);
}
