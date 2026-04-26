CC = gcc
CFLAGS = -O0 -g -Wall
OBJS = bomb.o phases.o support.o

bomb: $(OBJS)
	$(CC) $(CFLAGS) -o bomb $(OBJS)

bomb.o: bomb.c phases.h support.h
phases.o: phases.c phases.h support.h
support.o: support.c support.h

clean:
	rm -f bomb $(OBJS)
