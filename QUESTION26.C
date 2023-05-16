#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_INSTANCES 4
#define NUM_PROCESSES 4

sem_t semaphore;

void* process(void* process_id) {
    int id = *(int*)process_id;

    printf("Process P%d is waiting on semaphore.\n", id);
    sem_wait(&semaphore);
    printf("Process P%d has acquired the semaphore.\n", id);

    // Simulate some work
       
	   printf("Process P%d is releasing the semaphore.\n", id);
    sem_post(&semaphore);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_PROCESSES];
    int process_ids[NUM_PROCESSES] = {1, 2, 3, 4};
    int i;

    // Initialize semaphore
    sem_init(&semaphore, 0, NUM_INSTANCES);

    // Create threads for each process
    for (i = 0; i < NUM_PROCESSES; i++) {
        pthread_create(&threads[i], NULL, process, &process_ids[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_PROCESSES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&semaphore);

    return 0;
}

