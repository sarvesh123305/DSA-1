#include<stdio.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;
typedef struct Queue{
    struct node* front;
    struct node* rear;

}Queue;

typedef Queue Queue;

void initQueue(Queue*);
int isEmpty(Queue);
void enqueue(Queue*,int);
int dequeue(Queue*);
void displayQueue(Queue);
