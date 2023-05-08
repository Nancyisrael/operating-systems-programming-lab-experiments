#include <stdio.h>

#define NUM_PROCESSES 3
#define NUM_RESOURCES 3

void detect_deadlock(int allocation[NUM_PROCESSES][NUM_RESOURCES], int max[NUM_PROCESSES][NUM_RESOURCES], int available[NUM_RESOURCES]) {
    int work[NUM_RESOURCES];
    int finish[NUM_PROCESSES] = {0};
    int i, j, k;
    int deadlock = 1;  // assume there is deadlock by default

    // Initialize the work array to the available resources
    for (i = 0; i < NUM_RESOURCES; i++) {
        work[i] = available[i];
    }

    // Look for an unmarked process that can complete its resource needs
    for (k = 0; k < NUM_PROCESSES; k++) {
        if (!finish[k]) {
            int can_complete = 1;

            for (j = 0; j < NUM_RESOURCES; j++) {
                if (max[k][j] - allocation[k][j] > work[j]) {
                    can_complete = 0;
                    break;
                }
            }

            if (can_complete) {
                // Process k can complete its resource needs
                finish[k] = 1;
                deadlock = 0;  // there is no deadlock
                for (j = 0; j < NUM_RESOURCES; j++) {
                    work[j] += allocation[k][j];
                }
            }
        }
    }

    if (deadlock) {
        // There is a deadlock
        printf("System is in a deadlock state.\n");
        printf("The deadlocked processes are: ");
        for (i = 0; i < NUM_PROCESSES; i++) {
            if (!finish[i]) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        // There is no deadlock
        printf("System is not in a deadlock state.\n");
    }
}

int main() {
    int allocation[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 3, 3},
        {2, 0, 3},
        {1, 2, 4}
    };
    int max[NUM_PROCESSES][NUM_RESOURCES] = {
        {3, 6, 8},
        {4, 3, 3},
        {3, 4, 4}
    };
    int available[NUM_RESOURCES] = {1, 2, 0};

    detect_deadlock(allocation, max, available);

    return 0;
}
