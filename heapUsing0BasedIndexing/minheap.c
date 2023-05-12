#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "minheap.h"

#define PARENT (i-1)/2
void initMinHeap(minHeap* tnode){
    tnode -> size = 0;
    tnode -> arr = NULL;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(minHeap* tnode,int data){
  
    tnode -> arr = (int *) realloc(tnode -> arr,sizeof(int)*(tnode -> size+1));
    tnode -> arr[tnode -> size] = data;

    int i = tnode -> size ;
    tnode -> size =  tnode -> size + 1;

    while( i > 0){
        if(tnode -> arr[i] > tnode -> arr[PARENT])
        {
            swap(&tnode -> arr[i],&tnode -> arr[PARENT]);
            i = PARENT;
        }
        else
            return;
    }
}

int PopNode(minHeap* tnode){
    if(tnode -> size == 0)
        return INT_MIN;
    
    int tempAns = tnode -> arr[0];
    tnode -> arr[0] = tnode -> arr[tnode -> size-1];
    tnode -> size--;
    int i = 0;
    while(i < tnode -> size){
        int leftIndex = i*2+1;
        int rightIndex = i*2 + 2;
        int temp = i;
        if(leftIndex < tnode -> size && tnode -> arr[i] < tnode -> arr[leftIndex]){
            i = leftIndex;
        }
        if(rightIndex < tnode -> size && tnode -> arr[i] < tnode -> arr[rightIndex]){
            i = rightIndex;
        }
        if(i != temp){
        swap(&tnode -> arr[temp] , &tnode -> arr[i]);
        }
            return tempAns;
    } 
    return tempAns;
}
void display(minHeap tnode){
    printf("\n ");
    for(int i = 0 ; i < tnode.size ;i++){
        printf("%d ",tnode.arr[i]);
    }
    printf("\n");
}
