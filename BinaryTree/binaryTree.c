#include<stdlib.h>
#include<stdio.h>

#include "binaryTree.h"
#include "../../genericQueue/queue.h"
void initBinaryTree(BT* tNode) {
     *tNode = NULL;
     return ;
}


int randomNumberGenerator(int upperLimit,int lowerLimit){
return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit ;
}
void initFileWithRandomNumbers( char filename[] ,int upperLimit,int lowerLimit,int limit){
      FILE *fptr;
    fptr = fopen(filename,"w");
    
    if(!fptr){
        printf("Failed to Open the file");
        return ;
    }

    for (int i = 0; i < limit; i++) {
       
        int num = randomNumberGenerator(upperLimit,lowerLimit);
         fprintf(fptr, "%d %s",  num," ");
    }
    fclose(fptr);

}

void preOrderBT(BT tNode){
    if(!tNode)
    return;

    printf("%d ",tNode -> data);
    preOrderBT(tNode -> left);
    preOrderBT(tNode -> right);

}


void insertIntoTree(BT* tNode,int data){

        if(!(*tNode)){
                NodeBT* newnode = (NodeBT*)malloc(sizeof(NodeBT));
                newnode -> data = data;
                newnode -> left = NULL;
                newnode -> right = NULL;
                *tNode = newnode;
                return;
        }

        int randomNo = randomNumberGenerator(1000,100);
        if((randomNo % 2) == 0){ // Even number found so go to left
                // if((!(*tNode) -> right) && (!(*tNode) -> left)){
                    // insertIntoTree(&(*tNode) -> left,data);
                // }
                // else{
                    insertIntoTree(&(*tNode) -> left,data);
                // }
        }                    // else go to right
        else if(randomNo % 2 == 1){
            // if(!(*tNode) -> left){
                    // return;
                // }
                // else{
                    insertIntoTree(&(*tNode) -> right,data);
                // }
        }
}


int levelOrderSearch(BT tnode,int key){
    if(!tnode)
    return 0;
    
    Queue q;

    initQueue(&q, sizeof(BT));
    BT temp = tnode;

    enqueue(&q,&temp);
    // printf("\n");
    int ct = 0;

    while(getQueueSize(&q) > 0){
        BT temporary = NULL;
        dequeue(&q,&temporary);

        ct++;
        if(temporary -> data == key){
            return ct;
        }
        if(temporary -> left){
                enqueue(&q,&(temporary -> left));
        }
        if(temporary -> right)
                enqueue(&q,&(temporary -> right));

    }
    return ct;
}




void helpInsertingIntoTree(BT *tNode,char filename[],int limit,int upperLimit,int lowerLimit){
    FILE *fptr;
    fptr = fopen(filename,"r");
    
    if(!fptr){
        printf("Failed to Open the file");
    }
           int i = 0;
        
        while (fscanf(fptr,"%d",&i))
        {
                if(feof(fptr))
                break;

                int data = randomNumberGenerator(upperLimit,lowerLimit);
                insertIntoTree(tNode,data);
        }
        
}
int count = 0;
int flag = 1;
int searchInBinaryTree(BT tNode,int key,int *ct){
    if(!tNode)
        return 0;

    // *ct = *ct + 1;
    if(flag)
    count = count + 1;

    if(tNode -> data == key){
        flag = 1;
        // printf()
        return count;
    }


    return searchInBinaryTree(tNode -> left ,key,&(*ct)) || searchInBinaryTree(tNode -> right,key,&(*ct));
}













