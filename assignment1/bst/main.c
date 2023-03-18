#include<stdio.h>
#include "BST.h"

int main(){
    Tree tree1 ;
    initTree(&tree1);
    for(int i = 0 ; i < 10; i++){
        makeTree(&tree1,i);
    }
    preOrder(tree1);
    printf("\n");
    leafNodes(tree1);
    printf("Count : %d",countNodesInTree(tree1));
    printf("\nHeight : %d",heightOfTree(tree1));
    
    return 0;
}