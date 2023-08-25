#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graphs
{
    int V;
    bool **adj;
} Graph;

Graph *Graph_create(int V)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;

    g->adj = (bool **)malloc(V * sizeof(bool *));
    for (int i = 0; i < V; i++)
    {
        g->adj[i] = (bool *)malloc(V * sizeof(bool));
        for (int j = 0; j < V; j++)
        {
            g->adj[i][j] = false;
        }
    }

    return g;
}

void add_edge(Graph *g, int src, int dest)
{
    g->adj[src][dest] = true;
}

void top_sort_func(Graph *g, int v, bool visited[], int stack[], int *top)
{
    int i;
    visited[v] = true;

    for (i = 0; i < g->V; i++)
    {
        if (g->adj[v][i] && !visited[i])
        {
            top_sort_func(g, i, visited, stack, top);
        }
    }
    stack[++(*top)] = v;
}

void topo_sort(Graph *g)
{
    int i, t = -1;
    int *stack = (int *)malloc(g->V * sizeof(int));
    bool visited[g->V];
    for (i = 0; i < g->V; i++)
    {
        visited[i] = false;
    }

    for (i = 0; i < g->V; i++)
    {
        if (!visited[i])
        {
            top_sort_func(g, i, visited, stack, &t);
        }
    }

    while ((t) > -1)
    {
        printf("%d ", stack[t--]);
    }

    for (int i = 0; i < g->V; i++)
    {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);
    free(stack);
}

int main(void)
{
    printf("Enter the number of vertices: ");
    int v;
    scanf("%d", &v);

    Graph *g = Graph_create(v);

    printf("Enter the no of edges: ");
    int e;
    scanf("%d", &e);

    printf("Enter the starting and ending vertex of each edge:\n");
    for (int i = 0; i < e; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        add_edge(g, src, dest);
    }

    printf("The topological sort is as: ");

    topo_sort(g);
}