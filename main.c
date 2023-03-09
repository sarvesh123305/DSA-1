#include<stdio.h>
#include "binaryTree.h"
#include <stdlib.h>
#include <time.h>

int main(int argc,char **arguements){

    if(argc == 1){
        return 0;
    }


 srand ( time(NULL) );
int limit = atoi(arguements[1]);
int lowerLimit = atoi(arguements[2]);
int upperLimit = atoi(arguements[3]);
// char *filename = arguements[4];

initFileWithRandomNumbers( "file1.txt" , upperLimit, lowerLimit, limit);
BT tree;
initTree(&tree);

//  helpInsertingIntoTree( &tree, "file1.txt" , limit, upperLimit, lowerLimit);
// preOrder(tree);
//  insertIntoTree(&tree,10,1);
//  insertIntoTree(&tree,20,2);
//  insertIntoTree(&tree,30,3);
//  insertIntoTree(&tree,40,4);
//   insertIntoTree(&tree,10,2);
//  insertIntoTree(&tree,50,1);
//   insertIntoTree(&tree,10,2);
//  insertIntoTree(&tree,50,1);
//   insertIntoTree(&tree,10,2);
//  insertIntoTree(&tree,50,1);
//   insertIntoTree(&tree,10,2);
//  insertIntoTree(&tree,50,1);

preOrder(tree);


 
//    while (!feof(fptr)) {
//       fscanf(fptr,"%d",&i);
//    }
//    fclose(fptr);
// BT tree;
// initTree(&tree);
// insertTree(&tree,10);
// insertTree(&tree,20);
// insertTree(&tree,30);
// insertTree(&tree,40);
// insertTree(&tree,50);
// preOrder(tree);
// ./a.out >> file.txt
}

//Notes
//use int main arguemnts