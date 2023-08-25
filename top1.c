#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DFS(int vertex, int adjMatrix[100][100], bool *visited, int n, int stack[],int *top)
{
   //printf("%d ", vertex);
    visited[vertex] = true;
    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[vertex][i] && !visited[i])
        {
            DFS(i, adjMatrix, visited, n,stack,top);
        }
    }
    stack[++(*top)] = vertex;
}


int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);

    printf("Enter the no of edges: ");
    int e;
    scanf("%d", &e);

    int i, j;
   int adjMatrix[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the starting and ending vertex of each edge:\n");
    for (int i = 0; i < e; i++)
    {
            int src, dest;
            scanf("%d %d", &src,&dest);    
            adjMatrix[src][dest] = 1;

    }

    printf("Enter the starting vertex: ");
    int src;
    scanf("%d", &src);

    
    bool visited[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int t=-1;
    // int *stack = (int *)malloc(n * sizeof(int));
      int stack[n];
    
    DFS(src, adjMatrix, visited, n, stack,&t);

    while ((t) > -1)
    {
        printf("%d ", stack[t--]);
    }

    for (i = 0; i < n; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}
