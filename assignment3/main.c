#include<stdio.h>
// #include "BST.h"
#include<stdlib.h>
#ifndef MAIN_H
#define MAIN_H
#include "AVLTree.h"
#include<limits.h>
#include<string.h>
#endif

void insertIntoTreeHelper(AVLTree *t,int *i){
    char data[1000];
    printf("\nEnter data (string) : ");
    scanf("%s",data);
    insertIntoTree(t,data);
}
void removeNodeFromTreeHelper(AVLTree *t){
    char data[1000];
    printf("\nEnter a data to delete : ");
    scanf("%s",data);
    removeNode(t,data);
}


int main(){
    AVLTree t;
    initAVLTree(&t);   
    char data[1000][1000];
    FILE* fp;
    char ch;
    int k = 0; 
    fp = fopen("data1.txt", "r");
     if (NULL == fp) {
        return 0;
    }
  char str[1000];
      int i = 0;

    while (fscanf(fp, "%s", data[k]) != EOF) {
        // printf(" %s\n", data[k]);
        insertIntoTree(&t,data[k]);
        k++;
        i++;
    }
    // preOrder(t);
    k = 0 , i = 0 ;
    fclose(fp);
    fp = fopen("data1.txt", "r");

     while (fscanf(fp, "%s", data[k]) != EOF) {
        removeNode(&t,data[k]);
        k++;
        i++;
    }

    // printf("\nFinal");
    // printf("\n\nN : %s BF :  %d L : %s  , R  : %s\n\n", t -> data, t -> bf , t -> left ? t -> left -> data :"NO", t -> right ? t -> right -> data : "NO");
    // printf("END\n");
    
    // preOrder(t);

//  insertIntoTree(&t,"Analee");
    // insertIntoTree(&t,"Sholmo");
    // insertIntoTree(&t,"Jalyan");
    // insertIntoTree(&t,"Hally");
    // insertIntoTree(&t,"Karli");
    // insertIntoTree(&t,"Dora");
    // removeNode(&t,"Jalyan");
    // preOrder(t);


    // insertIntoTree(&t,"Sarvesh");
    // insertIntoTree(&t,"Mahind");
    // insertIntoTree(&t,"Kulkarni");
    // removeNode(&t,"Mahind");

   
    // do{
        // printf("\n\n*****AVL Tree Program*****\n");
        // printf("\n1.Insert into Tree ");
        // printf("\n2.Delete a node ");
        // printf("\n3.Display Tree");
        // printf("\n4.Destroy whole tree");
        // printf("\n5.Exit\n\n");

        // int choice ;
        // scanf("%d",&choice);
        //  switch (choice)
        //   {
        //         case 1 : 
        //                 printf("\nEnter data (string) : ");
        //                 scanf("%s",data[i]);
        //                 insertIntoTree(&t,data[i]);
        //                 i++;
        //                  break;
        //         case 2 : removeNodeFromTreeHelper(&t);
        //                  break;
        //         case 3 : preOrder(t);
        //                  break;
        //         case 4 : destroyTree(&t);
        //                  break;
        //         case 5 : exit(0);
        //         default : printf("\nPlease enter a valid choice\n");
        //   }
        // }while(1);
    
    return 0;
}