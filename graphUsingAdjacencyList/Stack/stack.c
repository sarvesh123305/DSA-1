#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

void initStack(stack *s,int size){
    s -> size = size;
    s -> top = -1;
    s -> arr = (int*)malloc(sizeof(int)*size);
}
int isEmptyStack(stack s){
    
    return s.top == -1;
}

int isFullStack(stack s){
    // printf("\nFull Fucked UP\n");
    return s.top == s.size-1;
}
void push(stack *s,int data){
   if(isFullStack(*s)){
    return ;
   }
   
    s -> top++;
    s -> arr[s -> top] = data;
}
int pop(stack *s){
    if(isEmptyStack(*s))
    return -1;

    int element = s -> arr[s -> top];
    s -> arr[s -> top] = -1;
    s -> top--;
    return element;
}
void display(stack s){
    if(isEmptyStack(s))
    return;
    for(int i = s.top ; i >= 0;i--){
        printf("%d\t",s.arr[i]);
    }
}

void deleteLastElement(stack *s){
        stack s1 = *s;
    if(s -> top == 0){
    printf("%d",s -> arr[s -> top]);

        pop(&s1);
        return ;
    }
    int element = s -> arr[s -> top];
        pop(&s1);
     deleteLastElement(&s1);
    push(&s1,element);
}

