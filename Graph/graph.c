#include "graph.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "Queue/back.h"

void initGraph(graph* g){
    FILE *fp;
    fp = fopen("input","r");

    if(!fp)
        return ;

    int size = 0;
    fscanf(fp,"%d",&size);
    g -> size = size;
    g -> A =  (int**)malloc(sizeof(int*)*size);
    for(int i = 0 ; i < size ; i++){
        g -> A[i] = (int*)malloc(sizeof(int)*size);
        for(int j = 0 ; j < size ;j++){
            fscanf(fp,"%d",&g -> A[i][j]);
        }
    }
}
int isEmptyGraph(graph g){
    return g.size == 0;
}
int isGraphNULLOrInaccessible(graph g,int index){
    return (isEmptyGraph(g)|| g.size <= index || index < 0);
}

void display(graph g){
    int size = g.size;
     for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ;j++){
            printf("%d ",g.A[i][j]);
        }
    }
    printf("\n");
}

void BFS(graph g,int s){
    if(isGraphNULLOrInaccessible(g,s)){
        return;
    }
    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    Queue q;
    initQueue(&q);
    enqueue(&q,s);
    visited[s] = 1;
    int v;
    int n = g.size;
    int temp = 0 ;

    while(!isEmpty(q)){
         v = dequeue(&q);
         printf("%d ",v);

    //look for all non visited adjacent vertices of v and then enqueue them
    for(int i = 0 ; i < n ; i++){
        if(g.A[v][i] && !visited[i]){
            enqueue(&q,i);
            visited[i] = 1;
        }
    }
    }
    free(visited);
    return ;
}

int displayDegreeOfSpecifiedVertex(graph g ,int v){
    if(isGraphNULLOrInaccessible(g,v)){
        return 0;
    }
    int count = 0 ;
    for(int  i = 0 ; i < g.size ; i++ ){
        if(g.A[v][i])
            count++;
    }
    return count;
}
void degreeOfEachVertex(graph g){   //Degree of each vertex
    if(isEmptyGraph(g))
        return ;
    printf("\n");
    for(int i = 0 ; i < g.size ; i++){
        int degree =  displayDegreeOfSpecifiedVertex(g,i);
        if(!degree){
            printf("vertex out of order");
            return ;
        }
        printf("Degree of Vertex :  %d is %d \n",i,degree);
    }
    printf("\n");

}

int isGraphConnected(graph g){ //Check whether graph is connected or not
    if(isEmptyGraph(g))
        return 0;

    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return INT_MIN;

    int s = 0;
    Queue q;
    initQueue(&q);
    enqueue(&q,s);
    visited[s] = 1;
    int v;
    int n = g.size;
    int temp = 0 ;

    while(!isEmpty(q)){
         v = dequeue(&q);

     //look for all non visited adjacent vertices of v and then enqueue them
    for(int i = 0 ; i < n ; i++){
        if(g.A[v][i] && !visited[i]){
            enqueue(&q,i);
            visited[i] = 1;
        }
    }
    }
    for(int i = 0 ; i < g.size; i++){
        if(!visited[i]){
            free(visited);
            return 0;
        }
    }
    free(visited);
    return 1;
}
int isAdjcantToAnother(graph g,int v,int e){
    if(isGraphNULLOrInaccessible(g,v) && isGraphNULLOrInaccessible(g,e) )
        return 0;

    for(int i = 0 ; i < g.size ; i++){
        if(g.A[v][i] == e)
            return 1;
    }

    return 0;
}

int numberOfComponentsInAGraph(graph g){
   int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return INT_MIN;

    int  n = g.size , v = 0 , countComponents = 0 ;
    int start = 0 ;

    Queue q;
    initQueue(&q);
    do{
        enqueue(&q,start);
        visited[start] = 1;
        int v;

        while(!isEmpty(q)){
            v = dequeue(&q);
            printf("%d ",v);

            for(int i = 0 ; i < n ; i++){
                    if(g.A[v][i] && !visited[i]){
                        enqueue(&q,i);
                        visited[i] = 1;
                    }
            }
        }
        countComponents++;

        int tempStore = start;
        for(int i = 0 ; i < n ; i++){
            if(visited[i] != 1){
                start = i ;
                break;
                }
        }
        if(start == tempStore){
            break;
        }
            
    }
    while(1);
    free(visited);
   
    return countComponents;
}

void displayCycle(Queue q){
    displayQueue(q);
}
void solveProblem(graph g,int s,int e,Queue q,int *visited){
    if(s == e){
        exit(0);
        return ;
    }
   
    for(int i = 0 ; i < g.size; i++){
        if(g.A[s][i] != 0 && !visited[i]  ){
            enqueue(&q,i);
            visited[i] = 1;
            int k = i;
            if(g.A[0][i] == 1 && g.A[i][0] == 1 && getLength(q) > 2)
                k = 0;
            solveProblem(g,k,0,q,visited);

            if(g.A[0][i] == 1 && g.A[i][0] == 1)
                {
                    // enqueue(&q,0);
                    displayCycle(q);
                    // dequeue(&q);
                    return;
                    // dequeue(&q);
                    // visited[i] = 0;
                    // exit(0);
                }
                else{
                    
                }
                
        }
        else{
                    // visited[i] = 0;
                    // dequeue(&q);
            // visited[i] = 0 ;
            // dequeue(&q);
        }
     
    }

}

void printCyclesInGraph(graph g,int s){
    Queue q;
    initQueue(&q);
    enqueue(&q,0);
    
    int *visited = (int*)calloc(g.size,sizeof(int));
    visited[0] = 1;
    solveProblem(g,0,1000,q,visited);

}

/*
0 --------------1
  -           -
     -     -
        2
*/
