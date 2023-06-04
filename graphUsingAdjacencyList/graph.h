#include<stdio.h>

typedef struct Node{
    int weight;
    int index;

    struct Node* next;
}Node;

typedef Node* List;

typedef struct graph{
    int size;
    List* column;
}graph;

typedef graph Graph;

void initGraph(Graph*);
void displayGraph(Graph);
void BFS(Graph,int);
void DFS(Graph g,int v);
void primsAlgorithm(Graph g,int v);
