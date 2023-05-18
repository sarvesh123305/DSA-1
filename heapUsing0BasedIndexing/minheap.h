#include<stdio.h>


typedef struct minHeap{
    int size ;
    int *arr;
}minHeap;

void initMinHeap(minHeap* tnode);
void insert(minHeap* tnode,int data);
int PopNode(minHeap* tnode);
void display(minHeap tnode);
void heapSort(minHeap* tnode);