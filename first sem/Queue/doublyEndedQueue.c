#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    int *arr;
    int size;
    int start;
    int end;
}Node;

typedef Node Queue;

void initQueue(Queue* q,int size){
    (q) -> arr = (int*)malloc(sizeof(int)*size);
    (q) -> size = size;
    (q) -> start = -1;
    (q) -> end = -1 ;

    return ;
}

int isFull(Queue q){
    return (q.end == q.size - 1 ) ;
}
int isEmpty(Queue q){
    return q.start == -1;  
}
void push(Queue* q,int data){
   if(isFull(*q)){
    return ;
   }
   if(q -> start == -1){
    q -> start = 0 ;
    q -> end = 0 ;
   }
   (q) -> arr[(q) -> end] = data;
   (q) -> end++;

}
int top(Queue q)
{
    if(isEmpty(q))
    return -1;
    return q.arr[q.start];
}
void pop(Queue *q){
    if(isEmpty(*q)){
        return;
    }
   
    q -> arr[q -> start] = -1;
    q -> start++;

    if(q -> start >= q-> end )
    {
        q -> start = -1;
        q -> end = -1;
    }
}
int main(){
    Queue q;
    initQueue(&q,10);
    push(&q,10);
    // printf("\t%d\n",top(q));
     push(&q,20);
    // pop(&q);
    
    printf("\t%d\n",top(q));

   
    return 0;
}