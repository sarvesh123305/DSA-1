typedef struct aBST{
    int *A;
    int size;
}aBST;

void initaBST(aBST*);
void insertIntoaBST(aBST*,int);
void preOrder(aBST,int);
void inOrder(aBST tnode,int i);
int heightOfTree(aBST);
void levelOrder(aBST tnode);
int isCompleteTree(aBST tnode);
int countLeafNodes(aBST tnode);