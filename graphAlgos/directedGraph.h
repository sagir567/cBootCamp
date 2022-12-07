#include <stdio.h>
#define inf __INT_MAX__
#define Min(X, Y ) (((X) > (Y) ) ? (Y) : (X))


void initVisited();

/*initilize the distance matrix acording to the graph*/
void initDistMat();

/* will initilize a 10*10 unDirected graph represnted by matrix */
void initGraph(); 

/* will print true for input of two vertex if there is available path from vertex i to vertex j, and print false if non path exist  */
int isReachable(int i, int j);

/* will print the shortest path from vertex i to vertex j , print -1 if non path available */
void shortestPath (int i, int j);

void floydWarshall();

