#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

int shared_data;    // Shared memory
sem_t semaphore;    // Semaphore for synchronization

void* thread1(void* arg)
{
    sem_wait(&semaphore);  // Wait for semaphore

    // Read and print double of the shared data
    int doubled_data = 2 * shared_data;
    printf("Thread 1: Doubled Data = %d\n", doubled_data);

    sem_post(&semaphore);  // Release semaphore

    pthread_exit(NULL);
}

void* thread2(void* arg)
{
    sem_wait(&semaphore);  // Wait for semaphore

    // Read and print five times the shared data
    int multiplied_data = 5 * shared_data;
    printf("Thread 2: Multiplied Data = %d\n", multiplied_data);

    sem_post(&semaphore);  // Release semaphore

    pthread_exit(NULL);
}

int main()
{
    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create two threads
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);

    // Set the shared data
    shared_data = 10;

    // Wait for the threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

