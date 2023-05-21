#include "graph.h"
#include<stdio.h>
#include<stdlib.h>
#include "../genericQueue/queue.h"

void initGraph(graph* g){
    FILE *fp;
    fp = fopen("input","r");

    if(!fp){
        return ;
    }
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
    int *visited = (int*)calloc(g.size,sizeof(int)); //calloc beacuse bydefault it makes it 0
    if(!visited)
    return;

    Queue q;
    initQueue(&q,sizeof(g));
    enqueue(&q,&s);
    visited[s] = 1;
    int v;
    int n = g.size;

    // int temp = 0 ;
        //  dequeue(&q,&temp);
        //  printf("%d",temp);

    while(getQueueSize(&q) != 0){
         dequeue(&q,&v);
         printf("%d",v);

// //look for all non visited adjacent vertices of v and then enqueue them
    for(int i = 0 ; i < n ; i++){
        if(g.A[v][i] && !visited[i]){
            enqueue(&q,&i);
            visited[i] = 1;
        }
    }
    }
}