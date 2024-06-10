#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "graph_matrix.h"

#ifndef DEBUG
#define DEBUG 0
#endif

int getTreeIndex(list_ptr *root, int n, int e)
{
    for (size_t i = 0; i <= n; i++)
    {
        if (Linkedlist_FindAll(root[i], e))
            return i;
    }
    return -1;
}
int int_comp_up(const void *a, const void *b)
{
    int *num1 = *(const int **)a;
    int *num2 = *(const int **)b;
    return (*num1 > *num2) - (*num1 < *num2);
}
void refreshList(list_ptr *root, int start, int end)
{
    for (size_t i = start; i < end; i++)
    {
        root[i] = root[i + 1];
    }
}
void Kruskal(graph_data_t raw_data, graph_data_t *mst)
{
    if (DEBUG)
        printf("in function kruskal:\n");
    int e = 0;
    int **e_sorted_ptr = (int **)malloc(raw_data.e * sizeof(int *));
    for (size_t i = 0; i < raw_data.e; i++)
    {
        e_sorted_ptr[i] = &raw_data.weight[i];
    }
    qsort(e_sorted_ptr, raw_data.e, sizeof(int *), int_comp_up);
    // 创建链表
    list_ptr mst_linkedlist = NULL;
    Linkedlist_CreateR(&mst_linkedlist, NULL, 0);
    if (DEBUG)
        printf("Kruskal:mst linkedlist created\n");

    list_ptr *root = (list_ptr *)malloc(raw_data.v * sizeof(list_ptr));
    for (size_t i = 0; i < raw_data.v; i++)
        Linkedlist_CreateR(&(root[i]), NULL, 0);
    if (DEBUG)
        printf("Kruskal:root linkedlist created\n");
    int max_child_tree = -1;
    int tmp[2] = {0};
    int v = 0;
    for (size_t i = 0; i < raw_data.e; i++)
    {
        e = (e_sorted_ptr[i]) - raw_data.weight;
        v = -1;
        tmp[0] = 0;
        tmp[1] = 0;
        for (size_t j = 0; j < raw_data.v; j++)
        {

            // 找出该边关联的两个顶点
            if (raw_data.graph[j][e] == 1)
            {
                v++;
                //查找该节点是否在已有子树中出现
                tmp[v] = getTreeIndex(root, max_child_tree + 1, j);
                if (tmp[v] == -1)
                {
                    max_child_tree++;
                    tmp[v] = max_child_tree;
                    Linkedlist_Append(root[max_child_tree], j);
                }
            }
        }
        //两个顶点属于不同子树时，添加其所关联的边
        if (tmp[0] != tmp[1])
        {
            Linkedlist_Append(mst_linkedlist, e);
            //合并子树
            Linkedlist_Connect(root[tmp[0]], root[tmp[1]]);
            // Linkedlist_Destroy_keep(root[tmp[1]]);
            refreshList(root, tmp[1], max_child_tree);
            //子树数量减一
            max_child_tree--;
        }
        if (DEBUG)
            printf("current index of e %d\n", e);
    }
    if (DEBUG)
    {
        Linkedlist_DisplayAll(mst_linkedlist);
        printf("\ndone\n");
    }
    for (size_t i = 0; i < raw_data.e; i++)
    {
        if (!Linkedlist_FindAll(mst_linkedlist, i))
        {
            for (size_t j = 0; j < raw_data.v; j++)
            {
                (mst->graph)[j][i] = 0;
            }
        }
    }
}
int main(void)
{
    graph_init_t graph_config = {
        .e = 10,
        .v = 6};
    int input_graph[6][10] = {
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 1}};
    int input_weight[] = {6, 1, 5, 3, 5, 5, 2, 6, 4, 6};
    graph_data_t *raw_graph = NULL;
    graph_init(graph_config, &raw_graph);
    graph_generate(raw_graph, graph_config.e, input_graph, input_weight);
    print_graph(*raw_graph, 0);
    graph_data_t mst_graph = *raw_graph;
    Kruskal(*raw_graph, &mst_graph);
    print_graph(mst_graph, 1);
    return 0;
}