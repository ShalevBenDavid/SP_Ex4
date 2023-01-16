// Created by Shalev Ben David.
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include "graph.h"
# include "nodes.h"
# include "algo.h"

int dijkstra (pnode head, pnode s, pnode d) {
    pqueue head1 = NULL;
    pqueue *headq = &head1;
    createQueue(headq, head, s);
    pqueue u = *headq;
    while (u != NULL) {
        pedge e = u -> node -> edges;
        while (e != NULL) {
            pqueue v = search_queue(*headq, e -> endpoint);
            if (v != NULL) {
                if (v -> distance > u -> distance + e -> weight) {
                    v -> distance = u -> distance + e -> weight;
                }
            }
            e = e -> next;
        }
        u -> visited = true;
        u = get_min_unvisited_queue(*headq);
    }
    pqueue result = search_queue(*headq, d);
    if (result != NULL) {
        int r = result -> distance;
        delete_queue(headq);
        return (r != INFINITY) ? r : -1;
    }
    delete_queue(headq);
    return -1;
}

void createQueue (pqueue* headq, pnode head, pnode s) {
    if ((*headq = (pqueue) malloc(sizeof(queue))) == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    pqueue tempq = *headq;
    tempq -> node = s;
    tempq -> distance = 0;
    tempq -> visited = false;
    tempq -> next = NULL;
    pnode temp = head;
    while (temp != NULL) {
        if (temp != s) {
            if ((tempq -> next = (pqueue) malloc(sizeof(queue))) == NULL) {
                printf("Memory allocation failed!\n");
                exit(EXIT_FAILURE);
            }
            tempq = tempq->next;
            tempq -> node = temp;
            tempq -> distance = INFINITY;
            tempq -> visited = false;
            tempq -> next = NULL;
        }
        temp = temp->next;
    }
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

pqueue get_min_unvisited_queue(pqueue headq) {
    pqueue temp = headq;
    pqueue minNode = NULL;
    int minDist = INFINITY;
    while (temp != NULL) {
        if (temp-> visited == false && temp->distance < minDist) {
            minDist = temp -> distance;
            minNode = temp;
        }
        temp = temp -> next;
    }
    return minNode;
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

// Recursive chain to update paths of permutation.
void find_permutations(pnode head, int* cities, int* permutations, int left, int right, int *index) {
    if (left == right) {
        permutations[*index++] = shortest_path(head, cities, right);
        return;
    }
    else {
        for (int i = left; i <= right; i++) {
            int temp = cities[i];
            cities[i] = cities[left];
            cities[left] = temp;
            find_permutations(head, cities, permutations, left + 1, right, index);
            temp = cities[i];
            cities[i] = cities[left];
            cities[left] = temp;
        }
    }
}

// Sums the shortest path along cities[0] to cities[size].
int shortest_path(pnode head, int nodes[], int size){
    int dist = 0;
    for (int i = 0; i < size; i++) {
        pnode s = search_node(head, nodes[i]);
        pnode d = search_node(head, nodes[i + 1]);
        int shortestDist = dijkstra(head, s, d);
        if (shortestDist == -1) {
            return INT_MAX;
        }
        dist += shortestDist;
    }
    return dist;
}
