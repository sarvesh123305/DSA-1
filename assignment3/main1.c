#include<stdio.h>
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include<string.h>
#include "AVLTree.h"
#include<limits.h>
#include<string.h>
#endif

int getCount(AVLTree tnode){
    if(!tnode)
    return 0;
    return 1 + getCount(tnode -> left) + getCount(tnode -> right);
}

int main(){
    AVLTree t;
    initAVLTree(&t);

    char data[1000][1000];
    FILE* fp;
    char ch;
    int k = 0; 
    fp = fopen("data.txt", "r");
     if (NULL == fp) {
        return 0;
    }
  char str[1000];
      int i = 0;

    while (fscanf(fp, "%s", data[k]) != EOF) {
        insertIntoTree(&t,data[k]);
        k++;
        i++;
    }
    k = 0 , i = 0 ;
    fclose(fp);
    int count = 0 ;
    //  printf("\nTnode Count :  %d\n",getCount(t));
    //  preOrder(t );
        while(t){
            removeNode(&t,t-> data);
     printf("\nTnode Count :  %d",getCount(t));
            count++;
            // printf("\n%d",count);
        }
    
    //  printf("\nTnode Count :  %d",getCount(t));

    //  printf("Count :  %d",count);

   

    return 0;
}