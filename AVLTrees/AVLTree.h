#ifndef STACK_H
#define STACK_H

typedef struct avlTree{
    int data,bf;
    struct avlTree* left;
    struct avlTree* right;          //Maintaining data , balanace factor , left ,right and parent pointer for each node
    struct avlTree* parent;         
}avlTree;

typedef avlTree* AVLTree;


//Basic Tree functions
void initAVLTree(AVLTree* tree);
void insertIntoTree(AVLTree *tnode,int data);
void insertRecursivelyIntoTree(AVLTree* tnode,int data);
int heightOfTree(AVLTree tNode);

void removeNode(AVLTree *tnode,int data);

//Traversals
void inOrder(AVLTree tnode);
void preOrder(AVLTree tNode);
#endif
