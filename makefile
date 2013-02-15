OBJS = thing.o otherthing.o
CC = gcc
CFLAGS = -Wall -c

thing: $(OBJS)
	$(CC) $(OBJS) -o thing
thing.o: thing.c thing.h
	$(CC) $(CFLAGS) thing.c
otherthing.o: otherthing.c thing.c
	$(CC) $(CFLAGS) otherthing.c

