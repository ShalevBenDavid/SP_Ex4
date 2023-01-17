// Created by Shalev Ben David.
#include <stdio.h>
# include <stdlib.h>
# include "graph.h"
# include "nodes.h"

int total_edges (pedge edge) {
    int totalEdges = 0;
    pedge temp = edge;
    while (temp != NULL) {
        totalEdges++;
        temp = temp -> next;
    }
    return totalEdges;
}

int create_edge (pnode* head, int srcV, int weight, int destV) {
    pnode source = search_node(*head, srcV);
    pnode dest = search_node(*head, destV);
    if (source == NULL || dest == NULL) {
        return -1;
    }
    else {
        if (source -> edges == NULL) { // Source doesnt have outgoing edges.
            if ((source -> edges = (pedge)malloc(sizeof(edge))) == NULL) {
                printf("Memory allocation failed!\n");
                return -1;
            }
            source -> edges -> next = NULL;
            source -> edges -> weight = weight;
            source -> edges -> endpoint = dest;
        }
        else { // Source has outgoing edges.
            pedge e = source -> edges;
            while (e -> next != NULL) {
                e = e -> next;
            }
            if ((e -> next = (pedge) malloc(sizeof (edge))) == NULL) {
                printf("Memory allocation failed!\n");
                return -1;
            }
            e -> next -> next = NULL;
            e -> next -> weight = weight;
            e -> next -> endpoint = dest;
        }
    }
    return 0;
}

void delete_node_edges (pnode v) {
    if (v -> edges == NULL) {
        free (v -> edges);
    }
    else {
        while (v -> edges != NULL) {
            pedge temp = v -> edges;
            v -> edges = v -> edges -> next;
            free(temp);
        }
        free(v -> edges);
    }
}

void delete_incoming_edges (pnode* head, pnode dest) {
pnode temp = *head;
while (temp != NULL) {
    if (temp -> edges == NULL || temp == dest) { // There cant be an edge from a node to himself.
        temp = temp -> next;
    }
    else {
        if (temp -> edges -> endpoint == dest) {
            pedge edgeToDelete = temp -> edges;
            temp -> edges = temp -> edges -> next;
            free(edgeToDelete);
        }
        else {
            pedge p = temp -> edges;
            while ((p -> next != NULL) && (p -> next -> endpoint != dest)) {
                p = p -> next;
            }
            if (p -> next != NULL) {
                    pedge edgeToDelete = p -> next;
                    p -> next = p -> next -> next;
                    free(edgeToDelete);
                }
            }
        }
        temp = temp -> next;
    }
}
