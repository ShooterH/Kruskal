#include "graph_matrix.h"
#define DEBUG 0
void print_graph(graph_data_t src, int no_weight)
{
    for (size_t i = 0; i < src.e; i++)
        printf("\te%d",i);
    printf("\n");
    for (size_t i = 0; i < src.v; i++)
    {
        printf("v%d\t",i);
        for (size_t j = 0; j < src.e; j++)
        {
            printf("%d\t", src.graph[i][j]);
        }
        printf("\n");
    }
    if (!no_weight)
    {
        printf("\nweight: ");
        for (size_t j = 0; j < src.e; j++)
        {
            printf("%d\t", src.weight[j]);
        }
        printf("\n");
    }

    printf("\n");
}
void graph_init(graph_init_t g, graph_data_t **dst)
{
    *dst = malloc(sizeof(graph_data_t));
    (*dst)->e = g.e;
    (*dst)->v = g.v;
    (*dst)->weight = malloc(g.e * sizeof(int));
    (*dst)->graph = (int **)malloc(g.v * sizeof(int *));
    for (size_t i = 0; i < g.v; i++)
    {
        ((*dst)->graph)[i] = malloc(g.e * sizeof(int));
        for (size_t j = 0; j < g.e; j++)
        {
            ((*dst)->graph)[i][j] = 0;
        }
    }
    for (size_t j = 0; j < g.e; j++)
    {
        ((*dst)->weight)[j] = 0;
    }
    if (DEBUG)
    {
        printf("graph_init:init done\t e:%d\t v:%d\n", (*dst)->e, (*dst)->v);
        print_graph(**dst, 0);
    }
}
void graph_generate(graph_data_t *src, int e, int graph_src[][e], int weight[])
{
    for (size_t i = 0; i < src->v; i++)
    {
        for (size_t j = 0; j < src->e; j++)
        {
            (src->graph)[i][j] = graph_src[i][j];
        }
    }
    memcpy(src->weight, weight, src->e * sizeof(int));
}