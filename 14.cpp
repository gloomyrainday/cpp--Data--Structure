#include<iostream>
#include<iomanip>
#include <string.h>
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
int Input_L(LinkList &L)
{//链表的输入（前插法实现逆序存储）
    int n;
    cin >> n;
    L->length = n;  

    char no[20];
    char name[50];
    float price;

    for (int i = 0; i < n; i++) {
        cin >> no >> name >> price;
        LinkList newNode = new LNode;
        strcpy(newNode->data.no, no);
        strcpy(newNode->data.name, name);
        newNode->data.price = price;

        
        newNode->next = L->next;  
        L->next = newNode;       
    }

    return OK;
}
