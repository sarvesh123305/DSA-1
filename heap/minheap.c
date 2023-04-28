#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "minheap.h"

//1st node is not used it is kept aas INT_MIN;
void initMinHeap(minHeap* tnode){
    tnode -> size = 0;
    tnode -> arr = (int*)malloc(sizeof(int));
    tnode -> arr[0] = INT_MIN;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(minHeap* tnode,int data){
  
    tnode -> size =  tnode -> size + 1;
    tnode -> arr = (int *) realloc(tnode -> arr,sizeof(int)*(tnode -> size+1));
    tnode -> arr[tnode -> size] = data;

    int i = tnode -> size ;
    while( i > 1){
        if(tnode -> arr[i] > tnode -> arr[i/2])
        {
            swap(&tnode -> arr[i],&tnode -> arr[i/2]);
            i = i/2;
        }
        else
            return;
    }
}

int PopNode(minHeap* tnode){
    if(tnode -> size == 0)
        return INT_MIN;
    
    int tempAns = tnode -> arr[1];
    tnode -> arr[1] = tnode -> arr[tnode -> size];
    tnode -> size--;
    int i = 1;
    while(i < tnode -> size){
        int leftIndex = i*2;
        int rightIndex = i*2 + 1;
        int temp = i;
        if(tnode -> arr[i] < tnode -> arr[leftIndex]){
            i = leftIndex;
        }
        if(tnode -> arr[i] < tnode -> arr[rightIndex]){
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
    printf("\n");
    for(int i = 1 ; i <= tnode.size ;i++){
        printf("%d ",tnode.arr[i]);
    }
    printf("\n");
}