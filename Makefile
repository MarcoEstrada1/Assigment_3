F90 = f95
CC = gcc
FLAGS = -O3
FLAGS0 = -O0
FLAGS02= -O2
FLAGS3=-Og
OBJS= Head.c tools.c
BINARY= SOLHEAD
BINARY2= soldebug
BINARY3=profal

all: $(BINARY)

SOLHEAD: $(OBJS)
	$(CC) -o $(BINARY) $(FLAGS02)  $(OBJS) -lm
	
soldebug: $(OBJS)
	$(CC) -g -o $(BINARY2) $(FLAGS0)  $(OBJS) -lm
profal: $(OBJS)
	$(CC) -pg -o $(BINARY3) $(FLAGS3) $(OBJS) -lm

clean:
	rm -f $(BINARY) $(BINARY2) $(BINARY3)
	

		