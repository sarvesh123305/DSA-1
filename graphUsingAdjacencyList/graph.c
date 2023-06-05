#include "graph.h"
#include<stdlib.h>
#include<limits.h>
#include "Queue/queue.h"
#include "Stack/stack.h"
#include "minHeap/minHeap.h"

int min(int a,int b){
    return a < b ? a : b ;
}
void appendToLinkdedList(List* L,int weight, int index){
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
        return ;

    newnode -> index = index;
    newnode -> weight = weight;
    newnode -> next = NULL;

    if(!(*L)){
        *L = newnode;
        return;
    }
    Node* temp  = *L;
    while (temp -> next)
    {
        temp = temp -> next;        //Insert to back
    }

    temp -> next = newnode;
    //newnode -> next = *L;       //Insert To Front
    //*L = newnode;
    return;
}

void displayList(List L){
    if(!L){
        return;
    }
    // printf("I : %d , W : %d -> ",L -> index,L -> weight);

    printf("Idx,Weight(%d , %d) -> ",L -> index,L -> weight);
    displayList(L -> next);
}
void initGraph(Graph *g,char* filename){
    FILE *fp;
    fp = fopen(filename,"r");
    
    if(!fp)
        return ;

    int size = 0;
    fscanf(fp,"%d",&size);

    g -> size = size;
    printf("Size : %d\n",size);
    g -> column = (Node**)malloc(sizeof(Node*) * size);
    if(!(g) -> column)
        return ;

    for(int i = 0 ; i < size ; i++){
            g -> column[i] = (Node*) malloc(sizeof(Node));
            if(!g -> column[i]){
                free(g -> column);
                return ;
            }
            g -> column[i] = NULL;
        for(int j = 0 ; j < size; j++){
            int temp ; 
            fscanf(fp,"%d",&temp);
            if(temp != 0)
            appendToLinkdedList(&g -> column[i],temp,j);
        }
    }

    printf("\n");
  
    return ;
}

void displayGraph(Graph g){
    
      for(int i = 0 ; i < g.size; i++){
        List temp = (g).column[i];
        printf("i = %d , ",i);
        displayList(temp);
        printf("\n");
    }

}

int isGraphNULLOrInaccessible(graph g,int v){
    return v >= g.size || g.size == 0 || v < 0;
}

void BFS(graph g,int v){
    if(isGraphNULLOrInaccessible(g,v)){
        return ;
    }
    Queue q;
    initQueue(&q);

    if(!g.column){
        return ;
    }

    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    enqueue(&q,v);
     visited[v] = 1;

    while(!isEmpty(q)){
        int v = dequeue(&q);
        printf("%d ",v);
       
        
        Node* temp = g.column[v]; 
        while(temp)
        {
            if(!visited[temp -> index]){
                enqueue(&q,temp -> index);
                visited[temp -> index] = 1;
            }
            temp = temp -> next;
        }
        
    }
}

void DFS(Graph g,int v){
    if(isGraphNULLOrInaccessible(g,v))
        return ;
    stack st;
    initStack(&st,g.size);

    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    push(&st,v);

    while(!isEmptyStack(st)){
        int node = pop(&st);
        // printf("%d ",node);
        printf("%c ",node + 'A');

        Node* temp = g.column[node];
        while(temp){
             if(temp -> index && !visited[temp -> index]){
                push(&st,temp -> index);
                visited[temp -> index] = 1;
            }
            temp = temp -> next;
        }

    }
}   

SpanningTree primsAlgorithm(Graph g,int v){
   if(isGraphNULLOrInaccessible(g,v))
        return  NULL;
    
    SpanningTree tree = (SpanningTree)malloc(sizeof(Node*)*g.size);
    if(!tree){
        return NULL;
    }
    int totalWeight = 0;
    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited){
        free(tree);
        return NULL;
    }

    int tempWeight = 0;
    int n = g.size;
    for(int i = 0 ; i < n ; i++){
        int minIndex = INT_MAX;
        int Value = INT_MAX;
        appendToLinkdedList(&tree[i],tempWeight,v);
        printf("%d ",v);
        totalWeight += tempWeight  ;
        
        visited[v] = 1;
        for(int j = 0 ; j < n ; j++){
            if(visited[j]){
            Node* temp = g.column[j];
            while(temp){
                if(temp -> weight < Value && !visited[temp -> index]){
                    Value = temp -> weight;
                    minIndex = temp -> index;
                }
                temp = temp -> next;
            }
            }
        }
        v = minIndex;
        tempWeight = Value;
    }
    printf("Weight : %d",totalWeight);
    return tree;        
}
 void printSpanningTree(SpanningTree tree,Graph g){
    printf("\n");
    for(int i = 0 ; i < g.size; i++){
        Node* temp = tree[i];
        printf("\ni = %d  , ",i);
        while(temp){
            printf("%d ",temp -> index);
            printf(" %d",temp -> weight);
            temp = temp -> next;
        }     
        
    }
 }
 
SpanningTree kruskalsAlgorithm(Graph g){  
    int n = g.size;
    minHeap heap;
    initminHeap(&heap,n);
    int countWeight = 0;
    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return NULL;

    int *set = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!set){
        free(visited);
        return NULL;
    }

    SpanningTree tree = (SpanningTree)malloc(sizeof(Node*)*g.size);
    if(!tree){
        free(visited);
        free(set);
        return NULL;
    }
    
    for(int i = 0 ; i < n ; i++){
        set[i] = i ;
    }   

    for(int i = 0 ; i < n; i++){
        Node* temp = g.column[i];
        while (temp)
        {   
            visited[i] = 1;
            if(visited[temp -> index] == 0) 
            // printf("\nStart : %d  , end : %d , weight : %d\n",i,temp -> index,temp ->weight);
            insert(&heap,i,temp -> index,temp -> weight);
            temp = temp -> next;
        }
    }
    int count = 0;
    int j = 0 ;
    do{        
        Data getTop = popNode(&heap);
        if(getTop.weight == INT_MIN)
            break;

        if(set[getTop.start] != set[getTop.end] ) // Indicates both start and end are in diff sets
        {
            appendToLinkdedList(&tree[j],getTop.weight,getTop.start);
            count += getTop.weight; 
            // printf("\nStart : %c  , end : %c , weight : %d\n",getTop.start+ 'A',getTop.end+'A',getTop.weight);
            int temp = set[getTop.end];
            int replace = set[getTop.start];
            for(int i = 0 ; i < n; i++){
                if(set[i] == temp)
                    set[i] = replace;
        }
        }
        j++;
    }
        while(1);
    
        free(set);
        free(visited);
        
        printf("\n%d Weight ", count);
        return tree;
}
int findminIndex(int* cost,int* visited,int n){
    int minIndex,minVal=INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(minVal>cost[i] && !visited[i]){
            minVal=cost[i];
            minIndex=i;
        }
    }
    return minIndex;
}


void dijestra(graph g,int start){
    int n = g.size;
    int *visited = (int*) calloc(n,sizeof(int));
    if(!visited)
        return ;
    int *cost = (int*) malloc(sizeof(int)*n);
    if(!cost)
    {
        free(visited);
        return ;
    }

    for(int i = 0 ; i < n ;i++){
        cost[i] = INT_MAX;
    }
    
    cost[start] = 0;
    int mini ,minIndex ;
    
    for(int i = 0 ; i < n ; i++){
        int index=findminIndex(cost,visited,n);
        visited[index] = 1;

        Node* temp = g.column[index];
        while(temp ){
            int vertex=temp->index;
            if(cost[index] + temp -> weight < cost[vertex])
                cost[vertex] = cost[index] + temp -> weight;
            temp=temp->next;
        }
        
    }
    for(int i = 0 ; i < n ;i++){
            printf("%d ",cost[i]);
    }
    free(cost);
    free(visited);
} 