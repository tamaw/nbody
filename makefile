# Makefile for nbody
# Date: Wed Mar 13 19:49:08 EST 2013
# Tama Waddell <tama.waddell@griffithuni.edu.au>

PROJECT	= nbody
CC		= mpicc
FLAGS	= -std=c99 -Wall -Iinclude -Iinclude/SDL -I/usr/include/openmpi-x86_64 -D_GNU_SOURCE=1 -D_REENTRANT -pthread -m64
LDFLAGS	= -Llib -L./lib/SDL -L/usr/lib64/openmpi/lib -Wl,-rpath,/tmp/gcc/lib 
DEPS	= -lgmp -lSDL -lmpi -ldl -lpthread 

#gcc -I/usr/include/openmpi-x86_64 
#-pthread -m64 -L/usr/lib64/openmpi/lib -lmpi -ldl

all: build

build: main.o body.o display.o
	$(CC) main.o display.o body.o $(LDFLAGS) $(DEPS) -o bin/$(PROJECT)

main.o: body.o display.o
	$(CC) -c $(FLAGS) main.c

body.o:
	$(CC) -c $(FLAGS) body.c

display.o:
	$(CC) -c $(FLAGS) display.c

clean:
	rm *.o bin/$(PROJECT)


