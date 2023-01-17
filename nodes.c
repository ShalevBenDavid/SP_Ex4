// Created by Shalev Ben David.
#include <stdio.h>
# include <stdlib.h>
# include "graph.h"
# include "edges.h"

int total_nodes (pnode head) {
    int totalNodes = 0;
    pnode temp = head;
    while (temp != NULL) {
        totalNodes++;
        temp = temp -> next;
    }
    return totalNodes;
}

pnode search_node (pnode head, int vertexNum) {
    pnode temp = head;
    while (temp != NULL) {
        if (temp -> node_num == vertexNum) {
            return temp;
        }
        temp = temp -> next;
    }
    return NULL;
}

int create_node (pnode *head, int vertexNum) {
    pnode temp = *head;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    if ((temp -> next = (pnode)malloc(sizeof (node))) == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }
    temp -> next -> node_num = vertexNum;
    temp -> next -> edges = NULL;
    temp -> next -> next = NULL;
    return 0;
}