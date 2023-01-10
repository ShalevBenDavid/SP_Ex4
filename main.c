// Created by Shalev Ben David.
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    char c = 0;
    graph G = {0,0, NULL, NULL};
    pgraph G_ptr = &G;
    while ((c = (char) getchar()) != EOF) {
        switch (c) {
            case 'A': {
                int numOfVertexes = 0;
                scanf(" %d", &numOfVertexes);
                if (G_ptr->total_nodes != 0)
                    deleteGraph_cmd(&(G_ptr -> head_node));
                build_graph_cmd(&(G_ptr -> head_node), numOfVertexes);
                break;
            }
            case 'B': {
                int vertexNum = 0;
                scanf(" %d", &vertexNum);
                insert_node_cmd(&(G_ptr -> head_node), vertexNum);
                break;
            }
            case 'D': {
                int vertexToDelete = 0;
                scanf(" %d", &vertexToDelete);
                delete_node_cmd(&(G_ptr -> head_node), vertexToDelete);
                break;
            }
            case 'S': {
                int srcV = 0;
                int destV = 0;
                scanf(" %d %d", &srcV, &destV);
                shortsPath_cmd(G_ptr -> head_node, srcV, destV);
            }
            case 'T': {
                int k = 0;
                scanf(" %d", &k);
                TSP_cmd(G_ptr -> head_node, k);
            }
            case 'G': { // Print graph.
                printGraph_cmd(G_ptr -> head_node);
            }
            default:
                printf("Please Enter A/B/C/D/S/T");
                break;
        }
    }

}

