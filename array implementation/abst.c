#include "abst.h"
#include<stdlib.h>
#include<limits.h>
#include<stdio.h>
#include<math.h>


void initaBST(aBST* tnode){
    tnode -> A = NULL;          //Initializing BST
    tnode -> size = 0 ;
}

int isEmpty(aBST tnode){        //Checking if BST is NULL
    return (!tnode.A);         //return tnode.size == 0     We can check here size too
}

void insertIntoaBST(aBST* tnode,int data){
    if(isEmpty(*tnode)){
        tnode -> A = (int*)malloc(sizeof(int));         //If BST is empty , mallocate a single byte
        
        if(!tnode -> A)                 //If memory is not allocated ,return
        return ;

        tnode -> size = 1 ;                    //Inserting data
        tnode -> A[0] = data;
        
        return ;
    }

    int index = 0;
    int size =  tnode -> size;
  
    while(index < size && tnode -> A[index] != INT_MIN){    //Checking to insert data at right position
        
        if(tnode -> A[index] == data)                       //If duplicate exits, return i.e discard it
        return ;
        
        else if(tnode -> A[index] > data){
            index = 2 * index + 1;              //Go left
        }
        
        else{
            index = 2 * index + 2;              //Go right
        }
    }

    if( index < size &&  tnode -> A[index] == INT_MIN){     //Insert data
            tnode -> A[index] = data;
            return ;
    }

        tnode -> A = (int*) realloc(tnode -> A,sizeof(int) * (index+1)); //Now if size of array is less and data is 
                                                                         //to be inserted at size greater than array , 
                                                                         //then reallocate memory
        if(!tnode -> A)
        return ;

        for(int i = size ; i < index ; i++)             //Make extra reallocated bytes value INT_MIN
        tnode -> A[i] = INT_MIN;

        tnode -> A[index] = data;
        tnode -> size = index+1;
        return ; 
}
void preOrder(aBST tnode,int i){
   if(i >= tnode.size || tnode.A[i] == INT_MIN){
    return ;
   }

   printf("%d ",tnode.A[i]);
   preOrder(tnode,2*i + 1);
   preOrder(tnode,2*i + 2);

}
void inOrder(aBST tnode,int i){
   if(i >= tnode.size || tnode.A[i] == INT_MIN){
    return ;
   }

   inOrder(tnode,2*i + 1);
   printf("%d ",tnode.A[i]);
   inOrder(tnode,2*i + 2);

}
int heightOfTree(aBST tnode){
    if(isEmpty(tnode))          //Height of empty tree is -1
        return -1;
    int size = tnode.size;
    int count = 0 , decrement = 0;      //Maximum height element is present at last index , so iterate it reverse to get height
    if(size % 2 == 0){
        decrement = 1;              //left call
    }
    else{
        decrement = 2;          //right call
    }
    for(int i = size ; i >= 0 ; i = i/2-decrement){ //Decrement and go towards top with incrementing count
        count++;
    }
    return count;
}

int countLeafNodes(aBST tnode){
    int size = tnode.size;
    int count = 0 ;

     if(isEmpty(tnode)){        //If tree is empty , then return 0 as no node exists
            return 0;   
     }

    for(int i = 0 ; i < size ; i++){
        int left = 2*i + 1;
        int right = 2*i + 2;            
            if(tnode.A[i] == INT_MIN)       //If position is INT_MIN then continue  
                continue;
        
            if(left >= size && right >= size)   //if(left and right are out of size means that it is a leaf node , so inc count)
                count++;
            else if(tnode.A[left] == INT_MIN &&  tnode.A[right] == INT_MIN) //if node has its left and right INT_MIN then it's a leaf node 
                count++;
        
    }
    return count;
}

int isCompleteTree(aBST tnode){
 
    int size = tnode.size ;

    for(int i = 0 ; i < size ; i++)
    {
        // int left = 2*i + 1;
        // int right = 2*i + 2;
        
        if(tnode.A[i] == INT_MIN)           //If any element is INT_MIN indicates it is incomplete tree
            return 0;
        // if(left < size && tnode.A[left] == INT_MIN )
        //     return 0;
        // if(right < tnode.A[right] == INT_MIN)
        //     return 0;
    }
    return 1;
}

void levelOrder(aBST tnode){
    
    if(isEmpty(tnode)){
        return ;
    }

    int lvl = 0 , count = 0;
    for(int i = 0 ; i < tnode.size ; i++){
        if(tnode.A[i] != INT_MIN)
            printf("%d ",tnode.A[i]);       //Printing element only if it has some value
       
        if(i == 0){                     //if i == 0 i.e it is lvl 0 , so print newline
            lvl++;
            printf("\n");
        }

        else if(count == (int)pow(2,lvl)){      // if count is = 2^lvl then print new line
            count = 0;
             lvl++;
            printf("\n");
        }
        count++;                    //Incrememt count at each iteration
    }
    return;
}