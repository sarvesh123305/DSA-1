#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Queue{
    Node* front ;
    Node* rear ;
}Queue;

void initQueue(Queue* q){
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(Queue q){
    return q.front == NULL;
}
void enqueue(Queue*q , int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode){
        return ;
    }
    newnode -> data = data;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if(isEmpty(*q)){
        q -> front = newnode ;
        q -> rear = newnode;
        return ;
    }
    newnode -> prev = q -> rear;
    q -> rear -> next = newnode;
    q -> rear = newnode;
}

int dequeue(Queue *q){
    if(isEmpty(*q)){
        return -1;
    }

    Node* freeNode = q -> front;
    if(q -> front == q -> rear){
        q -> front = NULL;
        q -> rear = NULL;
    }
    else{
        q -> front = q -> front -> next;
    }
    free(freeNode);
    return freeNode -> data;

}

void display(Queue q){
    printf("\n");
    
    while(q.front){
        printf("%d\t",q.front -> data);
        q.front = q.front -> next;
    }

    printf("\n");
}
int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,30);
    enqueue(&q,30);
    enqueue(&q,30);
        
    display(q);

}