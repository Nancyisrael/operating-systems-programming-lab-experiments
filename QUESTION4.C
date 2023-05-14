#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

// Structure to represent memory partitions
struct Partition {
    int size;
    int allocated;
};

// Structure to represent processes
struct Process {
    int size;
    int partitionIndex;
};

// Function to allocate memory using the first-fit algorithm
void allocateMemory(struct Partition partitions[], struct Process processes[]) {
    int i, j;
    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (partitions[j].allocated == 0 && partitions[j].size >= processes[i].size) {
                // Allocate the process to the current partition
                partitions[j].allocated = 1;
                processes[i].partitionIndex = j;
                break;
            }
        }
    }
}

// Function to display the memory allocation result
void displayResult(struct Partition partitions[], struct Process processes[]) {
    printf("Process\tProcess Size\tPartition\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d KB\t\t", i+1, processes[i].size);
        if (processes[i].partitionIndex != -1) {
            printf("%d (%d KB)\n", processes[i].partitionIndex+1, partitions[processes[i].partitionIndex].size);
        } else {
            printf("Not Allocated\n");
        }
    }
}

int main() {
    struct Partition partitions[MAX_PARTITIONS] = {
        {300, 0},
        {600, 0},
        {350, 0},
        {200, 0},
        {750, 0},
        {125, 0}
    };

    struct Process processes[MAX_PROCESSES] = {
        {115, -1},
        {500, -1},
        {358, -1},
        {200, -1},
        {375, -1}
    };

    allocateMemory(partitions, processes);
    displayResult(partitions, processes);

    return 0;
}

