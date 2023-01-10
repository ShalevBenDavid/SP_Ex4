#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct GRAPH {
    int total_nodes;
    int total_edges;
    pnode head_node;
    pedge head_edge;
} graph, *pgraph;

void build_graph_cmd(pnode *head, int);
void insert_node_cmd(pnode *head, int);
void delete_node_cmd(pnode *head, int);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head, int, int);
void TSP_cmd(pnode head, int);

#endif