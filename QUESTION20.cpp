#include <stdio.h>

// Structure to represent a memory partition
typedef struct {
    int size;
    int allocated;
} Partition;

// Function to allocate memory blocks using the worst-fit algorithm
void allocateMemory(Partition partitions[], int numPartitions, int processes[], int numProcesses) {
    int i, j;

    for (i = 0; i < numProcesses; i++) {
        int processSize = processes[i];
        int maxBlockSize = -1;
        int maxBlockIndex = -1;

        // Find the memory partition with the worst-fit
        for (j = 0; j < numPartitions; j++) {
            if (partitions[j].allocated == 0 && partitions[j].size >= processSize) {
                if (partitions[j].size > maxBlockSize) {
                    maxBlockSize = partitions[j].size;
                    maxBlockIndex = j;
                }
            }
        }

        // Allocate the memory block if a suitable partition is found
        if (maxBlockIndex != -1) {
            partitions[maxBlockIndex].allocated = 1;
            printf("Process of size %d KB is allocated to memory partition %d (size: %d KB)\n",
                   processSize, maxBlockIndex + 1, partitions[maxBlockIndex].size);
        } else {
            printf("Process of size %d KB cannot be allocated\n", processSize);
        }
    }
}

int main() {
    Partition partitions[] = {{300, 0}, {600, 0}, {350, 0}, {200, 0}, {750, 0}, {125, 0}};
    int processes[] = {115, 500, 358, 200, 375};
    int numPartitions = sizeof(partitions) / sizeof(partitions[0]);
    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    allocateMemory(partitions, numPartitions, processes, numProcesses);

    return 0;
}

