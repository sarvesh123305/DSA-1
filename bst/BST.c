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
        makeTree(&(*tNode) -> left,data);
    }
    else{
        makeTree(&(*tNode) -> right,data);
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


void removeNode(Tree *tnode,int key){
    tree *p,*q;
    if(!*tnode){
        return;
    }

    p = *tnode;
    while(p){
        if(p -> data == key)
            break;
        q = p;                  //Search for presence of node and make pointer q following p
        if(p -> data > key)
            p = p -> left;
        else 
            p = p -> right;
    }
    if(p)
        printf("\n%d",p -> data);
        printf(" Found ");
   
    if(!p)
    {
        printf("Not Found ");
        return ;        //Node not present 
    }

    //Now 4 cases

    //leaf node
    if(!p -> right && !p -> left){

        tree *deleteNode = p;
        if(p == *tnode)    //There is only 1 node (root node) 
            *tnode = NULL;
        
        else{
            if(q -> left == p){
                q -> left = NULL;
            }
            else{
                q -> right = NULL;
            }
        }   
        free(deleteNode);
        return;
    }

    if(!p -> right && p -> left){
        tree *deleteNode = p;

        if(p == *tnode)    //There is root with only left child
            *tnode = p -> left;
        
        else{
              if(q -> left == p)
                q -> left = p -> left;
            
            else
                q -> right = p -> right;
        }
        free(deleteNode);
        return;
    }

     if(p -> right && !p -> left){
        tree *deleteNode = p;

        if(p == *tnode)    //There is root with only right child
            *tnode = p -> right;
        
        else{
              if(q -> left == p)
                q -> left = p -> left;
            
            else
                q -> right = p -> right;
        }
        free(deleteNode);
        return;
    }
 
    if(p -> right && p -> left){
        tree *temp,*preecedingPointer; //There is root with left and right child

        preecedingPointer = p -> left;
        temp = preecedingPointer -> right;
        if(!temp)
        {
            p -> data = preecedingPointer -> data;
            p -> left = preecedingPointer -> left;
        }
        else{
            while(temp -> right){
                preecedingPointer = temp;
                temp = temp -> right;
            }
            (*tnode) -> data = p -> data;
            q -> right = NULL;
            // free(p);
        }
        
        return;
    }

}