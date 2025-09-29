#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int DupRemoval_L(LinkList &L)
{//图书去重：删除书号重复的图书，只保留第一本
    if (L->next == NULL) {
        return OK;
    }

    LinkList p = L->next;
    while (p != NULL && p->next != NULL) {
        LinkList q = p;  
        while (q->next != NULL) {
            if (strcmp(q->next->data.no, p->data.no) == 0) {
                LinkList dup_node = q->next;  
                q->next = dup_node->next;     
                delete dup_node;             
                L->length--;                 
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }

    return OK;
}