#include<stdio.h>
// #include "BST.h"
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include "AVLTree.h"
#include<limits.h>
#endif


int main(){
    AVLTree t;
    initAVLTree(&t);   
    //Recursion check
    //RR Recursion

    // insertRecursivelyIntoTree(&t,10);
    // insertRecursivelyIntoTree(&t,20);
    // insertRecursivelyIntoTree(&t,30);
    // insertRecursivelyIntoTree(&t,40);
    // insertRecursivelyIntoTree(&t,50);
    //Works Fine
    //LL Recursion

    // insertRecursivelyIntoTree(&t,50);
    // insertRecursivelyIntoTree(&t,40);
    // insertRecursivelyIntoTree(&t,30);
    // insertRecursivelyIntoTree(&t,20);
    //Works Fine

    //LR Recursion 
            //RECURSION NOT WORKING in this two codes
    //RL Recursion
    // insertRecursivelyIntoTree(&t,10);
    // insertRecursivelyIntoTree(&t,20);
    // insertRecursivelyIntoTree(&t,30);
    // insertRecursivelyIntoTree(&t,40);
    // insertRecursivelyIntoTree(&t,50);
    // insertRecursivelyIntoTree(&t,25);

    //RL Check

    // insertIntoTree(&t,10);
    // insertIntoTree(&t,20);
    // insertIntoTree(&t,30);
    // insertIntoTree(&t,40);
    // insertIntoTree(&t,50);
    // insertIntoTree(&t,25);
    //Works Fine

    //LR Check

    // insertIntoTree(&t,100);
    // insertIntoTree(&t,120);
    // insertIntoTree(&t,50);
    // insertIntoTree(&t,25);
    // insertIntoTree(&t,75);
    // insertIntoTree(&t,80 );
    //Works Fine

    //LL Check

    // insertIntoTree(&t,30);
    // insertIntoTree(&t,15);
    // insertIntoTree(&t,1);
    // insertIntoTree(&t,0);
    //Works Fine

    //RR Check
    // insertIntoTree(&t,10);
    // insertIntoTree(&t,20);
    // insertIntoTree(&t,30);
    // insertIntoTree(&t,40);
    //Works Fine
    //
    insertIntoTree(&t,10);
    insertIntoTree(&t,20);
    insertIntoTree(&t,30);
    insertIntoTree(&t,40);
    insertIntoTree(&t,50);
    // insertIntoTree(&t,60);
    insertIntoTree(&t,70);
    insertIntoTree(&t,80);
    insertIntoTree(&t,90);
    insertIntoTree(&t,5);
    insertIntoTree(&t,2);
    insertIntoTree(&t,3);
    insertIntoTree(&t,6);
    insertIntoTree(&t,200);
    insertIntoTree(&t,300);





    inOrder(t);
    // preOrder(t);
    
    return 0;
}