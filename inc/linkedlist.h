#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node* next_p;
    struct node* pre_p;
} node_t;
typedef node_t *list_ptr;
/**
 * @brief 后插法创建单链表
 * 
 * @param res 指向链表头的指针的指针
 * @param dat 要放入链表的数据
 * @param n 数组dat的长度
 * @return ** list_ptr 链表头指针
 */
list_ptr Linkedlist_CreateR(list_ptr* res, ElemType dat[], int n);
/**
 * @brief 获取第n个节点的值
 * 
 * @param tar 目标链表
 * @param n 节点序号，头节点序号为0
 * @return ElemType 该节点的值
 */
ElemType Linkedlist_Get(list_ptr tar, unsigned int n);
/**
 * @brief 释放链表
 * 
 * @param res 要释放的链表
 */
void Linkedlist_Destroy(list_ptr res);
void Linkedlist_Destroy_keep(list_ptr res);
/**
 * @brief 拓展链表
 * 
 * @param tar 要拓展的链表 
 * @param dat 新节点存放的数据
 */
void Linkedlist_Append(list_ptr tar, ElemType dat);
/**
 * @brief 打印链表所有节点
 * 
 * @param tar 要打印的链表
 */
void Linkedlist_DisplayAll(list_ptr tar);
void Linkedlist_DisplayAllR(list_ptr tar);
/**
 * @brief 解析列表数据并将符合条件的数据放入另一个链表
 * 
 * @param dest 要放入的链表
 * @param src 要解析的链表 
 * @param Parser 解析函数，&Integer_Parser，&UpperChar_Parser或者&LowerChar_Parser
 * @return list_ptr 所放入数据的链表头指针
 */
list_ptr Linkedlist_Connect(list_ptr dest, list_ptr src);
int Integer_Parser(ElemType dat);
int UpperChar_Parser(ElemType dat);
int LowerChar_Parser(ElemType dat);
//TODO
void Linkedlist_Insert(list_ptr tar, int n, ElemType dat);
void Linkedlist_Delete(list_ptr tar, int n);
ElemType Linkedlist_Find(list_ptr tar, ElemType e);
list_ptr Linkedlist_FindAll(list_ptr tar, ElemType e);