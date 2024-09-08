#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For getopt

int main(int argc, char* argv[]) {
    // Default values
    int num_processes = 5;
    int max_simultaneous = 3;
    int iterations = 10;

    // Parsing command-line arguments
    int opt;
    while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) {
        switch (opt) {
        case 'h':
            printf("Usage: ./oss [-h] [-n proc] [-s simul] [-t iter]\n");
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
            fprintf(stderr, "Usage: ./oss [-h] [-n proc] [-s simul] [-t iter]\n");
            exit(EXIT_FAILURE);
        }
    }

    // For testing, print out the values
    printf("Number of processes: %d\n", num_processes);
    printf("Max simultaneous processes: %d\n", max_simultaneous);
    printf("Iterations per process: %d\n", iterations);

    // Placeholder for future logic to fork and exec user processes

    return 0;
}
