#include<stdio.h>

void worstFit(int memory[], int m, int processes[], int n) {
    int allocation[n];
  
    for (int i = 0; i < n; i++) {
        int worst_index = -1;
        for (int j = 0; j < m; j++) {
            if (memory[j] >= processes[i]) {
                if (worst_index == -1 || memory[j] > memory[worst_index])
                    worst_index = j;
            }
        }
  
        if (worst_index != -1) {
            allocation[i] = worst_index;
            memory[worst_index] -= processes[i];
        }
        else
            allocation[i] = -1;
    }
  
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int memory[] = {40, 10, 30, 60};  // Memory partitions
    int processes[] = {100, 50, 30, 120, 35};  // Processes
    int m = sizeof(memory) / sizeof(memory[0]);
    int n = sizeof(processes) / sizeof(processes[0]);
  
    worstFit(memory, m, processes, n);
  
    return 0;
}

