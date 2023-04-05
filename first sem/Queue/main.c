#include<stdio.h>
#include "back.h"

int main(){
    Queue q;
    initList(&q);
    enqueue(&q,10);
// display(q);

    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    // dequeue(&q);
display(q);
    dequeue(&q);
display(q);

    dequeue(&q);
display(q);

    dequeue(&q);
display(q);

    dequeue(&q);
display(q);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);


    return 0;
}