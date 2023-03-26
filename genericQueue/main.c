#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct code{
    int data;
    struct code* next;
}code;

typedef code*  list;
void display(code* node){
    printf("\n");
    while(node){
        printf("%d",node -> data);
        node = node -> next;
    }
}

int main()
{
    code* element1 = (code*)malloc(sizeof(code));
    element1 -> data = 1;
    element1 -> next = NULL;

code* element2 = (code*)malloc(sizeof(code));
    element2 -> data = 0;
    element2 -> next = element1;
    
    code* val = (code*)malloc(sizeof(code));
    val -> data = 1;
    val -> next = element2;
    


    Queue q;
    
    initQueue(&q, sizeof(code));
char a;

    for(int i = 0; i < 10; i++)
    {
        //  a = 'a'+val;
        enqueue(&q, &val);
        display(val);
        // printf("The value %c has been enqueued.\n", );
    }

    printf("\n");

    queuePeek(&q, &val);

display(val);
val = NULL;
    // printf("The value that is at the front of the queue is %c\n\n", a);

    while(getQueueSize(&q) > 0)
    {
         dequeue(&q,&val);
        display(val);
    
    }

    return 0;
}