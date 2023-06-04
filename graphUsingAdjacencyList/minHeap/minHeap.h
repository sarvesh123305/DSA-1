#include<stdio.h>

typedef struct Data{
    int start;
    int end;
    int weight;
}Data;

typedef struct minHeap{
    int rear ;
    int size ;
    Data *arr;
}minHeap;

void initminHeap(minHeap* ,int );
void insert(minHeap* ,int,int ,int );
Data popNode(minHeap*);
