#include "stack.h"

void initTree(Tree* tree){
    (*tree) = NULL;
}

void initStack(Stack *s){
    s -> top = NULL;
    return;
}
void pushS(Stack* s,Tree t){
    List newnode = (List)malloc(sizeof(LinkedList));
    newnode -> next = NULL;
    newnode -> data = t;
    if(isEmpty(*s)){
        s -> top = newnode;  
        return ;  
    }
    else{
        newnode -> next = s -> top;
        s -> top = newnode;
    }
    // printf("Data %d",s -> top -> data -> data);
}
void displayStack(Stack s){
    List temp = s.top;
    while(temp ){
        printf("%d ",temp -> data -> data);
        temp = temp -> next;
    }
    printf("\n");
    return ;
}
List pop(Stack* s){
    List deleteNode;
        // printf("%d ",s -> top -> data -> data);

    if(isEmpty(*s)){
        // printf("dar");
        return NULL;
    }
    else{
        deleteNode = s -> top;
        s -> top = s -> top -> next;
    }
    // free(deleteNode);
    return deleteNode;
}
int isEmpty(Stack s){
    return s.top == NULL;
}