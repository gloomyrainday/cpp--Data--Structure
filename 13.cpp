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
int AveRevise_L(LinkList &L)
{
    if (L->next == NULL) {
        return ERROR;
    }

    
    float total_price = 0.0;
    LinkList p = L->next;  
    while (p != NULL) {
        total_price += p->data.price;  
        p = p->next;
    }
    float avg_price = total_price / L->length;


    p = L->next;  
    while (p != NULL) {
        if (p->data.price < avg_price) {
            p->data.price *= 1.2;
        } else {
            p->data.price *= 1.1;
        }
        p = p->next;
    }

    cout << fixed << setprecision(2) << avg_price << endl;

    return OK;
}