#include<stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    findWaitingTime(processes, n, bt, wt);
    
    findTurnaroundTime(processes, n, bt, wt, tat);
    
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        
        printf("%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    
    double avg_wt = (double)total_wt / n;
    double avg_tat = (double)total_tat / n;
    
    printf("\nAverage Waiting Time: %.2lf", avg_wt);
    printf("\nAverage Turnaround Time: %.2lf", avg_tat);
}

int main()
{
    int processes[] = {0, 1, 2};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {2, 4, 8};
    
    findAverageTime(processes, n, burst_time);
    
    return 0;
}

