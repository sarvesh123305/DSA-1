#include<stdio.h>
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include "stack.h"
#include "B.h"
#endif


int main(){
    Tree tree1,tree2,tree3,tree4,tree5;
    initTree(&tree1);
   

        insertIntoTree(&tree1,15);
        insertIntoTree(&tree1,10);
        insertIntoTree(&tree1,20);
        insertIntoTree(&tree1,5);
        insertIntoTree(&tree1,12);
        insertIntoTree(&tree1,20);
        insertIntoTree(&tree1,82);
 

    preOrderinOOfOne(tree1);
     removeNode(&tree1,15);
    preOrderinOOfOne(tree1);
  
    
    return 0;
}