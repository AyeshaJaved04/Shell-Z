// cpu_algorithms.h
#ifndef CPU_ALGORITHMS
#define CPU_ALGORITHMS
// #define PROCESS_NUM 100
#include <stdbool.h>

typedef struct
{
    int pid;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int completionTime;
    int TAT;
    int rem_time;
    bool complete;
} Process;

// Function prototypes
void generateData(Process *array,int num);
void printData(Process *array,int num);
void fcfs(Process *array, float *avg_tat, float *avg_wt,int num);
void roundRobin(Process *arr, int quantum, float *avg_tat, float *avg_wt, int num);
void sjf(Process *arr, float *avg_tat, float *avg_wt, int num);
int compare_by_arrival(const void *a, const void *b);
void enqueue(int *queue, int *rear, int pid);
int dequeue(int *queue, int *front);
int isInQueue(int *queue, int front, int rear, int pid);
void logProcesses(Process *array, int num, const char *algorithm_name);

#endif