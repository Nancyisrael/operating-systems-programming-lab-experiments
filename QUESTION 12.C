#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

void bestFit(int partitions[], int m, int processes[], int n)
{
    int allocation[MAX_PROCESSES] = {-1};
  
    for (int i = 0; i < n; i++) {
        int bestFitIdx = -1;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (bestFitIdx == -1 || partitions[j] < partitions[bestFitIdx])
                    bestFitIdx = j;
            }
        }
  
        if (bestFitIdx != -1) {
            allocation[i] = bestFitIdx;
            partitions[bestFitIdx] -= processes[i];
        }
    }
  
    printf("\nProcess No.\tProcess Size\tPartition No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
  
int main()
{
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
  
    bestFit(partitions, MAX_PARTITIONS, processes, MAX_PROCESSES);
  
    return 0;
}

