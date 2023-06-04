#include<stdio.h>
#include "graph.h"

int main(int arg,char* argv[]){
    Graph g ;
    initGraph(&g,argv[1]);
    // BFS(g,0);
    // DFS(g,0);
    // displayGraph(g);
    // primsAlgorithm(g,0);
    // kruskalsAlgorithm(g);
    dijestra(g,5);
    
}