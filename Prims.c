#include <stdio.h>

int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    int adj[n][n];
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int visited[n];
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex: ");
    int start;
    scanf("%d", &start);
    visited[start] = 1;

    printf("\nThe minimal spanning tree is:\nEdge : Weight\n");
    for (k = 0; k < n - 1; k++)
    {
        int min = 999;
        int u = 0;
        int v = 0;
        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && adj[i][j])
                    {
                        if (min > adj[i][j])
                        {
                            min = adj[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", u, v, adj[u][v]);
        visited[v] = 1;
    }
}