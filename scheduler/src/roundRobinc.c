#include "cpu_algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SIZE 10000
#define MAX_QUEUE 10000


void enqueue(int *queue, int *rear, int pid) {
    queue[*rear] = pid; //add pid to the end of queue
    (*rear)++; //inc rear ptr
}

int dequeue(int *queue, int *front) {
    int pid = queue[*front]; //pid pop top element
    (*front)++;  //move front forward
    return pid;
}

//checks if a process is in queue
int isInQueue(int *queue, int front, int rear, int pid) {
    for (int i = front; i < rear; i++) {
        if (queue[i] == pid) 
            return 1;
    }
    return 0;
}

void roundRobin(Process *p, int quantum, float *avg_tat, float *avg_wt,int PROCESS_NUM) {
    int time = 0;
    int completed = 0;
    int queue[MAX_QUEUE], front = 0, rear = 0;
    int visited[SIZE] = {0}; //visited array

    enqueue(queue, &rear, 0); // add first process (assumes sorted by arrival time)
    visited[0] = 1;
    
    //this loop will run until all processes are completed
    while (completed < PROCESS_NUM) {
        if (front == rear) {
            // If queue is empty, advance time to next arriving process and push it into queue
            for (int i = 0; i < PROCESS_NUM; i++) {
                if (!p[i].complete) {
                    time = p[i].arrivalTime;
                    enqueue(queue, &rear, i);
                    visited[i] = 1;
                    break;
                }
            }
        }

        int index = dequeue(queue, &front);
        
        if (p[index].rem_time > 0) {
            //comparison wrt to time quantum
            //if a process has remaining burst time greater than time quantum then it cannot be completed
            //it must be placed at the wait queue again
            int exec_time = (p[index].rem_time > quantum) ? quantum : p[index].rem_time;
            time += exec_time;
            p[index].rem_time -= exec_time;

            // check for any newly arrived process, Add newly arrived processes during execution to queue
            for (int i = 0; i < PROCESS_NUM; i++) {
                if (!visited[i] && p[i].arrivalTime <= time) {
                    enqueue(queue, &rear, i);
                    visited[i] = 1;
                }
            }

            if (p[index].rem_time == 0) {
                p[index].complete = true;
                p[index].completionTime = time;
                p[index].TAT = p[index].completionTime - p[index].arrivalTime;
                p[index].waitTime = p[index].TAT - p[index].burstTime;
                completed++;
            } else {
                enqueue(queue, &rear, index); // Put it back in the queue
            }
        }
    }

    int total_tat = 0, total_wt = 0;
    for (int i = 0; i < PROCESS_NUM; i++) {
        total_tat += p[i].TAT;
        total_wt += p[i].waitTime;
    }

    *avg_tat = (float)total_tat / PROCESS_NUM;
    *avg_wt = (float)total_wt / PROCESS_NUM;
}
