/*
 * oss.c
 * CMP SCI 4760 Operating Systems - Project #1
 *
 * Author: Lucas lovellette
 * Date:   02/08/2025
 *
 * Description:
 *   The oss process parses command line options and launches a specified number of user
 *   processes (child processes) while ensuring that no more than a given number of them run
 *   simultaneously. It uses fork() to create child processes and execl() to run the user process.
 *
 * Usage:
 *   ./oss [-h] [-n proc] [-s simul] [-t iter]
 *   -h         : display help message and exit.
 *   -n proc    : total number of user processes to launch (default 5).
 *   -s simul   : maximum number of simultaneous user processes (default 3).
 *   -t iter    : number of iterations to pass to each user process (default 7).
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void print_usage() {
    printf("Usage: ./oss [-h] [-n proc] [-s simul] [-t iter]\n");
    printf(" -h       Show help message\n");
    printf(" -n proc  Number of user processes to create\n");
    printf(" -s simul Max simultaneous user processes\n");
    printf(" -t iter  Number of iterations for each user process\n");
}

int main(int argc, char *argv[]) {
    int opt, proc = 5, simul = 3, iter = 7;  // Default values
    int running = 0, i = 0;

    while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
        switch (opt) {
            case 'h':
                print_usage();
            return 0;
            case 'n':
                proc = atoi(optarg);
            break;
            case 's':
                simul = atoi(optarg);
            break;
            case 't':
                iter = atoi(optarg);
            break;
            default:
                print_usage();
            return 1;
        }
    }

    printf("OSS: Launching %d user processes with max %d simultaneous, each doing %d iterations.\n", proc, simul, iter);

    while (i < proc) {
        if (running < simul) {
            pid_t pid = fork();
            if (pid < 0) {
                perror("Fork failed");
                exit(1);
            }
            if (pid == 0) {
                char iter_str[10];
                snprintf(iter_str, sizeof(iter_str), "%d", iter);
                execl("./user", "user", iter_str, (char *)NULL);
                perror("Exec failed");
                exit(1);
            }
            running++;
            i++;
        } else {
            wait(NULL);
            running--;
        }
    }

    while (running > 0) {
        wait(NULL);
        running--;
    }

    printf("OSS: All user processes completed.\n");
    return 0;
}
