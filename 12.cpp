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

int Sort_L(LinkList &L)
{
    if (L->next == NULL || L->next->next == NULL) {
        return OK;
    }

    int n = L->length;  
    Book* books = new Book[n]; 
    LinkList p = L->next;      
    int i = 0;
    

    while (p != NULL) {
        books[i] = p->data;
        p = p->next;
        i++;
    }

    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // 前一个价格小于后一个时交换（实现降序）
            if (books[j].price < books[j + 1].price) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

  
    p = L->next;  // 重新指向首元结点
    for (i = 0; i < n; i++) {
        p->data = books[i];  // 更新结点数据
        p = p->next;
    }

    delete[] books;
    return OK;
}
    