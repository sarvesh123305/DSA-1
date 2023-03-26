
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


BT tree;
Tree tree1 ;


for(int i = 0 ; i < 3 ; i++){
        initFileWithRandomNumbers( filename , upperLimit, lowerLimit, limit);
        int ct1 = 0 , ct2 = 0;

        initTree(&tree1);
        helpInserting(&tree1,filename,limit,upperLimit,lowerLimit);
        initBinaryTree(&tree);
        helpInsertingIntoTree( &tree, filename , limit, upperLimit, lowerLimit);

        for(int j = 0 ; j < 5; j++){
                int temp = 0 ;
                int searchElement = randomNumberGenerator(upperLimit,lowerLimit);
                searchIntoBST(tree1,searchElement,&temp);
                ct1 += temp;
                ct2 +=  levelOrderSearch(tree,searchElement);
        }       
        ct1 /= 5;
        ct2 /= 5; 
        printf("%d %d %d\n" ,limit,ct1, ct2);
        
        limit = limit * 10;
}

}

//plot './file2.txt' using 1:2 with linespoints, './file2.txt' using 1:3 with linespoints