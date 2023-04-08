#include<stdio.h>
// #include "BST.h"
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include "stack.h"
#include "BST.h"
#endif

int randomNumberGenerator(int upperLimit,int lowerLimit){
    return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit ;
}
int main(){
    Tree tree1,tree2,tree3,tree4,tree5;
    initTree(&tree1);
    initTree(&tree2);
    initTree(&tree3);
    initTree(&tree4);
    initTree(&tree5);

 
        // tree2 = tree1;
        insertIntoTree(&tree1,15);

        insertIntoTree(&tree1,10);
        insertIntoTree(&tree1,20);
        insertIntoTree(&tree1,8);
        insertIntoTree(&tree1,12);
        insertIntoTree(&tree1,82);
        insertIntoTree(&tree1,122);
        insertIntoTree(&tree1,162);
        insertIntoTree(&tree1,2215);
        insertIntoTree(&tree1,2315);
       preOrder(tree1);
        // printf("Balanced or not %d \n",checkBalancedTree(tree1));
     

    // Tree re = removeNodeRecursive(&tree1,15);
    // if(re)
    // printf("Data %d", re -> data );
    // inOrder(tree1);
    // internalNodes(tree1);
    // removeNode(&tree1,12);

















// 16 12 11 10 14 13 20
    // printf("\n");
    // preOrder(tree1);
    // printf("wsa");
    // leafNodes(tree1);
    // printf("Count : %d",countNodesInTree(tree1));
    // printf("\nHeight : %d",heightOfTree(tree1));
    
    return 0;
}