#include<stdio.h>
#include<stdlib.h>
#include "B.h"

void initTree(BTree* tnode){
    *tnode = NULL;
}

void createNewNode(BTree* tnode,int data){
      BTree newnode = (tree*)malloc(sizeof(tree));
        newnode -> data = (int*)malloc(sizeof(int)*5);
        newnode -> left = NULL;
        newnode -> right = NULL;
}
void insertIntoTree(BTree* tnode,int data){
   

}