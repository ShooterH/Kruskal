#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
typedef struct graph
{
    int v;
    int e;
} graph_init_t;
typedef struct graph_data
{
    int **graph;
    int *weight;
    int v;
    int e;
} graph_data_t;
/**
 * @brief 打印出该图的关联矩阵
 * 
 * @param src 图数据
 * @param no_weight 是否输出权重
 */
void print_graph(graph_data_t src, int no_weight);
/**
 * @brief 结构体初始化
 * 
 * @param g 结构体配置
 * @param dst 结果
 */
void graph_init(graph_init_t g, graph_data_t **dst);
/**
 * @brief 将输入的数据存入结构体
 * 
 * @param src 存放数据
 * @param e 边数目
 * @param graph_src 关联矩阵
 * @param weight 权重
 */
void graph_generate(graph_data_t *src, int e, int graph_src[][e], int weight[]);