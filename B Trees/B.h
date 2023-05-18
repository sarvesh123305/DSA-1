#ifndef STACK_H
#define STACK_H

typedef struct Btree{
    int *data;
    struct Btree* left;
    struct Btree* right;   
}tree;
typedef tree* BTree;

// #include "stack.h"

// Basic Tree functions
void initTree(BTree*);
void insertIntoTree(BTree*,int);
// int searchIntoBST(Tree bst,int key,int *ct);
// void removeNode(Tree *tnode,int key);
// Tree removeNodeRecursive(Tree *root , int key);

//Traversals
// void preOrder(Tree tNode);
// void inOrder(Tree tNode);
// void postOrder(Tree);
// void preOrderinOOfOne(Tree tnode); 

#endif
