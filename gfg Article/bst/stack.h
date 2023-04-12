#ifndef BST_H
#define BST_H
#include "BST.h"

typedef struct snode{
    Tree data;
    struct snode *next;
}snode;
typedef snode* Stack;

void initStack(Stack*);
void pushS(Stack*,Tree t);
snode* pop(Stack*);
int isEmpty(Stack);
void displayStack(Stack);

#endif
