//Written by: Lucas Lovellette
//Written on: 09/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For getpid, getppid, and sleep

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./user <iterations>\n");
        return 1;
    }

    int iterations = atoi(argv[1]);

    for (int i = 0; i < iterations; i++) {
        printf("USER PID:%d PPID:%d Iteration:%d before sleeping\n", getpid(), getppid(), i + 1);
        sleep(1);
        printf("USER PID:%d PPID:%d Iteration:%d after sleeping\n", getpid(), getppid(), i + 1);
    }

    return 0;
}
