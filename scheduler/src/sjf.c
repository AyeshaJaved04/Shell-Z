#include "cpu_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void sjf(Process *p, float *avg_tat, float *avg_wt,int PROCESS_NUM)
{
    int completed = 0, time = 0, total_tat = 0, total_wt = 0;
    while (completed < PROCESS_NUM)
    {
        int idx = -1;
        int min_bt = 1e9;

        for (int i = 0; i < PROCESS_NUM; i++)
        {
            if (!p[i].complete && p[i].arrivalTime <= time && p[i].burstTime < min_bt)
            {
                min_bt = p[i].burstTime;
                idx = i;
            }
        }

        if (idx != -1)
        {
            p[idx].completionTime = time + p[idx].burstTime;
            p[idx].TAT = p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitTime = p[idx].TAT - p[idx].burstTime;
            p[idx].complete = true;

            total_tat += p[idx].TAT;
            total_wt += p[idx].waitTime;
            time = p[idx].completionTime;
            completed++;
        }
        else
        {
            time++;
        }
    }

    *avg_tat = (float)total_tat / PROCESS_NUM;
    *avg_wt = (float)total_wt / PROCESS_NUM;
}