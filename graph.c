// Created by Shalev Ben David on 10/01/2023.
# include <stdio.h>
# include <stdlib.h>
# include "graph.h"

int create_edge(pnode*, int, int, int);
pnode search_node (pnode*, int);
int total_nodes (pnode *head);
int total_edges (pedge *edge);
void delete_node_edges (pnode);
void delete_incoming_edges (pnode*, pnode );


char build_graph_cmd(pnode *head, int numOfVertexes) {
    char c; // The current char from the input.
    for (int i = 0; i < numOfVertexes; i++) {
        insert_node_cmd(head, i);
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
    if (temp != NULL) {
        if (temp -> edges != NULL) {
            delete_node_edges(temp);
        }
        while (scanf(" %d %d", &dest, &weight) == 2) { // We received the dest and the weight successfully.
            if (create_edge(head, vertexNum, weight, dest) == -1) {
                printf("Couldn't create edge from %d to %d with %d weight.\n", vertexNum, dest, weight);
            }
        }
    }
    else {
        temp = *head;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = (pnode)malloc(sizeof (node));
        if (temp -> next == NULL) {
            printf("Memory allocation failed!");
            return -1;
        }
        temp -> next -> node_num = vertexNum;
        temp -> next -> next = NULL;
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
    if (temp -> node_num == vertexToDelete) {
        delete_incoming_edges(head, temp);
        head = &temp -> next;
        free(temp);
    }
    else {
        while (temp -> next != NULL && temp -> next-> node_num != vertexToDelete) {
            temp = temp -> next;
        }
        if (temp -> next != NULL) {
            pnode temp1 = temp -> next;
            temp -> next = temp -> next -> next;
            delete_incoming_edges(head, temp1);
            free(temp1);
        }
    }
}

void printGraph_cmd (pnode head) {
    pnode v = head;
    int E = 0;
    while (v != NULL) {
        pedge e = v -> edges;
        E += total_edges(&e);
        v = v -> next;
    }
    printf("|E| = %d, |V| = %d", E, total_nodes(&head));
}

void deleteGraph_cmd(pnode* head) {

}

void shortsPath_cmd(pnode head, int srcV, int destV) {

}

void TSP_cmd(pnode head, int k) {

}

// --------------------------- Edges Methods ---------------------------

int total_edges (pedge *edge) {
    int totalEdges = 0;
    pedge temp = *edge;
    while (temp != NULL) {
        totalEdges++;
        temp = temp -> next;
    }
    return totalEdges;
}

int create_edge (pnode* head, int srcV, int weight, int destV) {
    pnode source = search_node(head, srcV);
    pnode dest = search_node(head, destV);
    if (source == NULL || dest == NULL) {
        return -1;
    }
    else {
        if (source -> edges == NULL) {
            source -> edges = (pedge)malloc(sizeof(edge));
            if (source -> edges == NULL) {
                printf("Memory allocation failed!");
                return -1;
            }
            source -> edges -> next = NULL;
            source -> edges -> weight = weight;
            source -> edges -> endpoint = dest;
        }
        else {
            pedge e = source -> edges;
            while (e -> next != NULL) {
                e = e -> next;
            }
            e -> next = (pedge) malloc(sizeof (edge));
            if (e -> next == NULL) {
                printf("Memory allocation failed!");
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
    }
}

void delete_incoming_edges (pnode* head, pnode dest) {
    pnode temp = *head;
    while (temp != NULL) {
        if (temp == dest) {
            temp = temp -> next;
        }
        pedge p = temp -> edges;
        while (p != NULL) {
            if (p -> endpoint == dest) {
                pedge p1 = p;
                p = p -> next;
                free(p1);
                break;
            }
        }
        temp = temp -> next;
    }
}

// --------------------------- Nodes Methods ---------------------------

int total_nodes (pnode *head) {
    int totalNodes = 0;
    pnode temp = *head;
    while (temp != NULL) {
        totalNodes++;
        temp = temp -> next;
    }
    return totalNodes;
}

pnode search_node (pnode *head, int vertexNum) {
    pnode temp = *head;
    while (temp != NULL) {
        if (temp -> node_num == vertexNum) {
            return temp;
        }
            temp = temp -> next;
    }
    return NULL;
}
