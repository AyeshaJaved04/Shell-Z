#include "cpu_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void fcfs(Process *p, float *avg_tat, float *avg_wt,int PROCESS_NUM)
{
    int current_time = 0;
    int total_tat = 0, total_wt = 0;

    for (int i = 0; i < PROCESS_NUM; i++)
    {
        if (current_time < p[i].arrivalTime)
            current_time = p[i].arrivalTime;

        p[i].completionTime = current_time + p[i].burstTime; //time at which process stops using cpu
        p[i].TAT = p[i].completionTime - p[i].arrivalTime; //tat time taken to complete the work
        p[i].waitTime = p[i].TAT - p[i].burstTime; //time a process had to wait bfr it gets cpu 

        total_tat += p[i].TAT;
        total_wt += p[i].waitTime;

        current_time = p[i].completionTime;
    }

    *avg_tat = (float)total_tat / PROCESS_NUM;
    *avg_wt = (float)total_wt / PROCESS_NUM;
}
