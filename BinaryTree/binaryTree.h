typedef struct NodeBT{
    int data;
    struct NodeBT* right;
    struct NodeBT* left;

}NodeBT;

typedef NodeBT* BT;


void initBinaryTree(BT*);
void insertIntoTree(BT*,int);
int randomNumberGenerator(int upperLimit,int lowerLimit);
void preOrderBT(BT tNode);
void insertTree(BT *tNode,int data);
void initFileWithRandomNumbers( char filename[] ,int upperLimit,int lowerLimit,int limit);
void helpInsertingIntoTree(BT *tNode,char filename[],int limit,int upperLimit,int lowerLimit);
int searchInBinaryTree(BT,int,int*);
int levelOrderSearch(BT tnode,int key);