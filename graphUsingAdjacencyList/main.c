#include<stdio.h>
#include "graph.h"

int main(){
    Graph g ;
    initGraph(&g);
    // displayGraph(g);
    // BFS(g,0);
    // DFS(g,0);
    primsAlgorithm(g,0);

}