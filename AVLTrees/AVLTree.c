#include<stdio.h>
#include<stdlib.h>
#include "AVLTree.h"
#include<limits.h>

int maxi(int a,int b){
return (a > b) ? a : b;
}
int heightOfTree(AVLTree t){
    if(!t)
        return -1;
    return 1 + maxi(heightOfTree(t -> left) ,heightOfTree(t -> right));
}
avlTree* mallocateANode(AVLTree* tnode,int data){
     avlTree* newnode = malloc(sizeof(avlTree));        //Mallocating a node and initializing the structure
     newnode -> left =  NULL;                           
     newnode -> right =  NULL;
     newnode -> parent =  NULL;
     newnode -> data = data;
     newnode ->  bf = 0;
     return newnode;
}
void initAVLTree(AVLTree* tnode){
    *tnode  = NULL;                             //Initializing a structure
}
void reassignBalanceFactor(AVLTree *tnode){
    AVLTree temp = *tnode;          
    while(temp){
                temp -> bf = heightOfTree(temp -> left ) - heightOfTree(temp -> right);     //Assigning balance factor to node as left height - right height
                temp = temp -> parent;
    }
    return ;

}

AVLTree getImBalancedNode(AVLTree tnode){
    if(!tnode)
        return NULL;
    AVLTree temp = tnode;          //Imbalanaced node is that node who has balance factor apart from 0,1,-1
    while(temp){
        if(temp -> bf >= 2 || temp -> bf <= -2){    //Traversing whole the parent ancestor tree for finding imbalanced node 
             return temp;
        }
        temp = temp -> parent;
    }
    return NULL;
  
}


void LLRotation(AVLTree* tnode,AVLTree* mainTNode){
    AVLTree A = (*tnode);
    AVLTree B = A -> left;
    AVLTree BR = B -> right;
    AVLTree AP = A -> parent;
    B -> parent = AP;
    if(!AP){
        *mainTNode = B;
    }
    else{
        if(AP -> right == A)
            AP -> right = B;
        else
            AP -> left = B;
    }
    A -> parent = B;
    B -> right = A;
    A -> left = BR;
    if(BR)
        BR -> parent = A;    
    A -> bf = B -> bf = 0;
    reassignBalanceFactor(&A);
    return;
}

void RRRotation(AVLTree* tnode,AVLTree* mainTNode){
    AVLTree A = (*tnode);
    AVLTree B = A -> right;
    AVLTree BR = B -> left;
    AVLTree AP = A -> parent;
    B -> parent = AP;
    if(!AP)
        *mainTNode = B;
    
    else{
        if(AP -> right == A)
            AP -> right = B;
        else
            AP -> left = B;
    }
    A -> parent = B;
    B -> left = A;
    A -> right = BR;
    if(BR)
        BR -> parent = A;
    A -> bf = B -> bf = 0;
    reassignBalanceFactor(&A);
}
void LRRotation(AVLTree* tnode,AVLTree* mainTNode){
    RRRotation(&(*tnode)-> left,mainTNode);
    LLRotation(tnode ,mainTNode);
}

void RLRotation(AVLTree* tnode,AVLTree* mainTNode){
    LLRotation(&(*tnode) -> right,mainTNode);
    RRRotation(tnode,mainTNode);
}
void insertIntoTree(AVLTree *tnode,int data){
     avlTree* newnode =  mallocateANode(tnode,data);
     if(!*tnode){
        *tnode = newnode;
        return;
     }
     AVLTree p = *tnode,q = NULL;
     while(p){
        q = p ;
        if( p -> data == data){
            free(newnode);
            return ;
        }
        else if(p -> data > data)
            p = p -> left;
        else
            p = p -> right;  
     }
     if(q -> data > data)
        q -> left = newnode;
     else
        q -> right = newnode;
     newnode -> parent = q;
    
     reassignBalanceFactor(&q);

     AVLTree imBalancedNode = getImBalancedNode(q);
     while(imBalancedNode){
    //  if(!imBalancedNode)
        // return;
     printf("\nImbalaned Node : %d , data : %d\n",imBalancedNode ? imBalancedNode -> bf : INT_MIN,imBalancedNode ? imBalancedNode -> data :INT_MIN );
     if(imBalancedNode -> bf == -2){

        if(imBalancedNode -> right -> bf == -1)
            RRRotation(&imBalancedNode,tnode);
        else
            RLRotation(&imBalancedNode,tnode);
     }   
     else if(imBalancedNode -> bf == 2 ){
        if(imBalancedNode -> left -> bf == 1)
            LLRotation(&imBalancedNode,tnode);
        else
            LRRotation(&imBalancedNode ,tnode);
     }
     imBalancedNode = getImBalancedNode(imBalancedNode);
    }
}

void inOrder(AVLTree tnode){
    if(!tnode)
    return ;
    
    inOrder(tnode -> left);
    printf("%d  ,BF : %d , L : %d , R : %d\n",tnode -> data,tnode -> bf,tnode -> left ? tnode -> left -> data : INT_MIN , tnode -> right ? tnode -> right -> data:INT_MIN) ;
    inOrder(tnode -> right);
}
void preOrder(AVLTree tnode){
    if(!tnode)
            return ;
    printf("%d  ,BF : %d , L : %d , R : %d\n",tnode -> data,tnode -> bf,tnode -> left ? tnode -> left -> data : INT_MIN , tnode -> right ? tnode -> right -> data:INT_MIN) ;

    preOrder(tnode -> left);
    preOrder(tnode -> right);
} 

void removeNodeHelper(AVLTree* parent)
{
    if(!(*parent))
        return;
    reassignBalanceFactor(parent);

    AVLTree imBalancedNode = getImBalancedNode(*parent);
    if (!imBalancedNode)
        return;
    
    // printf("\nImbalaned Node : %s , bf : %d\n", imBalancedNode->data, imBalancedNode->bf);
    if (imBalancedNode->bf == -2)
    {
        if (imBalancedNode->right->bf == -1)
            RRRotation(&imBalancedNode, parent);
        else
            RLRotation(&imBalancedNode, parent);
    }
    else if (imBalancedNode->bf == 2)
    {
        if (imBalancedNode->left->bf == 1)
            LLRotation(&imBalancedNode, parent);
        else
            LRRotation(&imBalancedNode, parent);
    }
}

void removeNode(AVLTree *tnode,int data)
{
    avlTree *p, *q;
    if (!*tnode)
        return;

    p = *tnode;
    while (p)
    {
        if (data == p -> data)
            break;
        q = p; // Search for presence of node and make pointer q following p
        if (p -> data > data)
            p = p->left;
        else
            p = p->right;
    }
    if (p)
    {
        printf("%d", p->data);
        printf("Found\n");
    }
    if (!p)
    {
        printf("\n %d ", data);
        printf("Not Found\n");
        return; // Node not present
    }
    // Now 4 cases
    
    // leaf node
    // int flag = 0;
   
    if (!p->right && !p->left)
    {
        avlTree *deleteNode = p;
        AVLTree temp = deleteNode->parent;
        if (p == *tnode) // There is only 1 node (root node)
            *tnode = NULL;

        else
        {
            if (q->left == p)
                q->left = NULL;
            else
                q->right = NULL;
            p -> parent = NULL;
        }
        free(deleteNode);
        removeNodeHelper(&temp);

        if((*tnode) && (*tnode) -> parent &&  (*tnode) -> parent == (temp))
        *tnode = temp;
        return;
    }
        //1 child -> Only left child exists
    if (!p->right && p->left)
    {
        AVLTree deleteNode = p;
        AVLTree temp = deleteNode->parent;
        if (p == *tnode) // There is root with only left child
        {
            // (*tnode) -> parent = NULL ;
            *tnode = p->left;
            (*tnode) -> parent = NULL;
        }

        else
        {
            if (q->left == p)
                q->left = p->left;
            else
                q->right = p->left;
            p -> left -> parent = q;
        }
        free(deleteNode);
        removeNodeHelper(&temp);

        if((*tnode) && (*tnode) -> parent &&  (*tnode) -> parent == (temp))
        *tnode = temp;

        return;
    }
    //1 Child , Only right child exists
    else if (p->right && !p->left)
    {
        avlTree *deleteNode = p;
       
        AVLTree temp = deleteNode->parent;
        if (p == *tnode)
        {
            p -> right -> parent = (*tnode) -> parent;
            *tnode = (deleteNode->right);
        }
        else
        {
           
            if (q->left == p)
                q->left = p->right;

            else
                q->right = p->right;
            
            p -> right -> parent = q;
        }
        free(deleteNode);
        removeNodeHelper(&temp);
        
        if((*tnode) && (*tnode) -> parent &&  (*tnode) -> parent == (temp))
        *tnode = temp;

        return;
    }
    //2 Childs i.e there exits both left and right
    else if (p->right && p->left)
    {
        avlTree *temp, *preecedingPointer; // There is root with left and right child
        preecedingPointer = p->left;
        temp = preecedingPointer->right;
        AVLTree parentOfTemp = NULL;
        if (!temp)
        {
            p -> data = preecedingPointer -> data;
            p->left = preecedingPointer->left;
            if(preecedingPointer -> left)
            preecedingPointer -> left -> parent = p;
            parentOfTemp = preecedingPointer->parent;
            free(preecedingPointer);
        }
        else
        {
            while (temp->right)
            {
                preecedingPointer = temp;
                temp = temp->right;
            }
           int tempo = temp->data;
            p -> data = temp -> data;
            parentOfTemp = preecedingPointer;
            if(temp -> left){
                preecedingPointer -> right = temp -> left;
                temp -> left -> parent = preecedingPointer; //EDGE CASE , MISSING CASE
            }
            else
            preecedingPointer->right = NULL;
            free(temp);
        }
        removeNodeHelper(&parentOfTemp);
        
        if((*tnode) && (*tnode) -> parent &&  (*tnode) -> parent == (parentOfTemp))
        *tnode = parentOfTemp;
    }
}
