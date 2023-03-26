#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
}Stack;

void initStack(Stack *s){
    s -> top = NULL;
}

int isEmpty(Stack s){
    return s.top == NULL;
}

void push(Stack *s,int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    return ;

    newnode -> data = data;
    newnode -> next = NULL;
    if(isEmpty(*s))
    {
        s -> top = newnode;
        return ;
    }
    newnode -> next = s -> top;
    s -> top = newnode;
}

int pop(Stack *s){
    if(isEmpty(*s))
    return -1;
    Node* freeNode = s -> top;
    int element = freeNode -> data;
    s -> top = s -> top -> next;
    free(freeNode);

    return element;
}

void display(Stack s){
    if(isEmpty(s))
    return ;
    while(s.top){
        printf("%d\t",s.top -> data);
        s.top = s.top -> next;
    }
    return ;
}

int main(){
    Stack s;
    initStack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    pop(&s);
    // pop(&s);
    // pop(&s);
    // pop(&s);
    display(s);
}