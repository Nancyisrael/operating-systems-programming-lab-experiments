#include <stdio.h>

struct Process {
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void calculateTimes(struct Process processes[], int n) {
    int i, j;
    struct Process temp;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Sort processes in ascending order based on burst time using bubble sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time for each process
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    // Calculate total waiting time and total turnaround time
    for (i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    // Define the processes with their burst times
    struct Process processes[] = {
        {6, 0, 0},
        {8, 0, 0},
        {7, 0, 0},
        {3, 0, 0}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    // Call the function to calculate waiting time and turnaround time
    calculateTimes(processes, n);

    return 0;
}

