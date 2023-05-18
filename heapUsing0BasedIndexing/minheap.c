#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "minheap.h"

#define PARENT (i-1)/2
#define SIZE tnode -> size
#define ARR tnode -> arr
void initMinHeap(minHeap* tnode){
    tnode -> size = 0;
    // tnode -> arr = NULL;
    tnode -> arr = (int*)malloc(sizeof(int)*100);

}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(minHeap* tnode){
    int i = SIZE-1 ;
    while(i > 0){
        if(ARR[i] > ARR[(i-1)/2]){
        // printf("SIZ");
            swap(&ARR[i],&ARR[(i-1)/2]);
        }
        i = (i-1)/2;
    }
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

void heapSort(minHeap* tnode){
    for(int i = SIZE-1 ; i >= (SIZE+1)/2 ; i--){
    // printf("SIZE");
        heapify(tnode);
    }
}

int PopNode(minHeap* tnode){
    if(tnode -> size == 0)
        return INT_MIN;
    
    int tempAns = tnode -> arr[0];
    tnode -> arr[0] = tnode -> arr[tnode -> size-1];
    SIZE--;
    int i = 0;
    while(i < (SIZE+1)/2){
        printf("Iterations \n");
        int leftIndex = i*2+1;
        int rightIndex = i*2 + 2;
        int temp = i;
        if(leftIndex < SIZE && tnode -> arr[i] < tnode -> arr[leftIndex]){
            i = leftIndex;
        }
        if(rightIndex < SIZE && tnode -> arr[i] < tnode -> arr[rightIndex]){
            i = rightIndex;
        }
        if(i != temp){
        swap(&tnode -> arr[temp] , &tnode -> arr[i]);
        }
        else{
            i++;
        }
            // return tempAns;
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
