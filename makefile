.PHONY = all clean
#Defining Macros
AR = ar
CC = gcc
FLAGS = -Wall -g

all: graph

#Creating Program
graph: graph.o nodes.o edges.o algo.o main.o
	$(CC) $(FLAGS) -o graph graph.o nodes.o edges.o algo.o main.o
#Creating Objects
graph.o: graph.c nodes.h edges.h
	$(CC) $(FLAGS) -c graph.c
nodes.o: nodes.c graph.h edges.h
	$(CC) $(FLAGS) -c nodes.c
edges.o: edges.c graph.h nodes.h
	$(CC) $(FLAGS) -c edges.c
algo.o: algo.c graph.h algo.h
	$(CC) $(FLAGS) -c algo.c
main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o graph