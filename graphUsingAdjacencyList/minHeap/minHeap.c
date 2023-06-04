#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "minHeap.h"

#define PARENT (i-1)/2
#define SIZE tnode -> size
#define REAR tnode -> rear
#define ARR tnode -> arr 

void initminHeap(minHeap* tnode,int size){
    if(tnode -> size == 0)
    return;
    tnode -> size = size;
    tnode -> arr = (Data*)malloc(sizeof(Data)*size);
    tnode -> rear = -1;
}

void swap(Data *a,Data *b){
    Data temp = *a;
    *a = *b;
    *b = temp;
   return; 
} 

void insert(minHeap* tnode,int start,int end,int weight){
    Data data;
    data.start = start;
    data.end = end;
    data.weight = weight;

    tnode -> rear += 1;
    if(tnode -> rear == tnode -> size){
        tnode -> arr = (Data *) realloc(tnode -> arr,sizeof(Data)*(tnode -> size*2));
        tnode -> size *= 2;
    }
    
    tnode -> arr[tnode -> rear] = data;

    int i = tnode -> rear ;

    while( i > 0){
        if(tnode -> arr[i].weight < tnode -> arr[PARENT].weight)
        {
            swap(&tnode -> arr[i],&tnode -> arr[PARENT]);
            i = PARENT;
        }
        else
            return;
    }
}

void displayHeap(minHeap tnode){
    for(int i = 0 ;  i <= tnode.rear; i++){
        printf("Weight : %d\t",tnode.arr[i].weight);
    }
}

Data popNode(minHeap* tnode){
    Data tempAns;
    tempAns.weight = INT_MIN;
    if(tnode -> rear == -1)
        return tempAns;
    
    tempAns = tnode -> arr[0];
    tnode -> arr[0] = tnode -> arr[REAR];

    REAR -= 1 ;

    int i = 0;

    while(i < (REAR+1)/2){

        int leftIndex = i*2+1;
        int rightIndex = i*2 + 2;
        int temp = i;
        if(leftIndex <= REAR && tnode -> arr[i].weight > tnode -> arr[leftIndex].weight)
            i = leftIndex;
        if(rightIndex <= REAR && tnode -> arr[i].weight > tnode -> arr[rightIndex].weight)
            i = rightIndex;

        if(i != temp)
            swap(&tnode -> arr[temp] , &tnode -> arr[i]);
        else
            i++;
        
    } 
    return tempAns;
}
