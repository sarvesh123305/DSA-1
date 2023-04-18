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
int searchIntoBST(Tree bst,int key,int *ct);
void removeNode(Tree *tnode,int key);
void insertIntoTree(Tree *tnode,int data);
Tree removeNodeRecursive(Tree *root , int key);

//Traversals
void preOrder(Tree tNode);
void inOrder(Tree tNode);
void postOrder(Tree);
void preOrderinOOfOne(Tree tnode); 

#endif
