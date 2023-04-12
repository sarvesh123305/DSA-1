#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

void initTree(Tree* tree){
    (*tree) = NULL;
}

void initStack(Stack *s){
    (*s) = NULL;
    return;
}
void pushS(Stack* s,Tree t){
    snode* newnode = (snode*)malloc(sizeof(snode));
    newnode -> next = NULL;
    newnode -> data = t;

    // printf("\nData %d",newnode->data-> data);
    if(isEmpty(*s)){
        *s = newnode;  
        return ;  
    }
    else{
        newnode -> next = *s ;
        *s = newnode;
    }
}
void displayStack(Stack s){
    snode* temp = s;
    printf("\n");
    while(temp){
        printf("%d ",temp -> data -> data);
        temp = temp -> next;
    }
    printf("\n");
    return ;
}
snode* pop(Stack* s){
    snode* deleteNode;
        // printf("%d ",s -> top -> data -> data);

    if(isEmpty(*s)){
        // printf("dar");
        return NULL;
    }
    else{
        deleteNode = *s;
        (*s)  = (*s) -> next;
    }
    // free(deleteNode);
    return deleteNode;
}
int isEmpty(Stack s){
    return ( s == NULL);
}