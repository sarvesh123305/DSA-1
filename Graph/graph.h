#include<stdio.h>

typedef struct graph{
    int **A;
    int size;
}graph;

void initGraph(graph*);
void BFS(graph,int);
void degreeOfEachVertex(graph);
int isGraphConnected(graph);
int isAdjcantToAnother(graph,int,int);
void display(graph);
void printCyclesInGraph(graph,int);
int numberOfComponentsInAGraph(graph);