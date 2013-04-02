# Makefile for nbody
# Date: Wed Mar 13 19:49:08 EST 2013
# Tama Waddell <tama.waddell@griffithuni.edu.au>

PROJECT	= nbody
CC		= gcc
FLAGS	= -std=c99 -Wall -Iinclude -Iinclude/SDL -D_GNU_SOURCE=1 -D_REENTRANT
LDFLAGS	= -Llib -L./lib/SDL -Wl,-rpath,/tmp/gcc/lib -lSDL -lpthread -lm -ldl -lpthread
DEPS	= -lgmp -lSDL

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


