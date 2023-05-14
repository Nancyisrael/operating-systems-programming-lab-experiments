#include<stdio.h>

void calculateWaitingTime(int burstTime[], int n, int waitingTime[])
{
    waitingTime[0] = 0;
  
    for (int i = 1; i < n ; i++)
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
}
  
void calculateTurnaroundTime(int burstTime[], int n, int waitingTime[], int turnaroundTime[])
{
    for (int i = 0; i < n ; i++)
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
}
  
void calculateAverageTimes(int burstTime[], int n)
{
    int waitingTime[n], turnaroundTime[n], totalWaitingTime = 0, totalTurnaroundTime = 0;
  
    calculateWaitingTime(burstTime, n, waitingTime);
  
    calculateTurnaroundTime(burstTime, n, waitingTime, turnaroundTime);
  
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  
    for (int i=0; i<n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
  
    double avgWaitingTime = (double)totalWaitingTime / n;
    double avgTurnaroundTime = (double)totalTurnaroundTime / n;
  
    printf("\nAverage Waiting Time: %.2lf", avgWaitingTime);
    printf("\nAverage Turnaround Time: %.2lf", avgTurnaroundTime);
}
  
int main()
{
    int burstTime[] = {10, 15, 25};
    int n = sizeof(burstTime) / sizeof(burstTime[0]);
  
    calculateAverageTimes(burstTime, n);
  
    return 0;
}

