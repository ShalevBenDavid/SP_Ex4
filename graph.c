// Created by Shalev Ben David on 10/01/2023.
# include <stdio.h>
# include <stdlib.h>
# include "edges.h"
# include "nodes.h"

char build_graph_cmd(pnode *head, int numOfVertexes) {
    char c; // The current char from the input.
    if ((*head = (pnode) malloc(sizeof (node))) == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    pnode p = *head;
    p -> node_num = 0;
    p -> edges = NULL;
    p -> next = NULL;
    for (int i = 1; i < numOfVertexes; i++) {
        if (create_node(head, i) == -1) {
            printf("Couldn't create node %d,\n", i);
        }
    }
    scanf(" %c", &c);
    again:
    if (c == 'n') {
        int node_num; // The node ID.
        scanf(" %d", &node_num);
        int dest; // The destination of the edge.
        int weight; // The weight of the edge;
        while (scanf(" %d %d", &dest, &weight) == 2) { // We received the dest and the weight successfully.
            if (create_edge(head, node_num, weight, dest) == -1) {
                printf("Couldn't create edge from %d to %d with %d weight.\n", node_num, dest, weight);
            }
        }
        scanf(" %c", &c);
        goto again;
    }
    return c;
}

int insert_node_cmd(pnode *head, int vertexNum) {
    pnode temp = search_node(head, vertexNum);
    int dest; // The destination of the edge.
    int weight; // The weight of the edge;
    if (temp != NULL) { // If vertex exists.
        if (temp -> edges != NULL) {
            delete_node_edges(temp);
        }
        while (scanf(" %d %d", &dest, &weight) == 2) { // We received the dest and the weight successfully.
            if (create_edge(head, vertexNum, weight, dest) == -1) {
                printf("Couldn't create edge from %d to %d with %d weight.\n", vertexNum, dest, weight);
            }
        }
    }
    else { // If vertex doesnt exists.
        if (create_node(head, vertexNum) == -1) {
            printf("Couldn't create node %d,\n", vertexNum);
            return -1;
        }
        while (scanf(" %d %d", &dest, &weight) == 2) { // We received the dest and the weight successfully.
            if (create_edge(head, vertexNum, weight, dest) == -1) {
                printf("Couldn't create edge from %d to %d with %d weight.\n", vertexNum, dest, weight);
            }
        }
    }
    return 0;
}

void delete_node_cmd (pnode *head, int vertexToDelete) {
    pnode temp = *head;
    if (temp -> node_num == vertexToDelete) { // Deleting head.
        delete_incoming_edges(head, temp);
        delete_node_edges(temp);
        *head = temp -> next;
        free(temp);
    }
    else {
        while ((temp -> next != NULL) && (temp -> next -> node_num != vertexToDelete)) {
            temp = temp -> next;
        }
        if (temp -> next != NULL) {
            pnode temp1 = temp -> next;
            temp -> next = temp -> next -> next;
            delete_incoming_edges(head, temp1);
            delete_node_edges(temp1);
            free(temp1);
        }
        else {
            printf("Node %d you wanted to delete wasn't found.\n", vertexToDelete);
        }
    }
}

void printGraph_cmd (pnode head) {
    pnode v = head;
    int E = 0;
    while (v != NULL) {
        pedge e = v -> edges;
        E += total_edges(e);
        printf("Vertex: %d, Edges: ", v -> node_num);
        while (e != NULL) {
            printf("(w: %d, d: %d)", e -> weight, e -> endpoint -> node_num);
            e = e -> next;
        }
        printf("/n");
        v = v -> next;
    }
    printf("|E| = %d, |V| = %d", E, total_nodes(head));
}

void deleteGraph_cmd(pnode* head) {
    pnode temp = *head;
    while (temp != NULL) {
        pedge e = temp -> edges;
        while (e != NULL) {
            pedge e1 = e;
            e = e -> next;
            free(e1);
        }
        pnode temp1 = temp;
        temp = temp -> next;
        free(temp1);
    }
    free(temp);
}

void shortsPath_cmd(pnode head, int srcV, int destV) {

}

void TSP_cmd(pnode head, int k) {

}