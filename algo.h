// Created by Shalev Ben David.
# include <limits.h>
# include <stdbool.h>
# include "graph.h"

#define INFINITY INT_MAX

#ifndef SP_EX4_ALGO_H
#define SP_EX4_ALGO_H

typedef struct priority_queue_ {
    pnode node;
    int distance;
    bool visited;
    struct priority_queue_* next;
} queue, *pqueue;

int dijkstra (pnode, pnode, pnode);
pqueue createQueue (pnode, pnode);
pqueue search_queue(pqueue, pnode);
void delete_queue(pqueue*);
int factorial(int);
void find_permutations(pnode*, int*, int*, int, int, int *);
int shortest_path(pnode *head, int  [], int size);

#endif //SP_EX4_ALGO_H
