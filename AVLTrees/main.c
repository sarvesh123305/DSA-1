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
    //RL Check

    insertIntoTree(&t,10);
    insertIntoTree(&t,20);
    insertIntoTree(&t,30);
    insertIntoTree(&t,40);
    insertIntoTree(&t,50);
    insertIntoTree(&t,25);

    //LR Check

    // insertIntoTree(&t,100);
    // insertIntoTree(&t,120);
    // insertIntoTree(&t,50);
    // insertIntoTree(&t,25);
    // insertIntoTree(&t,75);
    // insertIntoTree(&t,80 );

    //LL Check

    // insertIntoTree(&t,30);
    // insertIntoTree(&t,15);
    // insertIntoTree(&t,1);
    // insertIntoTree(&t,0);

    //RR Check
    // insertIntoTree(&t,10);
    // insertIntoTree(&t,20);
    // insertIntoTree(&t,30);
    // insertIntoTree(&t,40);

    // inOrder(t);
    preOrder(t);
    
    return 0;
}