# CMP SCI 4760 Operating Systems - Project 1

## Overview

This project implements a process management system in C using the `fork()` and `exec()` system calls. The program `oss` creates and manages multiple child processes (`user`), ensuring that no more than a specified number of processes run simultaneously. Each `user` process performs a specified number of iterations, printing its status before and after sleeping.

## Requirements

- A Unix-like environment with Bash and GCC installed.
- `make` for compiling the program.

## Files

- **`oss.c`**: The parent process that manages the creation and execution of `user` processes.
- **`user.c`**: The child process that performs a task and reports its status.

## Compilation

To compile the program, navigate to the project directory and run:

```make```

This will generate the following executables:
- **`oss`**: The main program that creates and controls the `user` processes.
- **`user`**: The program executed by each child process.

## Usage

### Running the Program

The `oss` program is executed with the following command-line options:

`./oss [-h help] [-n number of processes] [-s number of processes launched simultaneously] [-t number of iterations of each process]`

`-h`: Displays the above message and exits.

`-n`: Specifies the number of `user` processes to launch. Will default to 5 if not given.

`-s`: Specifies the maximum number of `user` processes that can be run simulatneously. Will default to 3 if not given.

`-t`: Specifies the number of iteration of each `user` process will perform. Will default to 10 if not given.

### Example Commands

1. Launch 8 user processes, with up to 4 running simultaneously, each performing 7 iterations: `./oss -n 8 -s 4 -t 7`
2. Launch 3 user processes, with up to 2 running simultaneously, each performing 6 iterations: `./oss -n 3 -s 2 -t 6`
3. Display help message: `./oss -h`

### Expected Output

Number of processes: 5

Max simultaneous processes: 3

Iterations per process: 7

USER PID:6577 PPID:6576 Iteration:1 before sleeping

USER PID:6577 PPID:6576 Iteration:1 after sleeping

...
