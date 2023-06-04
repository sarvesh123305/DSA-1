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

void initGraph(Graph*,char*);
void displayGraph(Graph);
void BFS(Graph,int);
void DFS(Graph ,int);
void primsAlgorithm(Graph ,int);
void kruskalsAlgorithm(Graph );
