#include<stdio.h>
#include "maxHeap.h"
int main(){
    maxHeap tnode;
    initmaxHeap(&tnode,5);
    insert(&tnode,12);
    insert(&tnode,35);
    insert(&tnode,66);
    insert(&tnode,71);
    insert(&tnode,54);
    insert(&tnode,92);
    insert(&tnode,13);
    insert(&tnode,18);
    insert(&tnode,20);
    insert(&tnode,25);
    insert(&tnode,60);
    insert(&tnode,13);

    popNode(&tnode);
    popNode(&tnode);
    display(tnode);

    heapSortAscending(&tnode);
    display(tnode);

    heapSortDescending(&tnode);

   
    display(tnode);
}