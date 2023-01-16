// Created by Shalev Ben David.
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "graph.h"
# include "nodes.h"
# include "algo.h"

int dijkstra (pnode head, pnode s, pnode d) {
    pqueue headq = createQueue(head, s);
    pnode a = search_queue(headq, d);
    printf("d: %d", a->node_num);
    pqueue u = headq;
    while (u != NULL) {
        pedge e = u -> node -> edges;
        while (e != NULL) {
            printf("before search queue\n");
            pqueue v = search_queue(headq, e -> endpoint);
            printf("after search queue\n");
            if (v != NULL) {
                if (v -> distance > u -> distance + e -> weight) {
                    v -> distance = u -> distance + e -> weight;
                }
            }
            e = e -> next;
        }
        u -> visited = true;
        u = u -> next;
    }
    printf("baefore result\n");
    pqueue result = search_queue(headq, d);
    printf("after result\n");
    if (result != NULL) {
        int r = result->distance;
        return (r != INFINITY) ? r : -1;
    }
    delete_queue(&headq);
    return -1;
}

pqueue createQueue (pnode head, pnode s) {
    pqueue headq;
    if((headq = (pqueue) malloc(sizeof(queue))) == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    headq -> node = s;
    headq -> distance = 0;
    headq -> visited = false;
    headq -> next = NULL;
    pnode temp = head;
    pqueue  tempq = headq;
    while (temp != NULL) {
        if (temp != s) {
            if ((tempq -> next = (pqueue) malloc(sizeof(queue))) == NULL) {
                printf("Memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }
            tempq = tempq -> next;
            tempq -> node = temp;
            tempq -> distance = INFINITY;
            tempq -> visited = false;
            headq -> next = NULL;
        }
        temp = temp -> next;
    }
    return headq;
}

pqueue search_queue(pqueue headq, pnode v) {
    pqueue temp = headq;
    while (temp != NULL) {
        if (temp -> node == v) {
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

void delete_queue(pqueue* headq) {
    pqueue temp = *headq;
    while (temp != NULL) {
        pqueue temp1 = temp;
        temp = temp -> next;
        free(temp1);
    }
    free(temp);
}

// ----------------------------------- TSP Methods -----------------------------------

int factorial(int n){
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Recursive
void find_permutations(pnode *head, int* nodes, int* permutations, int left, int right, int *index) {
    if (left == right) {
        permutations[*index] = shortest_path(head, nodes, right);
        *index++;
        return;
    }
    for (int i = left; i <= right; i++) {
        int temp = 0;
        temp = nodes[i];
        nodes[i] = nodes[left];
        nodes[left] = temp;
        find_permutations(head, nodes, permutations, left + 1, right, index);
        temp = nodes[i];
        nodes[i] = nodes[left];
        nodes[left] = temp;
    }
}

// Sums the shortest path using all nodes from nodes[0] to nodes[size].
int shortest_path(pnode * head, int nodes[], int size){
    int dist = 0;
    for (int i = 0; i < size; i++) {
        pnode s = search_node(*head, nodes[i]);
        pnode d = search_node(*head, nodes[i + 1]);
        int shortestDist = dijkstra(*head, s, d);
        if (shortestDist == -1) {
            return INT_MAX;
        }
        dist += shortestDist;
    }
    return dist;
}