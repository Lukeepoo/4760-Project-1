# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Targets
TARGETS = oss user

# Rules
all: $(TARGETS)

oss: oss.o
	$(CC) $(CFLAGS) -o oss oss.o

user: user.o
	$(CC) $(CFLAGS) -o user user.o

oss.o: oss.c
	$(CC) $(CFLAGS) -c oss.c

user.o: user.c
	$(CC) $(CFLAGS) -c user.c

clean:
	rm -f $(TARGETS) *.o
