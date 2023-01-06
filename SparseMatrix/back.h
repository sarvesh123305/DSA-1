#include<stdio.h>

typedef struct node {
	int i , j ;
	int data;
	struct node* next;
	struct node* down;
}node;
typedef struct Sparse{
	 int i , j ;
	node** rows ;
	node** cols;
}Sparse;

void colsDisplay(Sparse s);
void rowsDisplay(Sparse s);
void AddNodeToList(int temp,Sparse **s,int i , int j);
void initSparseMatrix(Sparse *s,char filename[]);
void initMatrix(Sparse *s,int i,int j);
Sparse addTwoMatrix(Sparse s1,Sparse s2);
Sparse subtractTwoMatrix(Sparse s1,Sparse s2);
void transposeMatrix(Sparse *s1);
void swapLinks(node **s1,node **s2);
int isSymmetric(Sparse s1);
