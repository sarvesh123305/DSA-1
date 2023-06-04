#include<stdio.h>
#include "graph.h"

int main(){
    graph g;
    initGraph(&g);
    // printf("\nPrint BFS of a graph\n\n");
    // BFS(g,1);
    // printf("\n");
    // degreeOfEachVertex(g);
    // printf("Is the graph connceted : %d",isGraphConnected(g));
    // printf("\nIs adjacent : %d",isAdjcantToAnother(g,1,2));
    // printCyclesInGraph(g,0);
    printf("\nNumber of Components of a graph : %d ", numberOfComponentsInAGraph(g));

    return 0;
}