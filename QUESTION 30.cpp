#include <stdio.h>
#include <pthread.h>

#define MAX_NUMBER 10

pthread_mutex_t mutex;
pthread_cond_t cond;

int count = 1;

void *print_even(void *arg) {
    while (count <= MAX_NUMBER) {
        pthread_mutex_lock(&mutex);

        if (count % 2 == 0) {
            printf("Even Thread: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    while (count <= MAX_NUMBER) {
        pthread_mutex_lock(&mutex);

        if (count % 2 != 0) {
            printf("Odd Thread: %d\n", count);
            count++;
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t even_thread, odd_thread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&even_thread, NULL, print_even, NULL);
    pthread_create(&odd_thread, NULL, print_odd, NULL);

    pthread_join(even_thread, NULL);
    pthread_join(odd_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}

