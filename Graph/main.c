#include<stdio.h>
#include "graph.h"

int main(){
    graph g;
    initGraph(&g);
    // display(g);
    BFS(g,1);
    return 0;
}