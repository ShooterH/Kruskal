#include "linkedlist.h"
#include <stdlib.h>
list_ptr Linkedlist_CreateR(list_ptr *res, ElemType dat[], int n)
{
    list_ptr p, r;
    *res = (list_ptr)malloc(sizeof(node_t));
    (*res)->data = 0;
    (*res)->next_p = NULL;
    (*res)->pre_p = NULL;
    r = *res;
    for (size_t i = 0; i < n; i++)
    {
        p = (list_ptr)malloc(sizeof(node_t));
        if (dat != NULL)
            p->data = dat[i];
        else
            p->data = 0;
        p->next_p = NULL;
        p->pre_p = r;
        r->next_p = p;
        r = p;
    }
    return *res;
}

ElemType Linkedlist_Get(list_ptr tar, unsigned int n)
{
    list_ptr p = tar->next_p;
    unsigned int i = 1;
    while (p && i < n)
    {
        p = p->next_p;
        i++;
    }
    if (i > n)
    {
        return 0;
    }
    return p->data;
}
void Linkedlist_Destroy(list_ptr res)
{
    list_ptr p = res->next_p;
    list_ptr q = p;
    free(res);
    while (p)
    {
        q = p->next_p;
        free(p);
        p = q;
    }
}
void Linkedlist_Destroy_keep(list_ptr res)
{
    list_ptr p = res->next_p;
    list_ptr q = p;
    //free(res);
    while (p)
    {
        q = p->next_p;
        free(p);
        p = q;
    }
}
void Linkedlist_Append(list_ptr tar, ElemType dat)
{
    list_ptr p = tar;
    while (p->next_p)
        p = p->next_p;
    p->next_p = (list_ptr)malloc(sizeof(node_t));
    (p->next_p)->data = dat;
    (p->next_p)->next_p = NULL;
}
list_ptr Linkedlist_Connect(list_ptr dest, list_ptr src)
{
    list_ptr p = src->next_p;
    while (p)
    {
        Linkedlist_Append(dest, p->data);
        p = p->next_p;
    }
    return dest;
}
/*
int Integer_Parser(ElemType dat)
{
    if (dat >= '0' && dat <= '9')
        return 1;
    else
        return 0;
}
int UpperChar_Parser(ElemType dat)
{
    if (dat >= 'A' && dat <= 'Z')
        return 1;
    else
        return 0;
}
int LowerChar_Parser(ElemType dat)
{
    if (dat >= 'a' && dat <= 'z')
        return 1;
    else
        return 0;
}
*/
void Linkedlist_DisplayAll(list_ptr tar)
{
    list_ptr p = tar->next_p;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next_p;
    }
}
void Linkedlist_DisplayAllR(list_ptr tar)
{
    list_ptr p = tar->next_p;
    while (p->next_p)
    {
        //printf("%c\t", p->data);
        p = p->next_p;
    }
    while (p)
    {
        printf("%c\t", p->data);
        p = p->pre_p;
    }
}
void Linkedlist_Delete(list_ptr tar, int n)
{
    list_ptr p = tar->next_p;
    unsigned int i = 1;
    while (p && i < n)
    {
        p = p->next_p;
        i++;
    }
    if (i > n)
    {
        return;
    }
    (p->pre_p)->next_p = p->next_p;
    (p->next_p)->pre_p = p->pre_p;
    free(p);
    return;
}
void Linkedlist_Insert(list_ptr tar, int n, ElemType dat)
{
    list_ptr p = tar->next_p;
    list_ptr e = (list_ptr)malloc(sizeof(node_t));
    e->data = dat;
    e->next_p = NULL;
    e->pre_p = NULL;
    unsigned int i = 1;
    while (p && i < n)
    {
        p = p->next_p;
        i++;
    }
    if (i > n)
    {
        return;
    }
    e->pre_p = p->pre_p;
    p->pre_p = e;
    e->next_p = p;
    (e->pre_p)->next_p = e;
    return;
}
list_ptr Linkedlist_FindAll(list_ptr tar, ElemType e)
{
    list_ptr p = tar->next_p;
    while (p)
    {
        if(p->data == e)
            return p;
        p = p->next_p;
    }
    return NULL;
}