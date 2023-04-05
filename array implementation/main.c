#include<stdio.h>
#include "abst.h"

int main(){
    aBST tnode;
    initaBST(&tnode);
    insertIntoaBST(&tnode,20);

    insertIntoaBST(&tnode,10);
    insertIntoaBST(&tnode,40);
    insertIntoaBST(&tnode,35);
    insertIntoaBST(&tnode,50);
    // insertIntoaBST(&tnode,25);
    insertIntoaBST(&tnode,5);
    insertIntoaBST(&tnode,12);
    
    // insertIntoaBST(&tnode,100);
    // insertIntoaBST(&tnode,105);
    // insertIntoaBST(&tnode,110);





    printf("\nSize :  %d\n",tnode.size);

    inOrder(tnode,0);
    printf("\n");
    // for(int i = 0 ;  i < 7; i++){
    //     printf("%d ",tnode.A[i]);
    // }
    printf("\n");
    printf("Height : %d\n",heightOfTree(tnode));
    levelOrder(tnode);
    printf("\nIsComplete ? : %d \n" ,isCompleteTree(tnode));
    printf("Count Leaf %d\n", countLeafNodes(tnode));

    return 0;
}