#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int count = 0;  // Number of items in the buffer
int in = 0;     // Index to insert items
int out = 0;    // Index to remove items

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_empty = PTHREAD_COND_INITIALIZER;

void produce(int item) {
    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    count++;
}

int consume() {
    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    count--;
    return item;
}

void *producer(void *param) {
    int i;
    for (i = 0; i < 4; i++) {
        pthread_mutex_lock(&mutex);

        while (count == BUFFER_SIZE) {
            // Buffer is full, wait for consumer to consume items
            pthread_cond_wait(&buffer_full, &mutex);
        }

        produce(i);
        printf("Produced item %d\n", i);

        if (count == 1) {
            // Buffer was empty, notify consumer that it can start consuming
            pthread_cond_signal(&buffer_empty);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(0);
}

void *consumer(void *param) {
    pthread_mutex_lock(&mutex);

    while (count == 0) {
        // Buffer is empty, wait for producer to produce items
        pthread_cond_wait(&buffer_empty, &mutex);
    }

    int item = consume();
    printf("Consumed item %d\n", item);

    if (count == BUFFER_SIZE - 1) {
        // Buffer was full, notify producer that it can start producing
        pthread_cond_signal(&buffer_full);
    }

    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}

