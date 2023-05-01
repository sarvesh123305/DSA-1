#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"
#include <string.h>
#include <limits.h>

avlTree *mallocateANode(AVLTree *tnode, char *data)
{
    avlTree *newnode = malloc(sizeof(avlTree)); // Mallocating a node and initializing the structure
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->data = data;
    newnode->bf = 0;
    return newnode;
}
void initAVLTree(AVLTree *tnode)
{
    *tnode = NULL; // Initializing a structure
}
void reassignBalanceFactor(AVLTree *tnode)
{
    AVLTree temp = *tnode;
    while (temp)
    {
        temp->bf = heightOfTree(temp->left) - heightOfTree(temp->right); // Assigning balance factor to node as left height - right height
        temp = temp->parent;
    }
    return;
}


AVLTree getImBalancedNode(AVLTree *tnode)
{
    if (!tnode)
        return NULL;
    AVLTree temp = *tnode; // Imbalanaced node is that node who has balance factor apart from 0,1,-1
    while (temp)
    {
        if (temp->bf >= 2 || temp->bf <= -2)
        { // Traversing whole the parent ancestor tree for finding imbalanced node
            return temp;
        }
        temp = temp->parent;
    }
    return NULL;
}


void LLRotation(AVLTree *tnode, AVLTree *mainTNode)  //Rotate whole tree in right direction
{
    AVLTree ANode = (*tnode);
    AVLTree BNode = (*tnode) -> left;
    AVLTree BNodeRight = BNode -> right;

    BNode -> right = ANode;
    ANode -> left = BNodeRight;
    BNode -> parent = ANode -> parent;

    if(BNodeRight){
        BNodeRight -> parent = ANode;
    }
    BNode -> bf = ANode -> bf = 0;
    ANode -> parent = BNode;
    if((*mainTNode) == ANode){
        *mainTNode = BNode;
        return;
    }
    if( BNode -> parent -> left == ANode){
        BNode -> parent -> left = BNode;
    }
    else{
        BNode -> parent -> right = BNode;
    }
    reassignBalanceFactor(&ANode);          //We have rotated the tree using pointers , now reassingning its bf

    return;
    AVLTree A = (*tnode);
    AVLTree B = A->left;
    AVLTree BR = B->right;
    AVLTree AP = A->parent;
    B->parent = AP;
    if (!AP)
    {
        *mainTNode = B;
    }
    else
    {
        if (AP->right == A)
        {
            AP->right = B;
        }
        else
        {
            AP->left = B;
        }
    }
    A->parent = B;
    B->right = A;
    A->left = BR;
    if (BR)
    {
        BR->parent = A;
    }
    A->bf = 0;
    B->bf = 0;

    reassignBalanceFactor(&A);          //We have rotated the tree using pointers , now reassingning its bf

    return;
}

void RRRotation(AVLTree *tnode, AVLTree *mainTNode) //Rotate tree to left
{
    AVLTree ANode = (*tnode);
    AVLTree BNode = (*tnode) -> right;
    AVLTree BNodeLeft = BNode -> left;
    BNode -> left = ANode;

    ANode -> right = BNodeLeft;

    BNode -> parent = ANode -> parent;

    if(BNodeLeft)
        BNodeLeft -> parent = ANode;

    ANode -> parent = BNode;
    BNode -> bf = ANode -> bf = 0;

    if((*mainTNode) == ANode){
        *mainTNode = BNode;
        return;

    }
    // if(!BNode -> parent){
    //     printf("********************");
    //     return ;
    // }
    if( BNode -> parent -> left == ANode)
        BNode -> parent -> left = BNode;

    else
        BNode -> parent -> right = BNode;
    reassignBalanceFactor(&ANode);
    return;
    AVLTree A = (*tnode);
    AVLTree B = A->right;
    AVLTree BR = B->left;
    AVLTree AP = A->parent;
    B->parent = AP;
    if (!AP)
    {
        *mainTNode = B;
    }
    else
    {
        if (AP->right == A)
        {
            AP->right = B;
        }
        else
        {
            AP->left = B;
        }
    }
    A->parent = B;
    B->left = A;
    A->right = BR;
    if (BR)
    {
        BR->parent = A;
    }
    A->bf = 0;
    B->bf = 0;
    reassignBalanceFactor(&A);  //We have rotated the tree using pointers , now reassingning its bf
}
void LRRotation(AVLTree *tnode, AVLTree *mainTNode)
{
    RRRotation(&(*tnode)->left, mainTNode);     //Rotate left subtree and then rotate that updated tree to right
    LLRotation(tnode, mainTNode);
}

void RLRotation(AVLTree *tnode, AVLTree *mainTNode)
{
    LLRotation(&(*mainTNode)->right, mainTNode); //Rotate right subtree and then rotate that updated tree to left
    RRRotation((tnode), mainTNode);
}


void insertIntoTree(AVLTree *tnode, char *data)
{
    avlTree *newnode = mallocateANode(tnode, data);
    if (!*tnode)
    {
        *tnode = newnode;
        return;
    }
    AVLTree p = *tnode, q = NULL;

    while (p)
    {
        q = p;
        int result = strcmp(p->data, data);     //Return 0 -> strings are equal , 1 -> First string is greater, 2 -> second string is greater
        if (result == 0)
        {
            free(newnode);
            return;
        }
        else if (result > 0)        //If string 1 is greater , go left
            p = p->left;
        else
            p = p->right;
    }
    int res = strcmp(q->data, data);
    if (res > 0)
        q->left = newnode;

    else
        q->right = newnode;

    newnode->parent = q;
   
    reassignBalanceFactor(&q);      //Reassinging balanace factor and  getting imbalanced node

    AVLTree imBalancedNode = getImBalancedNode(&q);
    if (!imBalancedNode)
        return;
    if (imBalancedNode->bf == -2)
    {

        if (imBalancedNode->right->bf == -1)
            RRRotation(&imBalancedNode, tnode);
        else
        {

            RLRotation(&imBalancedNode, tnode);
        }
    }
    else if (imBalancedNode->bf == 2)
    {

        if (imBalancedNode->left->bf == 1)
            LLRotation(&imBalancedNode, tnode);
        else
            LRRotation(&imBalancedNode, tnode);
    }
}

void inOrder(AVLTree tnode)
{
    if (!tnode)
        return;

    inOrder(tnode->left);
    printf("Node: %s , Parent : %s ,BF : %d , Left : %s , Right : %s\n", tnode->data,
           tnode->parent ? tnode->parent->data : "", tnode->bf, tnode->left ? tnode->left->data : "", tnode->right ? tnode->right->data : "");
    inOrder(tnode->right);
}
void preOrder(AVLTree tnode)
{

    if (!tnode)
    {
        return;
    }

    printf("N: %s  ,BF : %d , L : %s , R : %s\n", tnode ? tnode->data : "",
           tnode->bf, tnode->left ? tnode->left->data : "", tnode->right ? tnode->right->data : "");

    preOrder(tnode->left);
    preOrder(tnode->right);
}
void postOrder(AVLTree tNode)
{
    if (!tNode)
    {
        return;
    }

    postOrder(tNode->left);
    postOrder(tNode->right);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int heightOfTree(AVLTree tNode)
{
    if (!tNode)
        return -1;

    return 1 + max(heightOfTree(tNode->left), heightOfTree(tNode->right));
}
AVLTree removeNodeRecursive(AVLTree *root, char *data)
{
    if (!*root)
    {
        return NULL;
    }
    AVLTree tnode = *root;
    int result = strcmp(tnode->data, data);
    if (result == 0)
    {
        // 0 Child
        if (!tnode->left && !tnode->right)
        {
            return NULL;
        }
        // 1 Child (Right)
        if (!tnode->left && tnode->right)
        {
            AVLTree temp = tnode->right;
            free(tnode);
            return temp;
        }
        // 1 Child (Left)

        if (tnode->left && !tnode->right)
        {
            AVLTree temp = tnode->left;
            free(tnode);
            return temp;
        }

        // 2 Childs
        if (tnode->left && tnode->right)
        {
            AVLTree temp = tnode->left;
            if (!temp->right)
            {
                tnode->left = temp->left;
            }

            while (temp && temp->right)
            {
                temp = temp->right;
            }
            tnode->data = (char *)malloc(sizeof(temp));
            strcpy(tnode->data, temp->data);
        }
    }
    else if (result > 0)
    {
        tnode->left = removeNodeRecursive(&tnode->left, data);
    }
    else
    {
        tnode->right = removeNodeRecursive(&tnode->right, data);
    }
}

void removeNodeHelper(AVLTree* parent)
{
    reassignBalanceFactor(parent);

    AVLTree imBalancedNode = getImBalancedNode(parent);
    if (!imBalancedNode)
        return;
    printf("\nImbalaned Node : %s , bf : %d\n", imBalancedNode->data, imBalancedNode->bf);
    if (imBalancedNode->bf == -2)
    {
        if (imBalancedNode->right->bf == -1)
            RRRotation(&imBalancedNode, parent);
        else
        {
            RLRotation(&imBalancedNode, parent);
        }
    }
    else if (imBalancedNode->bf == 2)
    {
        if (imBalancedNode->left->bf == 1)
            LLRotation(&imBalancedNode, parent);
        else
            LRRotation(&imBalancedNode, parent);
    }
}

void removeNode(AVLTree *tnode, char *data)
{
    avlTree *p, *q;
    if (!*tnode)
    {
        return;
    }

    p = *tnode;
    while (p)
    {
        int result = strcmp(p->data, data);
        if (result == 0)
            break;
        q = p; // Search for presence of node and make pointer q following p
        if (result > 0)
            p = p->left;
        else
            p = p->right;
    }
    if (p)
    {
        printf("\n%s", p->data);
        printf(" Found \n");
    }
    if (!p)
    {
        printf("\nNot Found \n");
        return; // Node not present
    }
    // Now 4 cases

    // leaf node
    if (!p->right && !p->left)
    {

        avlTree *deleteNode = p;
        AVLTree temp = deleteNode->parent;
        if (p == *tnode) // There is only 1 node (root node)
            *tnode = NULL;

        else
        {
            if (q->left == p)
            {
                q->left = NULL;
            }
            else
            {
                q->right = NULL;
            }
        }
        free(deleteNode);
        removeNodeHelper(&temp);
        // while((*tnode) -> parent &&(*tnode) -> parent -> parent){
        //     (*tnode) = (*tnode) -> parent;
        // }
        // printf("\n Node : %s \n",temp -> data);
        // printf("\n Node2  : %s \n",(*tnode) -> data);

        if((*tnode) -> parent == (temp))
        *tnode = temp;
        return;
    }

    if (!p->right && p->left)
    {
        AVLTree deleteNode = p;
        AVLTree temp = deleteNode->parent;
        if (p == *tnode) // There is root with only left child
            *tnode = p->left;

        else
        {
            if (q->left == p)
            {

                q->left = p->left;
            }
            else
            {
                q->right = p->left;
            }
        }
        // free(deleteNode);
        removeNodeHelper(&temp);
        if((*tnode) -> parent == (temp))
        *tnode = temp;

        return;
    }

    if (p->right && !p->left)
    {
        avlTree *deleteNode = p;
        AVLTree temp = deleteNode->parent;
        if (p == *tnode)
        {
            *tnode = p->right;
        }
        else
        {
            if (q->left == p)
                q->left = p->right;

            else
                q->right = p->right;
        }
        // free(deleteNode);
        removeNodeHelper(&temp);
        if((*tnode) -> parent == (temp))
        *tnode = temp;

        return;
    }
    if (p->right && p->left)
    {

        avlTree *temp, *preecedingPointer; // There is root with left and right child
        preecedingPointer = p->left;
        temp = preecedingPointer->right;
        AVLTree parentOfTemp = NULL;
        if (!temp)
        {

            p->data = (char *)malloc(sizeof(preecedingPointer->data));
            strcpy(p->data, preecedingPointer->data);
            // p -> data = preecedingPointer -> data;
            p->left = preecedingPointer->left;
            parentOfTemp = preecedingPointer->parent;
            free(preecedingPointer);
        }
        else
        {
            while (temp->right)
            {
                preecedingPointer = temp;
                temp = temp->right;
            }
            char *tempo = temp->data;
            (p)->data = (char *)malloc(sizeof(p->data));
            strcpy(p->data, temp->data);

            parentOfTemp = preecedingPointer;
            preecedingPointer->right = NULL;
            free(temp);
        }
        removeNodeHelper(&parentOfTemp);
        if((*tnode) -> parent == parentOfTemp)
        *tnode = parentOfTemp;
 
        return;
    }
}

void destroyTree(AVLTree *tnode)
{
    if (!(*tnode))
    {
        return;
    }

    destroyTree(&(*tnode)->left);
    destroyTree(&(*tnode)->right);
    printf("\n%s Deleted\n", (*tnode)->data);
    free(*tnode);
    *tnode = NULL;
    return;
}