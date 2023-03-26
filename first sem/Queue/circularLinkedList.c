#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
        int data;
        struct Node* next;
}Node;

typedef Node* List;


void initList(List* l){
    *l = NULL;
    return ;
}

void insertAtTail(List* l,int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    
    if(!newnode)
    return ;

    newnode -> data = data;
    newnode -> next = NULL;

    if(!(*l)){
        *l = newnode;
        // newnode -> next = newnode;
        return ;
    }

    Node* temp = *l;
    Node* head = *l;
    while(temp -> next != head){
        temp = temp -> next;
    }
    temp -> next = newnode ;
    newnode -> next = head;

}

void display(List l){
    Node* head = l;
    do {
        printf("%d\t",l -> data);
        l = l -> next;
    }
    while(l != head);
   
}

int deleteAtPosition(List*l,int position){

    if(!(*l))
    return -1;

    int ct = 0 ;

    Node* temp = *l;
    Node* prev = NULL;
    
    while( ct != position - 1){
        if(temp->next == (*l))
            return -1;
        prev = temp;
        temp = temp -> next;
        ct++;
    }
    Node* freeNode = temp;
    int element = temp -> data;
    prev -> next = temp -> next;
    freeNode -> next = NULL;
    free(freeNode);

    return element;
}



int main(){
    List L;
    initList(&L);
    insertAtTail(&L,10);
    insertAtTail(&L,20);
    insertAtTail(&L,30);
    insertAtTail(&L,30);


    deleteAtPosition(&L,5000);
    display(L);
    return 0;
}