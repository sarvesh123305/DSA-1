#include<stdio.h>

typedef struct graph{
    int **A;
    int size;
}graph;

void initGraph(graph*);
void BFS(graph g,int s);

void display(graph);