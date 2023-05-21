#include<stdio.h>


typedef struct maxHeap{
    int rear ;
    int size ;
    int *arr;
}maxHeap;

void initmaxHeap(maxHeap* tnode,int size);
void insert(maxHeap* tnode,int data);
int popNode(maxHeap* tnode);
void display(maxHeap tnode);
void heapSortAscending(maxHeap* tnode);
void heapSortDescending(maxHeap* tnode);
