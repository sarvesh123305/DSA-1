#include<stdio.h>
#include "minheap.h"
int main(){
    minHeap tnode;
    initMinHeap(&tnode);
    insert(&tnode,10);
    insert(&tnode,20);
    insert(&tnode,30);
    insert(&tnode,40);
    insert(&tnode,50);
    insert(&tnode,60);
    display(tnode);
    printf("\nPopNode = %d",PopNode(&tnode));
    display(tnode);
    display(tnode);
}