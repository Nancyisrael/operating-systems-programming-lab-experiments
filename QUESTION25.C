#include<stdio.h>

struct Process {
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(struct Process processes[], int n) {
    int i, j;
    struct Process temp;

    // Sort the processes based on priority using bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].priority > processes[j+1].priority) {
                // Swap the processes
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    processes[0].waitingTime = 0;
    for (i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }

    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

int main() {
    int n = 3; // Number of processes

    struct Process processes[n];
    processes[0].burstTime = 30;
    processes[0].priority = 2;
    processes[1].burstTime = 5;
    processes[1].priority = 1;
    processes[2].burstTime = 12;
    processes[2].priority = 3;

    calculateTimes(processes, n);

    float avgWaitingTime = 0, avgTurnaroundTime = 0;

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].burstTime, processes[i].priority,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}

