.PHONY = all clean
#Defining Macros
AR = ar
CC = gcc
FLAGS = -Wall -g

all: graph

#Creating Program
graph: libgraph.a main.o
	$(CC) $(FLAGS) -o graph main.o libgraph.a
#Creating Static Library
libgraph.a: libgraph.o
	$(AR) -rc libgraph.a libgraph.o
#Creating Objects
libgraph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a graph