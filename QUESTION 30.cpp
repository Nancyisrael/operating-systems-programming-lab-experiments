#include <stdio.h>
#include <pthread.h>

void *printEven(void *arg) {
    int i;
    for (i = 2; i <= 20; i += 2) {
        printf("%d ", i);
    }
    return NULL;
}

void *printOdd(void *arg) {
    int i;
    for (i = 1; i <= 19; i += 2) {
        printf("%d ", i);
    }
    return NULL;
}

int main() {
    pthread_t evenThread, oddThread;

    pthread_create(&evenThread, NULL, printEven, NULL);
    pthread_create(&oddThread, NULL, printOdd, NULL);

    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    printf("\n");

    return 0;
}

