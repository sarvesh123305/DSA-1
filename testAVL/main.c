#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int main()
{
  avl_node root;
  init_avl(&root);
  // insert(&root, 33); 
  // insert(&root, 13); 
  // insert(&root, 9); 
  // insert(&root, 8); 
  insert(&root, 10); 
  insert(&root, 20); 
  insert(&root, 30); 
  insert(&root, 40);
  insert(&root, 25); 

  printf("\nInorder\n");
  inorder(root);
  return 0;
}
