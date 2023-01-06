#include<stdio.h>
#include<stdlib.h>

#include "back.h"
int main(){
	Sparse s,s1;
	initSparseMatrix(&s,"input.txt");
	rowsDisplay(s);
	
	initSparseMatrix(&s1,"input1.txt");
	rowsDisplay(s1);
	
	/*Sparse s3 = addTwoMatrix(s,s1);
	rowsDisplay(s3);
	
	Sparse s4 = subtractTwoMatrix(s,s1);
	rowsDisplay(s4);
	*/
	// Sparse s5 ;
	//  transposeMatrix(&s);
	// rowsDisplay(s);
	// transposeMatrix(&s);
	// rowsDisplay(s);
	Sparse x1 ;
	initSparseMatrix(&x1,"test.txt");

	int ans = isSymmetric(x1);
	if(ans){
		printf("\nSymmetric");
	}
	else
		printf("\nNot Symmetric");

}

