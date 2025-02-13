/*
 * user.c
 * CMP SCI 4760 Operating Systems - Project #1
 *
 * Author: Lucas Lovellette
 * Date:   02/08/2025
 *
 * Description:
 *   The user process accepts one command line argument (the number of iterations).
 *   For each iteration it outputs its PID, its parent's PID, and the current iteration number,
 *   sleeps for one second, and then outputs the same information after sleeping.
 *
 * Usage:
 *   ./user <iterations>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./user <iterations>\n");
        return 1;
    }

    int iter = atoi(argv[1]);
    for (int i = 1; i <= iter; i++) {
        printf("USER PID:%d PPID:%d Iteration:%d before sleeping\n", getpid(), getppid(), i);
        sleep(1);
        printf("USER PID:%d PPID:%d Iteration:%d after sleeping\n", getpid(), getppid(), i);
    }

    return 0;
}
