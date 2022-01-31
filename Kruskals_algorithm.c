#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int u;
    int v;
    int w;
} GRAPH;

int *uf_array = NULL;

GRAPH *take_input(int vertices, int edges)
{
    int u, v, w;
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH) * edges);
    uf_array = (int *)malloc(sizeof(int) * vertices);
    if (g == NULL)
    {
        printf("Heap is full!");
        exit(0);
    }
    if (uf_array == NULL)
    {
        printf("Heap is full!");
        exit(0);
    }
    for (int i = 0; i < vertices; i++)
    {
        uf_array[i] = i;
    }
    for (int i = 0; i < edges; i++)
    {
        printf("(%d)Enter the first vertex of the edge: ", i);
        scanf("%d", &u);
        printf("(%d)Enter the second vertex of the edge: ", i);
        scanf("%d", &v);
        if (u > v)
        {
            g[i].u = v;
            g[i].v = u;
        }
        else
        {
            g[i].u = u;
            g[i].v = v;
        }
        printf("(%d)Enter the weight of the edge: ", i);
        scanf("%d", &g[i].w);
        printf("\n\n");
    }
    return g;
}

void swap(GRAPH *g1, GRAPH *g2)
{
    GRAPH *t;
    t = (GRAPH *)malloc(sizeof(GRAPH));
    if (t == NULL)
    {
        printf("Heap is full!");
        exit(0);
    }
    *t = *g1;
    *g1 = *g2;
    *g2 = *t;
    free(t);
}

void bubble_sort(GRAPH *g, int edges)
{
    GRAPH *t;
    t = (GRAPH *)malloc(sizeof(GRAPH));
    for (int i = 0; i < edges - 1; i++)
    {
        for (int j = 0; j < edges - i - 1; j++)
        {
            if (g[j].w > g[j + 1].w)
            {
                swap((g + j), (g + j + 1));
            }
        }
    }
}

void union_f(int a, int b, int vertices)
{
    int p = uf_array[a];
    int q = uf_array[b];
    for (int i = 0; i < vertices; i++)
    {
        if (uf_array[i] == p)
        {
            uf_array[i] = q;
        }
    }
}

int find(int a, int b, int vertices)
{
    if (uf_array[a] == uf_array[b])
        return 1;
    else
        return 0;
}

int kruskals(GRAPH *g, int vertices, int edges)
{
    int weight = 0;
    int count = 0;
    printf("Minimum spanning Tree: \n");
    for (int i = 0; i < edges; i++)
    {
        if (count == vertices - 1)
            break;
        if (!find(g[i].u, g[i].v, vertices))
        {
            printf("%d %d -> %d\n", g[i].u, g[i].v, g[i].w);
            union_f(g[i].u, g[i].v, vertices);
            weight += g[i].w;
            count++;
        }
    }
    return weight;
}

int main()
{
    int vertices, edges, weight;
    GRAPH *g;
    printf("Minimum spanning tree using Kruskals Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    g = take_input(vertices, edges);
    bubble_sort(g, edges);
    weight = kruskals(g, vertices, edges);
    printf("\nThe total cost is: %d", weight);
    return 0;
}