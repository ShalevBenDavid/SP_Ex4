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
void createQueue (pqueue*, pnode, pnode);
pqueue search_queue(pqueue, pnode);
pqueue get_min_unvisited_queue(pqueue);
void delete_queue(pqueue*);
int factorial(int);
void find_permutations(pnode, int*, int*, int, int, int *);
int shortest_path(pnode, int[], int);

#endif //SP_EX4_ALGO_H
