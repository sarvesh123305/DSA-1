#ifndef STACK_H
#define STACK_H

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;
typedef tree* Tree;

#include "stack.h"

//Basic Tree functions
void initTree(Tree* tree);
void makeTree(Tree* tNode,int data);
int searchIntoBST(Tree bst,int key,int *ct);
void removeNode(Tree *tnode,int key);
void insertIntoTree(Tree *tnode,int data);
Tree removeNodeRecursive(Tree *root , int key);

//Traversals
void iterativePreOrder(Tree);
void inOrder(Tree tNode);
void preOrder(Tree tNode);
void postOrder(Tree);
void iterativePostOrderUsing2Stack(Tree);
//Extra functions
int travelEverythinginOOfOneSpace(Tree tnode);    
int checkBalancedTree(Tree tnode);
void leafNodes(Tree tNode);
int heightOfTree(Tree tNode);
int countNodesInTree(Tree tNode);
void internalNodes(Tree tNode);


#endif
