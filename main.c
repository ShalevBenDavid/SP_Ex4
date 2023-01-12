// Created by Shalev Ben David.
#include <stdio.h>
#include "graph.h"

int main() {
    char c;
    pnode head = NULL;
    pnode* head_ptr = &head;
    c = (char) getchar();
    while (c != EOF) {
        switch (c) {
            case 'A': {
                int numOfVertexes = 0;
                scanf(" %d", &numOfVertexes);
                if (head -> edges != NULL)
                    deleteGraph_cmd(head_ptr);
                c = build_graph_cmd(head_ptr, numOfVertexes);
                break;
            }
            case 'B': {
                int vertexNum = 0;
                scanf(" %d", &vertexNum);
                insert_node_cmd(head_ptr, vertexNum);
                scanf(" %c", &c);
                break;
            }
            case 'D': {
                int vertexToDelete = 0;
                scanf(" %d", &vertexToDelete);
                delete_node_cmd(head_ptr, vertexToDelete);
                scanf(" %c", &c);
                break;
            }
            case 'S': {
                int srcV = 0;
                int destV = 0;
                scanf(" %d %d", &srcV, &destV);
                shortsPath_cmd(head, srcV, destV);
                scanf(" %c", &c);
            }
            case 'T': {
                int k = 0;
                scanf(" %d", &k);
                TSP_cmd(head, k);
                scanf(" %c", &c);
            }
            case 'G': {
                printGraph_cmd(head);
                scanf(" %c", &c);
            }
            default:
                printf("Please Enter A/B/C/D/S/T");
                break;
        }
    }

}

