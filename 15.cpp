#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct
{//图书信息定义
    char no[20];     //图书ISBN
    char name[50];   //图书名字
    float price;     //图书价格
}Book;
typedef struct LNode
{//图书信息表的链式存储结构
    Book data;    	   //结点的数据域
    int length;       //链表的表长，即图书表中图书个数
    struct LNode *next; //指针域
}LNode,*LinkList;
int HighestPrice_L(LinkList L)
{
    if (L->next == NULL) {
        return ERROR;
    }

    float max_price = 0.0;
    LinkList p = L->next;  
    while (p != NULL) {
        if (p->data.price > max_price) {
            max_price = p->data.price;  // 更新最高价格
        }
        p = p->next;
    }

    int max_count = 0;
    p = L->next;  // 重新指向首元结点，再次遍历
    while (p != NULL) {
        if (p->data.price == max_price) {
            max_count++; 
        }
        p = p->next;
    }


    cout << max_count << endl;  // 第一行输出最高价格图书的数量
    p = L->next;  // 第三次遍历，输出所有最高价格图书的信息
    while (p != NULL) {
        if (p->data.price == max_price) {
            cout << p->data.no << " " 
                 << p->data.name << " " 
                 << fixed << setprecision(2) << p->data.price << endl;
        }
        p = p->next;
    }

    return OK;
}