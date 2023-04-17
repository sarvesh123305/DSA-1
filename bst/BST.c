#include<stdio.h>
#include<stdlib.h>
#include "BST.h"



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
void insertIntoTree(Tree *tnode,int data){
     tree* newnode = (tree*)malloc(sizeof(tree));
     newnode -> left =  NULL;
     newnode -> right =  NULL;
     newnode -> data = data;

     if(!*tnode){
    //  printf("got");
        *tnode = newnode;
        return;
     }
    //  exit(0);
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
void postOrder(Tree tNode){
        if(!tNode){
                return ;
        }

        postOrder(tNode -> left);
        postOrder(tNode -> right);
        printf("%d ",tNode -> data);
    }   
void iterativeInOrder(Tree tnode){
    if(!tnode)
        return ;

        Tree p = tnode;
        Stack s;
        initStack(&s);

        while(1){
            if(p){
                pushS(&s,p);
                p = p -> left;
            }
            else{
                while(!isEmpty(s)){
                    snode* temp = pop(&s);
                    printf("%d ",temp -> data -> data);
                    p = temp -> data;
                    p = p -> right;
                }
            }
        }
}

void iterativePreOrder(Tree tnode){
    if(!tnode)
        return ;
    
    Stack s;
    initStack(&s);
    pushS(&s,tnode);
    while(!isEmpty(s)){
        snode* temp = pop(&s);
        printf("%d ",temp-> data -> data);
        if(temp -> data -> right)
            pushS(&s,temp -> data -> right);
        if(temp -> data -> left)
            pushS(&s,temp -> data -> left);

    }
    return ;
}
void iterativePostOrderUsing2Stack(Tree tnode){
    if(!tnode)
        return ;
    Stack s1,s2;
    initStack(&s1);
    initStack(&s2);

    pushS(&s1,tnode);
    while (!isEmpty(s1))
    {
        snode* temp = pop(&s1);
        pushS(&s2,temp-> data);

        if(temp -> data -> left)
            pushS(&s1,temp -> data -> left);
        if(temp -> data -> right)
            pushS(&s1,temp -> data -> right);
    }
    while(!isEmpty(s2))
        printf("%d ",pop(&s2) -> data -> data);
    
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

// void internalNodes(Tree tnode){
    
//     if(!tnode){
//         return;
//     }

//     Queue q;
//     initQueue(&q,sizeof(tnode));
//     // if(!tnode -> left && !tnode -> right){
//         // return ;
//     // }
//     Tree temp = tnode;
//     enqueue(&q,&temp);
//     while(getQueueSize(&q) > 0 ){
//     int size = getQueueSize(&q);
//     printf("%d",size);
//         temp = NULL;
      
//         dequeue(&q,&temp);
//         printf("%d ",temp -> data);
//         // break;
//         // if(!temp -> left && !temp -> right){
//         //     continue;
//         // }
        
//         if(temp -> left){
//             enqueue(&q,temp -> left);
//         }
//         if(temp -> right){
//             enqueue(&q,temp -> right);
//         }
//     }
//     return ;

//     // printf("%d ",tnode -> data);
//     // internalNodes(tnode -> left);
//     // internalNodes(tnode -> right);
    
// }

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
        }
        
        return;
    }

}
int abs(int a){
    if(a < 0)
    a *= -1;
    return a;
}
int checkBalancedTree(Tree tnode){
    if(!tnode)
        return 1;
    

    int left = checkBalancedTree(tnode -> left);
    int right = checkBalancedTree(tnode -> right);

    int diff = abs(heightOfTree(tnode -> left) - heightOfTree(tnode -> right)) <= 1;
    
    if(left && right && diff)
        return 1;
    
    return 0;
}

int max(int a,int b){
    return a > b ? a : b;
}
void sumOfLongestBloodLine(Tree tnode,int len,int sum,int maxSum,int maxLen){
    if(!tnode)
    {
        if(len > maxLen){
            maxSum = sum;
            maxLen = len;
        }
        else if(len == maxLen)
            maxSum = max(maxSum,sum);
        

        return ;
    }
    sum += tnode -> data;
    sumOfLongestBloodLine(tnode -> left,len+1,sum,maxSum,maxLen);
    sumOfLongestBloodLine(tnode -> right,len+1,sum,maxSum,maxLen);

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

int countLeafNodes(Tree tnode){
    if(!tnode)
        return 0;
    if(!tnode -> left && !tnode -> right){
        return  1;
    }
    return countLeafNodes(tnode -> left) + countLeafNodes(tnode -> right);

}
int travelEverythinginOOfOneSpace(Tree tnode)    //How?
{
// printf("\nCount Leaf : %d\n", countLeafNodes(tnode));

int count = 0 ;
// morrisTraversalPreorder(tnode);
printf("\n"); 
   tree* curr = tnode;
    while(curr != NULL){
        if(curr -> left == NULL){
            printf("%d ",curr -> data);
            count++;
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
            count++;

                curr = curr -> right;
            }
        }
    }
        printf("\nSelf made function  Count : %d",count);
    return count;
}
