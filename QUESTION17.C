#include <stdio.h>

#define MAX_PROCESSES 3

struct Process {
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTime(struct Process processes[], int n, int quantum_time) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_burst_time[i] = processes[i].burst_time;

    int time = 0;
    while (1) {
        int all_done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                all_done = 0;
                if (remaining_burst_time[i] > quantum_time) {
                    time += quantum_time;
                    remaining_burst_time[i] -= quantum_time;
                } else {
                    time += remaining_burst_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }
        if (all_done)
            break;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void calculateAverageTimes(struct Process processes[], int n, float* avg_waiting_time, float* avg_turnaround_time) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    calculateWaitingTime(processes, n, 4);
    calculateTurnaroundTime(processes, n);

    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    *avg_waiting_time = (float)total_waiting_time / n;
    *avg_turnaround_time = (float)total_turnaround_time / n;
}

int main() {
    struct Process processes[MAX_PROCESSES] = {
        {24, 0, 0, 0},
        {3, 0, 0, 0},
        {3, 0, 0, 0}
    };

    int num_processes = sizeof(processes) / sizeof(processes[0]);

    float avg_waiting_time, avg_turnaround_time;
    calculateAverageTimes(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

