typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;

}Node;

typedef Node* BT;


void initTree(BT*);
void insertIntoTree(BT*,int);
void preOrder(BT tNode);
void insertTree(BT *tNode,int data);
void initFileWithRandomNumbers( char filename[] ,int upperLimit,int lowerLimit,int limit);
void helpInsertingIntoTree(BT *tNode,char filename[],int limit,int upperLimit,int lowerLimit);
