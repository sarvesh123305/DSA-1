#include<stdio.h>
#include<stdlib.h>
#include "AVLTree.h"
#include<limits.h>

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

void reassignBalanceFactorRecursive(AVLTree *tnode){

        AVLTree temp =*tnode;
        if(!temp){
            return;
        }
    temp -> bf = heightOfTree(temp -> left ) - heightOfTree(temp -> right);     //Assigning balance factor to node as left height - right height
      
    return reassignBalanceFactorRecursive(&temp -> parent);

}
AVLTree getImBalancedNode(AVLTree* tnode){
    if(!tnode)
        return NULL;
    AVLTree temp = *tnode;          //Imbalanaced node is that node who has balance factor apart from 0,1,-1
    while(temp){
        if(temp -> bf >= 2 || temp -> bf <= -2){    //Traversing whole the parent ancestor tree for finding imbalanced node 
             return temp;
        }
        temp = temp -> parent;
    }
    return NULL;
  
}
AVLTree getImBalancedNodeRecursive(AVLTree* tnode){
    if(!tnode)
        return NULL;
    AVLTree temp = *tnode;          //Imbalanaced node is that node who has balance factor apart from 0,1,-1
        if(temp -> bf >= 2 || temp -> bf <= -2){    //Traversing whole the parent ancestor tree for finding imbalanced node 
             return temp;
        }
        temp = temp -> parent;
    return getImBalancedNodeRecursive(&temp -> parent);
  
}

void LLRotation(AVLTree* tnode,AVLTree* mainTNode){
    // AVLTree ANode = (*tnode);
    // AVLTree BNode = (*tnode) -> left;           
    // AVLTree BNodeRight = BNode -> right;

    // BNode -> right = ANode;
    // ANode -> left = BNodeRight;
    // BNode -> parent = ANode -> parent;

    // if(BNodeRight){
    //     BNodeRight -> parent = ANode;
    // }
    // BNode -> bf = ANode -> bf = 0;
    // ANode -> parent = BNode;
    // if((*mainTNode) == ANode){
    //     *mainTNode = BNode;
    //     return;
    // }
    // if( BNode -> parent -> left == ANode){
    //     BNode -> parent -> left = BNode;
    // }
    // else{
    //     BNode -> parent -> right = BNode;
    // }
    // return;
    AVLTree A = (*tnode);
    AVLTree B = A -> left;
    AVLTree BR = B -> right;
    AVLTree AP = A -> parent;
    B -> parent = AP;
    if(!AP){
        *mainTNode = B;
    }
    else{
        if(AP -> right == A){
            AP -> right = B;
        }
        else{
            AP -> left = B;
        }
    }
    A -> parent = B;
    B -> right = A;
    A -> left = BR;
    if(BR){
        BR -> parent = A;
    }
    A -> bf = 0;
    B -> bf = 0;
   
    reassignBalanceFactor(&A);

    return;
}

void RRRotation(AVLTree* tnode,AVLTree* mainTNode){
    // AVLTree ANode = (*tnode);
    // AVLTree BNode = (*tnode) -> right;
    // AVLTree BNodeLeft = BNode -> left;
    // BNode -> left = ANode;

    // ANode -> right = BNodeLeft;
    
    // BNode -> parent = ANode -> parent;
    
    // if(BNodeLeft)
    //     BNodeLeft -> parent = ANode;

    // ANode -> parent = BNode;
    // BNode -> bf = ANode -> bf = 0;

    // if((*mainTNode) == ANode){
    //     *mainTNode = BNode;
    //     return;

    // }
    // // if(!BNode -> parent){
    // //     printf("********************");
    // //     return ;
    // // }
    // if( BNode -> parent -> left == ANode)
    //     BNode -> parent -> left = BNode;
    
    // else
    //     BNode -> parent -> right = BNode;
    // reassignBalanceFactor(&ANode);
    // return;
    AVLTree A = (*tnode);
    AVLTree B = A -> right;
    AVLTree BR = B -> left;
    AVLTree AP = A -> parent;
    B -> parent = AP;
    if(!AP){
        *mainTNode = B;
    }
    else{
        if(AP -> right == A){
            AP -> right = B;
        }
        else{
            AP -> left = B;
        }
    }
    A -> parent = B;
    B -> left = A;
    A -> right = BR;
    if(BR){
        BR -> parent = A;
    }
    A -> bf = 0;
    B -> bf = 0;
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
     newnode -> parent = q;
    
     reassignBalanceFactor(&q);

     AVLTree imBalancedNode = getImBalancedNode(&q);
     if(!imBalancedNode)
        return;
     printf("\nImbalaned Node : %d , data : %d\n",imBalancedNode ? imBalancedNode -> bf : INT_MIN,imBalancedNode ? imBalancedNode -> data :INT_MIN );
     if(imBalancedNode -> bf == -2){

        if(imBalancedNode -> right -> bf == -1)
            RRRotation(&imBalancedNode,tnode);
        else{

            RLRotation(&imBalancedNode,tnode);
        }
     }   
     else if(imBalancedNode -> bf == 2 ){
        if(imBalancedNode -> left -> bf == 1)
            LLRotation(&imBalancedNode,tnode);
        else
            LRRotation(&imBalancedNode ,tnode);
     }
        // printf("\n %d\n ", imBalancedNode ? imBalancedNode  -> data : INT_MAX);

        // printf("\nsar%d\n ", imBalancedNode -> parent  ? imBalancedNode  -> parent -> data : INT_MAX);
        // printf("\nsar%d\n ", imBalancedNode -> parent  -> parent ? imBalancedNode  -> parent -> parent -> data : INT_MAX);


    }

    void insertRecursivelyIntoTree(AVLTree* tnode,int data){

    avlTree* newnode =  mallocateANode(tnode,data);
     if(!*tnode){
        *tnode = newnode;
        return;
     }
     AVLTree q = *tnode;
       if(*tnode && (*tnode) -> data == data){
        return;
    }
    if(!*tnode){
       avlTree* newnode = mallocateANode(tnode,data);
        *tnode = newnode;
        return;
    }

    if((*tnode) -> data > data){
        insertRecursivelyIntoTree(&(*tnode) -> left,data);
    }
    else{
        insertRecursivelyIntoTree(&(*tnode) -> right,data);
    }
     newnode -> parent = q;
    
         reassignBalanceFactorRecursive(&q);


     AVLTree imBalancedNode = getImBalancedNode(&q);
     if(!imBalancedNode)
        return;
     printf("\nImbalaned Node : %d , data : %d\n",imBalancedNode ? imBalancedNode -> bf : INT_MIN,imBalancedNode ? imBalancedNode -> data :INT_MIN );
     if(imBalancedNode -> bf == -2){

        if(imBalancedNode -> right -> bf == -1)
            RRRotation(&imBalancedNode,tnode);
        else{

            RLRotation(&imBalancedNode,tnode);
        }
     }   
     else if(imBalancedNode -> bf == 2 ){
        if(imBalancedNode -> left -> bf == 1)
            LLRotation(&imBalancedNode,tnode);
        else
            LRRotation(&imBalancedNode ,tnode);
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
    if(!tnode){
            return ;
    }

    printf("%d  ,BF : %d , L : %d , R : %d\n",tnode -> data,tnode -> bf,tnode -> left ? tnode -> left -> data : INT_MIN , tnode -> right ? tnode -> right -> data:INT_MIN) ;

    preOrder(tnode -> left);
    preOrder(tnode -> right);
    
  
} 
void postOrder(AVLTree tNode){
        if(!tNode){
                return ;
        }

        postOrder(tNode -> left);
        postOrder(tNode -> right);
        printf("%d ",tNode -> data);
    }   



// int searchIntoBST(AVLTree bst,int key,int *ct){
//     //Recursive
//     // if(!bst){
//     //     return 0;
//     // }
//     // *ct = *ct + 1;
//         // if(bst -> data == key)
//         // return 1;
//         // else if(bst -> data > key){
//         //         searchIntoBST(bst -> left,key);
//         // }
//         // else{
//         //         searchIntoBST(bst -> right,key);

//         // }
//     //Iterative
//     while(bst){
//         if(!bst)
//             return 0;
        
//         *ct = *ct + 1;
        
//         if(bst -> data == key)
//             return 1;

//         else if(bst -> data > key)
//             bst = bst -> right;
        
//         else
//         bst = bst -> left;
//     }
//     return 0;
// }

int max(int a,int b){
    if(a > b){
        return a;
    }
    return b;
}
int heightOfTree(AVLTree tNode){
    if(!tNode)
    return -1;

    return 1 + max(heightOfTree(tNode -> left) , heightOfTree(tNode -> right));

}



// Tree removeNodeRecursive(AVLTree *root , int key){
//     if(!*root){
//         return NULL;
//     }
//     AVLTree tnode = *root;
//     // Tree preecedingNode ;
//     if(tnode -> data == key){
//         // 0 child
//         if(!tnode -> left && !tnode -> right){
//             return NULL; 
//         }

//         if(!tnode -> left && tnode -> right){
//             Tree temp = tnode -> right;
//             free(tnode) ;
//             return temp;
//         }

//         if(tnode -> left && !tnode -> right){
//             Tree temp = tnode -> left;
//             free(tnode) ;
//             return temp;
//         }

//         if(tnode -> left && tnode -> right){
//             Tree temp = tnode -> left;
//             if( !temp -> right){
//                 tnode -> left = temp -> left;
//             }

//             while(temp && temp -> right){
//                 temp = temp -> right;
//             }
//             int tempData = tnode -> data;
//             tnode -> data = temp -> data;
//         }
//     }
//     else if(tnode -> data > key){
//         tnode -> left = removeNodeRecursive(&tnode -> left,key);
//     }
//     else{
//         tnode -> right = removeNodeRecursive(&tnode -> right,key);
//     }
// }
// void removeNode(AVLTree *tnode,int key){
//     avlTree *p,*q;
//     if(!*tnode){
//         return;
//     }

//     p = *tnode;
//     while(p){
//         if(p -> data == key)
//             break;
//         q = p;                  //Search for presence of node and make pointer q following p
//         if(p -> data > key)
//             p = p -> left;
//         else 
//             p = p -> right;
//     }
//     if(p)
//         printf("\n%d",p -> data);
//         printf(" Found ");
   
//     if(!p)
//     {
//         printf("Not Found ");
//         return ;        //Node not present 
//     }

//     //Now 4 cases

//     //leaf node
//     if(!p -> right && !p -> left){

//         avlTree *deleteNode = p;
//         if(p == *tnode)    //There is only 1 node (root node) 
//             *tnode = NULL;
        
//         else{
//             if(q -> left == p){
//                 q -> left = NULL;
//             }
//             else{
//                 q -> right = NULL;
//             }
//         }   
//         free(deleteNode);
//         return;
//     }

//     if(!p -> right && p -> left){
//         avlTree *deleteNode = p;

//         if(p == *tnode)    //There is root with only left child
//             *tnode = p -> left;
        
//         else{
//               if(q -> left == p)
//                 q -> left = p -> left;
            
//             else
//                 q -> right = p -> right;
//         }
//         free(deleteNode);
//         return;
//     }

//      if(p -> right && !p -> left){
//         avlTree *deleteNode = p;

//         if(p == *tnode)    //There is root with only right child
//             *tnode = p -> right;
        
//         else{
//               if(q -> left == p)
//                 q -> left = p -> left;
            
//             else
//                 q -> right = p -> right;
//         }
//         free(deleteNode);
//         return;
//     }
 
//     if(p -> right && p -> left){
//         avlTree *temp,*preecedingPointer; //There is root with left and right child

//         preecedingPointer = p -> left;
//         temp = preecedingPointer -> right;
//         if(!temp)
//         {
//             p -> data = preecedingPointer -> data;
//             p -> left = preecedingPointer -> left;
//         }
//         else{
//             while(temp -> right){
//                 preecedingPointer = temp;
//                 temp = temp -> right;
//             }
//             (*tnode) -> data = p -> data;
//             q -> right = NULL;
//         }
        
//         return;
//     }

// }
