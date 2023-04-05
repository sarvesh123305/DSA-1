#include<stdio.h>


// Node* ; next;
typedef struct Node {
     int data;
    struct Node* next;
}Node;

typedef struct LinkedList {
    Node* data;
    // int data;
    struct LinkedList* next;
}LinkedList;

typedef LinkedList* List;

typedef struct Queue{
    List front,rear;
}Queue;

/*

front 1 -> 2 -> 3
      1 -> 2 -> 3
rear  1 -> 2 -> 3

*/




void initQueue(Queue* q);
void enqueue(Queue *q,Node* data);
Node* dequeue(Queue* q);
void display(Queue q);

















