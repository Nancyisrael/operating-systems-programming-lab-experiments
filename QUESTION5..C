#include<stdio.h>

struct Process {
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void SRPT(struct Process processes[], int n) {
    int currentTime = 0;
    int completed = 0;
    int shortest = -1;
    int i, j;

    while (completed != n) {
        shortest = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (shortest == -1 || processes[i].remainingTime < processes[shortest].remainingTime) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            currentTime++;
        } else {
            processes[shortest].remainingTime--;

            if (processes[shortest].remainingTime == 0) {
                completed++;
                processes[shortest].completionTime = currentTime + 1;
                processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
                processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
            }

            currentTime++;
        }
    }
}

int main() {
    int n = 4; // Number of processes
    struct Process processes[n];

    // Input the arrival time and burst time for each process
    processes[0].arrivalTime = 0;
    processes[0].burstTime = 5;
    processes[1].arrivalTime = 1;
    processes[1].burstTime = 3;
    processes[2].arrivalTime = 2;
    processes[2].burstTime = 3;
    processes[3].arrivalTime = 4;
    processes[3].burstTime = 1;

    // Initialize remainingTime, completionTime, waitingTime, and turnaroundTime
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].completionTime = 0;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    SRPT(processes, n);

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processes[i].arrivalTime, processes[i].burstTime, 
            processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);

    return 0;
}

