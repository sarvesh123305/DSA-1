#include<stdio.h>
#include "BST.h"
#include<stdlib.h>

int randomNumberGenerator(int upperLimit,int lowerLimit){
    return (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit ;
}
int main(){
    Tree tree1 ;
    initTree(&tree1);
    for(int i = 0 ; i < 10; i++){
        makeTree(&tree1,randomNumberGenerator(20,10));
    }
    preOrder(tree1);
    removeNode(&tree1,12);
// 16 12 11 10 14 13 20
    printf("\n");
    preOrder(tree1);
    // printf("wsa");
    // leafNodes(tree1);
    // printf("Count : %d",countNodesInTree(tree1));
    // printf("\nHeight : %d",heightOfTree(tree1));
    
    return 0;
}