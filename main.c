// Created by Shalev Ben David.
#include <stdio.h>
#include "graph.h"

int main() {
    char c;
    pnode head = NULL;
    pnode *head_ptr = &head;
    while ((scanf(" %c", &c) == 1) && c != EOF) {
        switch (c) {
            case 'A': {
                int numOfVertexes = 0;
                scanf(" %d", &numOfVertexes);
                deleteGraph_cmd(head_ptr);
                build_graph_cmd(head_ptr, numOfVertexes);
                break;
            }
            case 'B': {
                int vertexNum = 0;
                scanf(" %d", &vertexNum);
                insert_node_cmd(head_ptr, vertexNum);
                break;
            }
            case 'D': {
                int vertexToDelete = 0;
                scanf(" %d", &vertexToDelete);
                delete_node_cmd(head_ptr, vertexToDelete);
                break;
            }
            case 'S': {
                int srcV = 0;
                int destV = 0;
                scanf(" %d %d", &srcV, &destV);
                shortsPath_cmd(head, srcV, destV);
                break;
            }
            case 'T': {
                int k = 0;
                scanf(" %d", &k);
                TSP_cmd(head, k);
                break;
            }
            case 'G': {
                printGraph_cmd(head);
                break;
            }
            default: {
                printf("Please Enter A/B/C/D/S/T\n");
                break;
            }
        }
    }
    deleteGraph_cmd(&head);
    return 0;
}