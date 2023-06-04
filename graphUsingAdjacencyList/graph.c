#include "graph.h"
#include<stdlib.h>
#include<limits.h>
#include "Queue/back.h"
#include "Stack/stack.h"

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
        temp = temp -> next;
    }

    temp -> next = newnode;
    return;
}

void displayList(List L){
    if(!L){
        return;
    }
    printf("Index : %d , Weight : %d \n",L -> index,L -> weight);
    displayList(L -> next);
}
void initGraph(Graph *g){
    FILE *fp;
    fp = fopen("input","r");
    
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
        List check = (g).column[i];
        displayList(check);
        printf("\n");
    }

}

void BFS(graph g,int v){
    if(v >= g.size || g.size == 0 || v < 0 ){
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
        printf("Node : %d\n",v);
        int i = v ;
        
        Node* temp = g.column[i]; 
        while(temp)
        {
            if(temp -> index && !visited[temp -> index]){
                enqueue(&q,temp -> index);
                visited[temp -> index] = 1;
            }
            temp = temp -> next;
        }
        
    }
}

void DFS(Graph g,int v){
    if(g.size == 0 || v >= g.size || v < 0 ){
        return ;
    }
    stack st;
    initStack(&st,100);

    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    push(&st,v);

    while(!isEmptyStack(st)){
        int node = pop(&st);
        printf("%d ",node);

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

void primsAlgorithm(Graph g,int v){
   if(g.size == 0 || v >= g.size || v < 0 )
        return ;
    
    int totalWeight = 0;
    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    int tempWeight = 0;
    int n = g.size;
    for(int i = 0 ; i < n ; i++){
        int minIndex = INT_MAX;
        int Value = INT_MAX;
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
    return ;        
}
