// Created by Shalev Ben David.
# include "graph.h"

#ifndef SP_EX4_EDGES_H
#define SP_EX4_EDGES_H

int create_edge(pnode*, int, int, int);
int total_edges (pedge);
void delete_node_edges (pnode);
void delete_incoming_edges (pnode*, pnode );

#endif //SP_EX4_EDGES_H
