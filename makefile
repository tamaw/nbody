# Makefile for nbody
# Date: Wed Mar 13 19:49:08 EST 2013
# Tama Waddell <tama.waddell@griffithuni.edu.au>

PROJECT	= nbody
CC		= gcc
FLAGS	= -std=c99 -Wall -Iinclude
LDFLAGS	= -L/home/s2626286/assignment1/lib
DEPS	= -lgmp

 #gcc -std=c99 -Wall -L/home/s2626286/assignment1/lib -o main main.c -lgmp && ./main

all: build

build: main.o universe.o body.o
	$(CC) main.o universe.o body.o $(LDFLAGS) $(DEPS) -o $(PROJECT)

main.o: universe.o body.o
	$(CC) -c $(FLAGS) main.c

universe.o:
	$(CC) -c $(FLAGS) universe.c

body.o:
	$(CC) -c $(FLAGS) body.c

clean:
	rm *.o $(PROJECT)


