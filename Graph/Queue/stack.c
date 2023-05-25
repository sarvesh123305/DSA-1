#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

typedef stack stack;

void initStack(stack *s,int size){
    s -> size = size;
    s -> top = -1;
    s -> arr = (int*)malloc(sizeof(int)*size);
}
int isEmpty(stack s){
    // printf("\nEmpty\n");

    return s.top == -1;
}

int isFull(stack s){
    // printf("\nFull Fucked UP\n");
    return s.top == s.size-1;
}
void push(stack *s,int data){
   if(isFull(*s)){
    return ;
   }
   
    s -> top++;
    s -> arr[s -> top] = data;
}
int pop(stack *s){
    if(isEmpty(*s))
    return -1;

    int element = s -> arr[s -> top];
    s -> arr[s -> top] = -1;
    s -> top--;
    return element;
}
void display(stack s){
    if(isEmpty(s))
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
int main(){
    stack s;
    initStack(&s,5);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);


    display(s);
    printf("\n");

    deleteLastElement(&s);
    printf("\n");
    display(s);
}
