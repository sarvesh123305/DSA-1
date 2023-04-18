#include<stdio.h>
#include<stdlib.h>
#include "B.h"

tree* mallocateANode(int data){
        tree* newnode = (tree*)malloc(sizeof(tree));
        newnode -> data = data;
        newnode -> left = NULL;
        newnode -> right = NULL;
        return newnode;
}

void insertIntoTree(Tree *tnode,int data){
     tree* newnode = mallocateANode(data);
     newnode -> left =  NULL;
     newnode -> right =  NULL;
     newnode -> data = data;

     if(!*tnode){
        *tnode = newnode;
        return;
     }
     Tree p = *tnode,q = NULL;
     while(p){
        q = p ;
        if( p -> data == data){
            return ;
        }
        else if(p -> data > data){
            p = p -> left;
        }   
        else{
            p = p -> right;
        }     
     }
     if(q -> data > data){
        q -> left = newnode;
     }
     else{
        q -> right = newnode;
     }

}

void inOrder(Tree tnode){
    if(!tnode)
    return ;
    
    inOrder(tnode -> left);
    printf("%d ",tnode -> data);
    inOrder(tnode -> right);
}
void preOrder(Tree tNode){
    if(!tNode){
            return ;
    }

    printf("%d ",tNode -> data);
    preOrder(tNode -> left);
    preOrder(tNode -> right);
    
  
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


Tree removeNodeRecursive(Tree *root , int key){
    if(!*root){
        return NULL;
    }
    Tree tnode = *root;
    // Tree preecedingNode ;
    if(tnode -> data == key){
        // 0 child
        if(!tnode -> left && !tnode -> right){
            return NULL; 
        }

        if(!tnode -> left && tnode -> right){
            Tree temp = tnode -> right;
            free(tnode) ;
            return temp;
        }

        if(tnode -> left && !tnode -> right){
            Tree temp = tnode -> left;
            free(tnode) ;
            return temp;
        }

        if(tnode -> left && tnode -> right){
            Tree temp = tnode -> left;
            if( !temp -> right){
                tnode -> left = temp -> left;
            }

            while(temp && temp -> right){
                temp = temp -> right;
            }
            int tempData = tnode -> data;
            tnode -> data = temp -> data;
        }
    }
    else if(tnode -> data > key){
        tnode -> left = removeNodeRecursive(&tnode -> left,key);
    }
    else{
        tnode -> right = removeNodeRecursive(&tnode -> right,key);
    }
}
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

    if(!p)
    {
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
            int data = temp -> data;
            (p) -> data = temp -> data;
            removeNode(&(p -> left),data);
        }
        
        return;
    }

}
int abs(int a){
    if(a < 0)
    a *= -1;
    return a;
}
int max(int a,int b){
    return a > b ? a : b;
}
void morrisTraversalPreorder(Tree root)
{
    while (root)
    {
        // right child.
        if (root->left == NULL)
        {
                printf("%d ",root -> data);

            // cout<<root->data<<" ";
            root = root->right;
        }
        else
        {
            // Find inorder predecessor
            Tree current = root->left;
            while (current->right && current->right != root)
                current = current->right;
 
            // If the right child of inorder predecessor already points to
            // this node
            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
 
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                printf("%d ",root -> data);
                // cout<<root->data<<" ";
                current->right = root;
                root = root->left;
            }
        }
    }
}


void preOrderinOOfOne(Tree tnode)   
{
    printf("\n");

   tree* curr = tnode;
    if(!curr)
        return;
    while(curr != NULL){
        if(curr -> left == NULL){
            printf("%d ",curr -> data);
            curr = curr -> right;
        }
        else{
            tree* prev = curr -> left;
            while( prev -> right && prev -> right != curr){
                prev = prev -> right;
            } 

            if(prev -> right == NULL){
                prev -> right = curr;
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;

                printf("%d ",curr -> data);

                curr = curr -> right;
            }
        }
    }
    printf("\n");
    return ;
}
