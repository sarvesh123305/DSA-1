#ifndef STACK_H
#define STACK_H
// typedef struct tree Tsaree;


typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;
// typedef tree* Tree;
typedef tree* Tree;

#include "stack.h"


Tree removeNodeRecursive(Tree *root , int key);


void initTree(Tree* tree);
void makeTree(Tree* tNode,int data);
void preOrder(Tree tNode);
void inOrder(Tree tNode);
// void displayStack(Stack s);
void leafNodes(Tree tNode);
int countNodesInTree(Tree tNode);
int heightOfTree(Tree tNode);
void internalNodes(Tree tNode);
int searchIntoBST(Tree bst,int key,int *ct);
void removeNode(Tree *tnode,int key);
int checkBalancedTree(Tree tnode);

void insertIntoTree(Tree *tnode,int data);
int travelEverythinginOOfOneSpace(Tree tnode);    

#endif
