#include<stdio.h>
#include "queue.h"

#include<stdlib.h>
#include<limits.h>


void initQueue(Queue* q){
    q -> front = NULL;
    q -> rear = NULL;
}

void enqueue(Queue *q,Node* data){
    List newnode = (List)malloc(sizeof(LinkedList));
    newnode -> data = data;
    newnode -> next = NULL;
    if(!q-> front){
        q -> front = q -> rear = newnode;
        return;
    }

    q -> rear -> next = newnode;
    q -> rear = newnode;

}
Node* dequeue(Queue* q){
    if(!q -> front){
        // return INT_MIN;
        return NULL;
    }
    List deleteNode = q -> front;
    if(q -> front == q -> rear){
        q -> front = q -> rear = NULL;
    }
    else{
        q -> front = q -> front -> next;
    }
    Node* data = deleteNode -> data;
    // while(deleteNode){
        // deleteNode = deleteNode -> next;
    // }
    // free(deleteNode);
    return data;
}
void display(Queue q){
    if(!q.front){
        printf("Empty");
        return;
    }
    while(q.front){
    Node* data = q.front -> data;
    printf("\n");
        while(data){
            printf("%d\t",data ->data );
            data = data -> next;
        }
        q.front = q.front -> next;
    }
    printf("\n");

}
















