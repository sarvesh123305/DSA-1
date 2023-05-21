#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "maxHeap.h"

#define PARENT (i-1)/2
#define SIZE tnode -> size
#define REAR tnode -> rear

#define ARR tnode -> arr
void initmaxHeap(maxHeap* tnode,int size){
    if(tnode -> size == 0)
    return;
    tnode -> size = size;
    tnode -> arr = (int*)malloc(sizeof(int)*size);
    tnode -> rear = -1;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(maxHeap* tnode){
    int i = SIZE-1 ;
    while(i > 0){
        if(ARR[i] > ARR[(i-1)/2]){
            swap(&ARR[i],&ARR[(i-1)/2]);
        }
        i = (i-1)/2;
    }
}
void insert(maxHeap* tnode,int data){
  
    tnode -> rear += 1;
    if(tnode -> rear == tnode -> size){
        tnode -> arr = (int *) realloc(tnode -> arr,sizeof(int)*(tnode -> size*2));
        tnode -> size *= 2;
    }
    
    tnode -> arr[tnode -> rear] = data;

    int i = tnode -> rear ;

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

void heapSortAscending(maxHeap* tnode){
    int count = REAR;
    int temp;
    while (REAR > 0)
    {
        temp = popNode(tnode);
        ARR[REAR+1] = temp;
    }
    
    REAR = count;
}

void heapSortDescending(maxHeap* tnode){
    for(int i = 0 ; i <= REAR/2; i++){
        swap(&ARR[i] ,&ARR[REAR-i]);
    }
}

int popNode(maxHeap* tnode){
    if(tnode -> rear == -1)
        return INT_MIN;
    
    int tempAns = tnode -> arr[0];
    tnode -> arr[0] = tnode -> arr[REAR];

    REAR -= 1 ;

    int i = 0;

    while(i < (REAR+1)/2){

        int leftIndex = i*2+1;
        int rightIndex = i*2 + 2;
        int temp = i;
        if(leftIndex <= REAR && tnode -> arr[i] < tnode -> arr[leftIndex])
            i = leftIndex;
        if(rightIndex <= REAR && tnode -> arr[i] < tnode -> arr[rightIndex])
            i = rightIndex;

        if(i != temp){
        swap(&tnode -> arr[temp] , &tnode -> arr[i]);
        }
        else{
            i++;
        }
    } 
    return tempAns;
}
void display(maxHeap tnode){
    printf("\n ");
    for(int i = 0 ; i <= tnode.rear ;i++){
        printf("%d ",tnode.arr[i]);
    }
    printf("\n");
}
