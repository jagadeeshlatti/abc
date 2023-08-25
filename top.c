#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void DFS(int vertex, int **adjMatrix, bool *visited, int n, int stack[],int *top)
{
   //printf("%d ", vertex);
    visited[vertex] = true;
    for (int adjacent = 0; adjacent < n; adjacent++)
    {
        if (adjMatrix[vertex][adjacent] && !visited[adjacent])
        {
            DFS(adjacent, adjMatrix, visited, n,stack,top);
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
    int **adjMatrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        adjMatrix[i] = (int *)malloc(n * sizeof(int));
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
    int *stack = (int *)malloc(n * sizeof(int));
    
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
