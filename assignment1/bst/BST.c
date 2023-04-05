#include<stdio.h>
#include<stdlib.h>
#include "BST.h"


void initTree(Tree* tree){
    (*tree) = NULL;
}

tree* mallocateANode(int data){
        tree* newnode = (tree*)malloc(sizeof(tree));
        newnode -> data = data;
        newnode -> right = NULL;
        newnode -> left = NULL;
        return newnode;
}
void makeTree(Tree* tNode,int data){
    if(*tNode && (*tNode) -> data == data){
        return;
    }
    if(!*tNode){
       tree* newnode = mallocateANode(data);
        *tNode = newnode;
        return;
    }

    if((*tNode) -> data > data){
        makeTree(&(*tNode) -> right,data);
    }
    else{
        makeTree(&(*tNode) -> left,data);
    }
}
void preOrder(Tree tNode){
    if(!tNode){
            return ;
    }

    printf("%d ",tNode -> data);
    preOrder(tNode -> left);
    preOrder(tNode -> right);
} 
void leafNodes(Tree tNode){
    if(!tNode)
    return ;

    if(!tNode -> left && !tNode -> right){
        printf("%d ",tNode -> data);
        return;
    }

    leafNodes(tNode -> left);
    leafNodes(tNode -> right);

}
int randomNumberGeneratorBST(int upperLimit,int lowerLimit){
return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit ;
}
void helpInserting(Tree *tNode,char filename[],int limit,int upperLimit,int lowerLimit){
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

                int data = randomNumberGeneratorBST(upperLimit,lowerLimit);
                makeTree(tNode,data);
        }
        
}

int searchIntoBST(Tree bst,int key,int *ct){
    //Recursive
    // if(!bst){
    //     return 0;
    // }
    // *ct = *ct + 1;
        // if(bst -> data == key)
        // return 1;
        // else if(bst -> data > key){
        //         searchIntoBST(bst -> left,key);
        // }
        // else{
        //         searchIntoBST(bst -> right,key);

        // }
    //Iterative
    while(bst){
        if(!bst)
            return 0;
        
        *ct = *ct + 1;
        
        if(bst -> data == key)
            return 1;

        else if(bst -> data > key)
            bst = bst -> right;
        
        else
        bst = bst -> left;
    }
    return 0;
}
int countNodesInTree(Tree tNode){
    if(!tNode)
    return 0;

    return countNodesInTree(tNode -> left) +  countNodesInTree(tNode -> right) + 1; 
}


int heightOfTree(Tree tNode){
    if(!tNode)
    return 0;

    return 1 + heightOfTree(tNode -> left) + heightOfTree(tNode -> right);
}

// void internalNodes(Tree tNode){
//     if(!tNode){
//         return;
//     }

//     if(!tNode -> left && !tNode -> right){
//         return;
//     }

//     printf(%d,tNode);
// }