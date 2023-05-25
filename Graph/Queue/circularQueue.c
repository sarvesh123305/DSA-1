#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    struct Node* front;
    struct Node* rear;
} Queue;


void initQueue(Queue* q){
    q -> front = NULL;
    q -> rear = NULL;
}

int isEmpty(Queue q){
    return (q.front == NULL || q.rear == NULL);
}

void enqueue(Queue *q,int data){
     Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    return ;

    newnode -> data = data;
    newnode -> next = NULL;

   if(isEmpty(*q)){ 
        q -> front = newnode;
        q -> rear = newnode;
        q -> rear -> next = q -> front;
   }
    q -> rear -> next = newnode;
    q -> rear = newnode;
    q -> rear -> next = q -> front;

}

void dequeue(Queue *q){
    if(isEmpty(*q))
    return ;
    Node* deleteNode = q -> front;
    if(q -> front == q -> rear){
        q -> front = NULL;
        q -> rear = NULL;
    }
    else{
    q -> front = q -> front -> next;
    }
    free(deleteNode);

}
int peek(Queue q){
    if(isEmpty(q))
    return -1;
    return q.front-> data;
}

void display(Queue q){
    Node* start = q.front;
    while(start != q.rear){
        printf("%d\t",start -> data);
        start = start -> next;
    }
}
int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
    // dequeue(&q);
display(q);
    // printf("%d",peek(q));
}

