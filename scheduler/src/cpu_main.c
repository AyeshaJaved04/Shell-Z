// cpu_main.c
#include "cpu_algorithms.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>  // For mkdir()

int main()
{
    float avg_fcfs_tat = 0, avg_fcfs_wt = 0;
    float avg_rr_tat = 0, avg_rr_wt = 0;
    float avg_sjf_tat = 0, avg_sjf_wt = 0;
    int choice;
    int PROCESS_NUM;

    printf("Enter Number of Processes: ");
    scanf("%d", &PROCESS_NUM);
    Process original[PROCESS_NUM], temp[PROCESS_NUM];
    generateData(original, PROCESS_NUM);

    // Create logs directory if it doesn't exist for scheduling.txt file
    mkdir("logs", 0777);

    // append to the previous log file when starting new session
    FILE *log_file = fopen("logs/scheduling_logs.txt", "a");
    if (log_file != NULL)
    {
        fprintf(log_file, "=== CPU Scheduling Log ===\n");
        fprintf(log_file, "Started at: %s", ctime(&(time_t){time(NULL)})); //current time will be printed in logs file
        fclose(log_file);
    }

    do
    {
        printf("\nCPU Scheduling Menu\n");
        printf("1. Run FCFS Scheduling\n");
        printf("2. Run Round Robin Scheduling\n");
        printf("3. Run SJF Scheduling\n");
        printf("4. Complexity Analysis\n");
        printf("5. View Logs\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice > 6 || choice < 1)
        {
            printf("Invalid Input. Enter a Number Between 1 - 6.\n");
            continue;
        }

        system("clear");
        
        switch (choice)
        {
        case 1:
            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            fcfs(temp, &avg_fcfs_tat, &avg_fcfs_wt, PROCESS_NUM);
            printData(temp, PROCESS_NUM);
            logProcesses(temp, PROCESS_NUM, "FCFS");
            printf("\nFCFS Average Turn Around Time: %.2f\n", avg_fcfs_tat);
            printf("FCFS Average Waiting Time: %.2f\n", avg_fcfs_wt);
            break;

        case 2:
            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            roundRobin(temp, 10, &avg_rr_tat, &avg_rr_wt, PROCESS_NUM);
            printData(temp, PROCESS_NUM);
            logProcesses(temp, PROCESS_NUM, "Round Robin");
            printf("\nRound Robin Average Turn Around Time: %.2f\n", avg_rr_tat);
            printf("Round Robin Average Waiting Time: %.2f\n", avg_rr_wt);
            break;

        case 3:
            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            sjf(temp, &avg_sjf_tat, &avg_sjf_wt, PROCESS_NUM);
            printData(temp, PROCESS_NUM);
            logProcesses(temp, PROCESS_NUM, "SJF");
            printf("\nSJF Average Turn Around Time: %.2f\n", avg_sjf_tat);
            printf("SJF Average Waiting Time: %.2f\n", avg_sjf_wt);
            break;

        case 4:
            printf("\n--- Complexity Analysis ---\n");
            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            sjf(temp, &avg_sjf_tat, &avg_sjf_wt, PROCESS_NUM);
            //logProcesses(temp, PROCESS_NUM, "SJF (Analysis)");
            printf("SJF -> TAT: %.2f, WT: %.2f\n", avg_sjf_tat, avg_sjf_wt);

            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            fcfs(temp, &avg_fcfs_tat, &avg_fcfs_wt, PROCESS_NUM);
           // logProcesses(temp, PROCESS_NUM, "FCFS (Analysis)");
            printf("FCFS -> TAT: %.2f, WT: %.2f\n", avg_fcfs_tat, avg_fcfs_wt);

            memcpy(temp, original, sizeof(original));
            qsort(temp, PROCESS_NUM, sizeof(Process), compare_by_arrival);
            roundRobin(temp, 10, &avg_rr_tat, &avg_rr_wt, PROCESS_NUM);
            //logProcesses(temp, PROCESS_NUM, "Round Robin (Analysis)");
            printf("Round Robin -> TAT: %.2f, WT: %.2f\n", avg_rr_tat, avg_rr_wt);

            float min_avg = avg_fcfs_tat + avg_fcfs_wt;
            char best_algo[20] = "FCFS";

            if ((avg_rr_tat + avg_rr_wt) < min_avg) {
                min_avg = avg_rr_tat + avg_rr_wt;
                strcpy(best_algo, "Round Robin");
            }
            if ((avg_sjf_tat + avg_sjf_wt) < min_avg) {
                min_avg = avg_sjf_tat + avg_sjf_wt;
                strcpy(best_algo, "SJF");
            }

            printf("\nThe most efficient algorithm is: %s\n", best_algo);

            FILE *cmp_log = fopen("logs/scheduling_logs.txt", "a");
            if (cmp_log != NULL) {
                fprintf(cmp_log, "\n=== Algorithm Comparison ===\n");
                fprintf(cmp_log, "SJF: TAT=%.2f, WT=%.2f\n", avg_sjf_tat, avg_sjf_wt);
                fprintf(cmp_log, "FCFS: TAT=%.2f, WT=%.2f\n", avg_fcfs_tat, avg_fcfs_wt);
                fprintf(cmp_log, "Round Robin: TAT=%.2f, WT=%.2f\n", avg_rr_tat, avg_rr_wt);
                fprintf(cmp_log, "Most efficient algorithm: %s\n", best_algo);
                fclose(cmp_log);
            }
            break;

        case 5:  // New case for viewing logs
            printf("\n--- Log File Contents ---\n");
            system("cat logs/scheduling_logs.txt");  // System call to display logs
            printf("\n-------------------------\n");
            break;

        case 6:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}