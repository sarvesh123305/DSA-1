
#include<stdio.h>
#include "binaryTree.h"
#include <stdlib.h>
#include <time.h>
#include "../bst/BST.h"
int main(int argc,char **arguements){
    if(argc == 1){
        return 0;
    }


 srand ( time(NULL) );
int limit = atoi(arguements[1]);
int lowerLimit = atoi(arguements[2]);
int upperLimit = atoi(arguements[3]);
char *filename = arguements[4];

initFileWithRandomNumbers( filename , upperLimit, lowerLimit, limit);
BT tree;
Tree tree1 ;
int ct1 = 0 , ct2 = 0;

for(int i = 0 ; i < 3 ; i++){

        initTree(&tree1);
        helpInserting(&tree1,filename,limit,upperLimit,lowerLimit);
        int searchElement = randomNumberGenerator(upperLimit,lowerLimit);
        searchIntoBST(tree1,searchElement,&ct1);

        initBinaryTree(&tree);
        helpInsertingIntoTree( &tree, filename , limit, upperLimit, lowerLimit);

        searchInBinaryTree(tree,searchElement,&ct2);
        printf("%d %d %d\n" ,limit,ct1, ct2);

        limit = limit * 100;
}
exit(0);
// preOrder(tree);

}

//Notes
//use int main arguemnts
//plot './file2.txt' using 1:2 with linespoints, './file2.txt' using 1:3 with linespoints