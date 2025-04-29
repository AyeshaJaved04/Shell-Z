#include "cpu_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>  // For mkdir()
#define SIZE 10000
#define MAX_QUEUE 100

void generateData(Process *process_arr, int PROCESS_NUM)
{
    srand(time(0));

    for (int i = 0; i < PROCESS_NUM; i++)
    {
        process_arr[i].pid = i + 1;
        process_arr[i].arrivalTime = (rand() % 50) + 1;
        process_arr[i].burstTime = (rand() % 10) + 1;
        process_arr[i].rem_time = process_arr[i].burstTime;
        process_arr[i].complete = false;
    }
}

void printData(Process *p_arr, int PROCESS_NUM)
{
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWait Time\tTAT\n");

    for (int i = 0; i < PROCESS_NUM; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p_arr[i].pid,
               p_arr[i].arrivalTime,
               p_arr[i].burstTime,
               p_arr[i].completionTime,
               p_arr[i].waitTime,
               p_arr[i].TAT);
    }
}

int compare_by_arrival(const void *a, const void *b)
{
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;

    if (p1->arrivalTime != p2->arrivalTime)
        return p1->arrivalTime - p2->arrivalTime;
    else
        return p1->pid - p2->pid;
}


void logProcesses(Process *array, int num, const char *algorithm_name) {
    // Create logs directory if it doesn't exist
    mkdir("logs", 0777);  // 0777 gives read, write, execute permissions to owner, group and others
    
    char log_path[256];
    snprintf(log_path, sizeof(log_path), "logs/scheduling_logs.txt");
    
    FILE *log_file = fopen(log_path, "a"); // Open in append mode
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    // Write header with algorithm name and timestamp
    time_t now;
    time(&now);
    fprintf(log_file, "\n\n=== Scheduling Algorithm: %s ===\n", algorithm_name);
    fprintf(log_file, "Log Time: %s", ctime(&now));
    fprintf(log_file, "PID\tArrival\tBurst\tCompletion\tWait\tTAT\n");

    // Write process details
    for (int i = 0; i < num; i++) {
        fprintf(log_file, "%d\t%d\t%d\t%d\t\t%d\t%d\n",
                array[i].pid,
                array[i].arrivalTime,
                array[i].burstTime,
                array[i].completionTime,
                array[i].waitTime,
                array[i].TAT);
    }

    // Calculate and write averages
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < num; i++) {
        avg_tat += array[i].TAT;
        avg_wt += array[i].waitTime;
    }
    avg_tat /= num;
    avg_wt /= num;

    fprintf(log_file, "\nAverages:\n");
    fprintf(log_file, "Turn Around Time: %.2f\n", avg_tat);
    fprintf(log_file, "Waiting Time: %.2f\n", avg_wt);

    fclose(log_file);
}