#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree* left;          //Making structure with left , right pointer and data 
    struct tree* right;
}tree;  
typedef tree* Tree;


void initTree(Tree *tnode){
    *tnode = NULL;              //Initing the node to NULL
}

void insertIntoTree(Tree *tnode,int data){
     Tree newnode = (tree*)malloc(sizeof(tree));
     newnode -> left =  NULL;                           //Allocating space for tree and setting data
     newnode -> right =  NULL;
     newnode -> data = data;

     if(!*tnode){
        *tnode = newnode;               // If tree is empty , make the newnode as root
        return;
     }
     Tree current = *tnode,prev = NULL;
     while(current){
        prev = current ;
        if( current -> data == data)               //If duplicate data is being inserted , discard it 
            return ;
        
        else if(current -> data > data)
            current = current -> left;                  //If data to be inserted is less than tnode -> data then go left
        
        else
            current = current -> right;              //If data to be inserted is more than tnode -> data then go right
         
     }
  
     if(prev -> data > data)
        prev -> left = newnode;
     
     else
        prev -> right = newnode;
     
	return ;
}


int getCountOfNodes(Tree tnode)    
{

    int count = 0 ;                             //Initialize count to 0
    Tree curr = tnode;
    while(curr != NULL){
        if(curr -> left == NULL){                   //If current node is NULL then print data of the current node and move pointer to right
            // printf("%d ",curr -> data);             
            count++;                                //Increment count 
            curr = curr -> right;
        }
        else{
            Tree prev = curr -> left;                           //Store left child of current in some variable
            while( prev -> right && prev -> right != curr)     
                prev = prev -> right;                              //Iterate until prev -> right != NULL or prev -> right != current node
            

            if(prev -> right == NULL){                  // If this is last node then , make a temporary pointer to root (tnode)
                prev -> right = curr;                   //Move current pointer to left
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;               //If prev -> next == current node then , there is temporary link present , remove it i.e make NULL

                // printf("%d ",curr -> data);             //Print the data
            count++;

                curr = curr -> right;               //Move current to right
            }
        }
    }
    return count;
}
int main(){
  
    Tree tree1;                             //Making Tree and initing
    initTree(&tree1);

    insertIntoTree(&tree1,15);                  
    insertIntoTree(&tree1,10);
    insertIntoTree(&tree1,20);
    insertIntoTree(&tree1,8);               //Inserting elements into the tree
    insertIntoTree(&tree1,12);
    insertIntoTree(&tree1,82);
    insertIntoTree(&tree1,122);
    insertIntoTree(&tree1,2);

    int count = getCountOfNodes(tree1) ;            
    printf("Count of nodes : %d \n", count);

    return 0;
}