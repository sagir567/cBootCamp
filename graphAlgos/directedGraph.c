#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "directedGraph.h"
static int v=10;
static int visited [10];
static int distMat[10][10];
static int graph [10][10];


void DFS(int i){

    printf("\n%d",i);
    visited[i]=1;
    for(int j=0; j < v; j++)
        if(!visited[j] && graph[i][j]==1)
            DFS(j);
}

void initVisited(){
    for (int i=0;i<v;i++){
        visited[i]=0;
    }
}

int isReachable(int source, int dest){

    if (graph[source][dest]){
        printf("there is a path to vertex %d\n",dest);
        return true;
    }

    visited[source]=1;
    for (int j =0; j<v ;j++){
    
        if(!visited[j] && (graph[source][j])){
            return isReachable(j,dest);
        }
    }
    return false;
    
}


void floydWarshall (){
    initDistMat();
  
    printf("%d\n",v);
    for (int k=1; k < v; k++) {
        for(int i=1; i < v; i++){
            for(int j=1; j < v; j++){
                distMat[i][j] = Min(distMat[i][j],distMat[i][k] + distMat[k][j]);
            }
        }
    }
}

void initDistMat()
{
    for (int i = 0; i <v; i++)
    { 
        for (int j = 0; j < v; j++)
        {
            if (i == j)continue;

            else if(graph[i][j]==0){
                distMat[i][j] = inf;
            }
            else 
            {
                distMat[i][j] = graph[i][j];
            }
            
        }
    }
}

void printGraph(int graph[10][10])
{
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            printf("| %d |", graph[i][j]);
        }
        printf("\n");
        for (int j = 0; j < 15; j++)
        {
            printf("____");
        }
        printf("\n");
    }
   
}

void initGraph()
{
    initVisited;
    printf("you have requested to init an 10 * 10 size graph\n if you want to create an edge between vertex i to vertex j enter the edge distance, else ente 0\n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == j)
            {
                graph[i][j] = 0;
                continue;
            }
            
            printf("whould you like to add edge from vertex %d to vertex %d ???\n please add the edge distance", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
     v =(int)(sizeof(graph[0])/sizeof(graph[0][0]));
}

