#include <stdio.h>
#include "directedGraph.c"
#include "directedGraph.h"




int main (){
char status;
 while(status != 'E'){
    
    printf("wellcome to graphAlgos\n\n currently avilable methods are : \nA to init a new graph.\nB to check for avilable path between two vertexes.\nC to print the shortest path between two vertexes\n\n\n\n\n");
    
    scanf("%c",&status);
    if (status == 'A'){
        initGraph();
        continue;
    }
    
    if (status == 'B'){
        int i,j;
        scanf("%d %d",&i,&j);
        printf("%d",(isReachable(i,j)));
        continue;
    }

    if (status == 'C'){
        int i,j;
        scanf("%d %d",&i,&j);
        if(isReachable(i,j)){
            floydWarshall();
           printf("%d",distMat[i][j]) ;
        }else{
            printf("-1");
        }
        continue;
    }

    if (status == 'D'){
       printGraph(graph);
        continue;
    }
 }


return 1;
}