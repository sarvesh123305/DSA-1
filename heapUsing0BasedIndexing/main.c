#include<stdio.h>
#include "minheap.h"
int main(){
    minHeap tnode;
    initMinHeap(&tnode);
    // insert(&tnode,12);
    // insert(&tnode,35);
    // insert(&tnode,66);
    // insert(&tnode,71);
    // insert(&tnode,54);
    // insert(&tnode,92);
    // insert(&tnode,13);
    // insert(&tnode,18);
    // insert(&tnode,20);
    // insert(&tnode,25);
    // insert(&tnode,60);
    // insert(&tnode,13);
    tnode.arr[0] = 15;
    tnode.arr[1] = 35;
    tnode.arr[2] = 5;
    tnode.arr[3] = 2;
    tnode.arr[4] = -15;
    tnode.arr[5] = 95;


    tnode.size = 6;
    display(tnode);

    heapSort(&tnode);
    // display(tnode);
    // printf("\nPopNode = %d",PopNode(&tnode));
    // display(tnode);
    display(tnode);
}