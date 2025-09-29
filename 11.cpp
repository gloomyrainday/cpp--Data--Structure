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

int Length_L(LinkList &L)
{
    int book_count = 0;
    LinkList p = L->next; 

   
    while (p != NULL) {    // 当指针未指向链表末尾时
        book_count++;      // 每遇到一个有效结点，图书数量+1
        p = p->next;       // 指针后移，检查下一个结点
    }

   
    cout << book_count << endl;
    L->length = book_count;

    return OK;
}