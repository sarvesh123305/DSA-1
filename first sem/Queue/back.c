#include<stdio.h>
#include "back.h"
#include<stdlib.h>
void initList(Queue* q){
    q -> front = NULL;
    q -> rear = NULL;

}
int isEmpty(Queue q){
    return q.front == NULL ||  q.rear == NULL;
}
void display(Queue q){
    if(isEmpty(q))
    return ;
printf("\n");
    while( q.front  ){
        printf("%d\t",q.front -> data );
        q.front = (q.front -> next );

    }
printf("\n");

}

void enqueue(Queue* q,int data){
    node* newnode = (node*) malloc(sizeof(node));
    if(!newnode)
    return;
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if(isEmpty(*q)){
        q -> front = q -> rear = newnode;
    }
    else{
        q -> rear -> next = newnode;
        q -> rear = newnode;
    }
}
int dequeue(Queue* q){
    if(isEmpty(*q))
    return 0;

    int element = q -> front -> data;
    node* ab = q -> front;
    q -> front =  q -> front -> next;
    free(ab);
    return element;
}
