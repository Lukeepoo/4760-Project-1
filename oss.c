#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int num_processes = 5;
    int max_simultaneous = 3;
    int iterations = 10;

    int opt;
    while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
        switch (opt) {
        case 'h':
            printf("Usage: ./oss [-h help] [-n number of processes] [-s number of processes launched simultaneously] [-t number of iterations of each process]\n");
            exit(0);
        case 'n':
            num_processes = atoi(optarg);
            break;
        case 's':
            max_simultaneous = atoi(optarg);
            break;
        case 't':
            iterations = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Usage: ./oss [-h help] [-n number of processes] [-s number of processes launched simultaneously] [-t number of iterations of each process]\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("Number of processes: %d\n", num_processes);
    printf("Max simultaneous processes: %d\n", max_simultaneous);
    printf("Iterations per process: %d\n", iterations);

    // Fork and Exec logic
    int active_processes = 0;
    for (int i = 0; i < num_processes; i++) {
        if (active_processes >= max_simultaneous) {
            wait(NULL); // Wait for any child to finish
            active_processes--;
        }

        pid_t pid = fork();
        if (pid == 0) {
            // In the child process
            char iter_str[10];
            sprintf(iter_str, "%d", iterations);
            execl("./user", "user", iter_str, (char*)NULL);
            perror("execl failed"); // This will only run if execl fails
            exit(1);
        }
        else if (pid > 0) {
            // In the parent process
            active_processes++;
        }
        else {
            // Fork failed
            perror("fork failed");
            exit(1);
        }
    }

    // Wait for all remaining children to finish
    while (active_processes > 0) {
        wait(NULL);
        active_processes--;
    }

    return 0;
}
