
typedef struct stack{
    int size;
    int top;
    int *arr;
}stack;

typedef stack stack;

void initStack(stack *s,int size);
int isFullStack(stack s);
int isEmptyStack(stack s);

void push(stack *s,int data);
int pop(stack *s);
void display(stack s);
