#include<stdio.h>
// #include "BST.h"
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include "AVLTree.h"
#include<limits.h>
#include<string.h>
#endif


int main(){
    AVLTree t;
    initAVLTree(&t);   
   
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


/*
    RUNTIME CHECK
*/

    // insertIntoTree(&t,"Soham");
    // insertIntoTree(&t,"Mahind");
    // insertIntoTree(&t,"Sahel");
    // insertIntoTree(&t,"Sarvesh");
    // insertIntoTree(&t,"Aditya");
    // insertIntoTree(&t,"Pratyay");
    insertIntoTree(&t,"Soham");
    insertIntoTree(&t,"Sarvesh");
    insertIntoTree(&t,"Tushar");
    insertIntoTree(&t,"Sadanand");
    insertIntoTree(&t,"SoalMortal");

    insertIntoTree(&t,"Zuned");
    insertIntoTree(&t,"Sara");




    preOrder(t);
    printf("\n\n");
    removeNode(&t,"Soham");
    // destroyTree(&t);
    

/*
    END CHECK
*/
    //LL Check

    // insertIntoTree(&t,"Saf");//10
    // insertIntoTree(&t,"Sac");//20
    // insertIntoTree(&t,"Sai");//50
    // insertIntoTree(&t,"Saa");//20
    // insertIntoTree(&t,"Sad");//20
    // insertIntoTree(&t,"Sae");//30
    // insertIntoTree(&t,"Sag");//40
    // insertIntoTree(&t,"Sad");//25

    //Works Fine Checked
    // removeNode(&t,"Saf");
    // AVLTree tempp =  removeNodeRecursive(&t,"Sac");
    // printf("\n%s", tempp -> data);
    // printf("OP ; %d\n",strcmp("Sar","Sas"));

    // printf("\nOP ; %d",strcmp("Sar","Sak"));

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
    // inOrder(t);
    preOrder(t);
    
    return 0;
}