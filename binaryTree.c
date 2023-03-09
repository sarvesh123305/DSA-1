#include "binaryTree.h"
#include<stdlib.h>
#include<stdio.h>

void initTree(BT* tNode) {
     *tNode = NULL;
     return ;
}



int randomNumberGenerator(int upperLimit,int lowerLimit){
return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit ;
}
void initFileWithRandomNumbers( char filename[] ,int upperLimit,int lowerLimit,int limit){
     
     printf("\n");
      FILE *fptr;
    fptr = fopen("file1.txt","w");
    
    if(!fptr){
        printf("Failed to Open the file");
        return ;
    }

    for (int i = 0; i < limit; i++) {
       
        int num = randomNumberGenerator(upperLimit,lowerLimit);
         fprintf(fptr, "%d %s",  num," ");
    }
    // char buf[100];
    //  while (fscanf(fptr, "%d ",buf) == 1)
    //     printf("%d\n", buf);
    fclose(fptr);

}

void preOrder(BT tNode){
    if(!tNode)
    return;

    printf("%d ",tNode -> data);
    preOrder(tNode -> left);
    preOrder(tNode -> right);


}


void insertIntoTree(BT* tNode,int data){
        // if(*tNode && (*tNode) -> data == data)
        // return ;

        if(!(*tNode)){
                Node* newnode = (Node*)malloc(sizeof(Node));
                newnode -> data = data;
                newnode -> left = NULL;
                newnode -> right = NULL;
                *tNode = newnode;
                return;
        }

        int randomNo = randomNumberGenerator(1000,100);
        if((randomNo % 2) == 0){ // Even number found so go to left
                if((!(*tNode) -> right) && (!(*tNode) -> left)){
                    insertIntoTree(&(*tNode) -> left,data);
                }
                else{
                    insertIntoTree(&(*tNode) -> left,data);
                }
        }                    // else go to right
        else if(randomNo % 2 == 1){
            if(!(*tNode) -> left){
                    return;
                }
                else{
                    insertIntoTree(&(*tNode) -> right,data);
                }
        }
}




void helpInsertingIntoTree(BT *tNode,char filename[],int limit,int upperLimit,int lowerLimit){
    FILE *fptr;
    fptr = fopen("file1.txt","r");
    
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
