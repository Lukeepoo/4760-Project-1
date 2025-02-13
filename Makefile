# Makefile for CMP SCI 4760 Operating Systems Project #1
#
# This Makefile compiles two executables: oss and user.
# Use the "all" target to compile both.
# Use "make clean" to remove compiled binaries and object files.

CC = gcc
CFLAGS = -Wall -g
TARGETS = oss user

all: $(TARGETS)

oss: oss.c
	$(CC) $(CFLAGS) -o oss oss.c

user: user.c
	$(CC) $(CFLAGS) -o user user.c

clean:
	rm -f $(TARGETS) *.o
