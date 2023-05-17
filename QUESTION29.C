#include <stdio.h>

#define NUM_PARTITIONS 4
#define NUM_PROCESSES 5

void firstFit(int partitions[], int numPartitions, int processes[], int numProcesses) {
    int allocation[numProcesses];
  
    for (int i = 0; i < numProcesses; i++) {
        allocation[i] = -1; // Initialize allocation array with -1 indicating unallocated processes
  
        for (int j = 0; j < numPartitions; j++) {
            if (processes[i] <= partitions[j]) {
                allocation[i] = j; // Allocate process to the partition
                partitions[j] -= processes[i]; // Reduce available memory in the partition
                break;
            }
        }
    }
  
    printf("\nProcess\tProcess Size\tPartition\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("%d\t%d KB\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int partitions[NUM_PARTITIONS] = {40, 10, 30, 60};
    int processes[NUM_PROCESSES] = {100, 50, 30, 120, 35};
  
    printf("Memory Partition Sizes:\n");
    for (int i = 0; i < NUM_PARTITIONS; i++) {
        printf("%d. %d KB\n", i + 1, partitions[i]);
    }
  
    firstFit(partitions, NUM_PARTITIONS, processes, NUM_PROCESSES);
  
    return 0;
}

