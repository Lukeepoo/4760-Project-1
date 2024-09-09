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

```bash
make

This will generate the following executables
- **`oss`**: The main program that creates and controls the `user` processes.
- **`user`**: The program executed by each child process