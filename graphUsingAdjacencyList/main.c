#include<stdio.h>
#include "graph.h"
#include<stdlib.h>
int main(int arg,char* argv[]){
    Graph g ;
    initGraph(&g,argv[1]);
    BFS(g,0);
    printf("\n");
    DFS(g,0);
    // displayGraph(g);
    // SpanningTree t = primsAlgorithm(g,0);
    // printSpanningTree(t,g);
    // SpanningTree t1 = kruskalsAlgorithm(g);
    // printSpanningTree(t1,g);
    // dijestra(g,5);
    
}