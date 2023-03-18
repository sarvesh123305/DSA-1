typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

typedef tree* Tree;

void initTree(Tree* tree);
void makeTree(Tree* tNode,int data);
void preOrder(Tree tNode);
void leafNodes(Tree tNode);
int countNodesInTree(Tree tNode);
int heightOfTree(Tree tNode);
void internalNodes(Tree tNode);
int searchIntoBST(Tree bst,int key,int *ct);
void helpInserting(Tree *tNode,char filename[],int limit,int upperLimit,int lowerLimit);

