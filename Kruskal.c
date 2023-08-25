#include <stdio.h>

int find(int v, int *parent)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j, int *parent)
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int main(void)
{
    printf("Enter the number of vertices: ");
    int n;
    scanf("%d", &n);

    printf("Enter the adjacency matrix(use 999 as infinity):\n");
    int adj[n][n];
    int i;
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int parent[n];
    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0, k = 0, min, sum = 0, j, t[n][n], u, v;

    while (count != n - 1)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (adj[i][j] < min && adj[i][j] != 0)
                {
                    min = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        i = find(u, parent);
        j = find(v, parent);

        if (i != j)
        {
            union1(i, j, parent);
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum = sum + adj[u][v];
        }
        adj[u][v] = adj[v][u] = 999;
    }

    if (count == n - 1)
    {
        printf("The minimal spanning tree is as:\n");
        for (i = 0; i < n - 1; i++)
        {
            printf("%d -> %d\n", t[i][0], t[i][1]);
        }
        printf("Cost of spanning tree = %d\n", sum);
    }
    else
    {
        printf("\nSpanning tree does not exist!");
    }
}