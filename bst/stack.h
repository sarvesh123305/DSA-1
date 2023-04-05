typedef struct LinkedStack{
    int data;
    struct LinkedStack *next;
}LinkedList;

typedef LinkedList* List;
typedef struct Stack{
    List top;
}Stack;


void initStack(Stack*);
void pushS(Stack*,Tree t);
List pop(Stack*);
int isEmpty(Stack);

