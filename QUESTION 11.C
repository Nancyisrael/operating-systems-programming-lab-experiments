#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void printOddNumbers()
{
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    for (int i = 1; i <= 10; i += 2) {
        printf("Odd Number: %d\n", i);
    }
}

void printEvenNumbers()
{
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    for (int i = 2; i <= 10; i += 2) {
        printf("Even Number: %d\n", i);
    }
}

void printMultiplesOf3()
{
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    for (int i = 3; i <= 30; i += 3) {
        printf("Multiple of 3: %d\n", i);
    }
}

void printMultiplesOf5()
{
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    for (int i = 5; i <= 50; i += 5) {
        printf("Multiple of 5: %d\n", i);
    }
}

int main()
{
    pid_t pid1, pid2, pid3, pid4;

    pid1 = fork();

    if (pid1 == 0) {
        // First child process for odd numbers
        printOddNumbers();
    } else {
        pid2 = fork();
        if (pid2 == 0) {
            // Second child process for even numbers
            printEvenNumbers();
        } else {
            pid3 = fork();
            if (pid3 == 0) {
                // Third child process for multiples of 3
                printMultiplesOf3();
            } else {
                pid4 = fork();
                if (pid4 == 0) {
                    // Fourth child process for multiples of 5
                    printMultiplesOf5();
                }
            }
        }
    }

    return 0;
}

