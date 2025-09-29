#include<iostream>
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
int Delete_L(LinkList &L)
{//出库旧图书并输出
    
    int del_pos;
    cin >> del_pos;

    if (del_pos < 1 || del_pos > L->length) {
        cout << "Sorry，the position to be deleted is invalid!" << endl;
        return ERROR;
    }

  
    LinkList p = L;          // p指向头结点，用于找删除点的前驱
    int current_pos = 0;     // 头结点对应位置0，前驱位置为 del_pos - 1
    while (current_pos < del_pos - 1) {
        p = p->next;         // 指针后移，直到到达前驱结点
        current_pos++;
    }
    LinkList del_node = p->next;  // del_node 指向待删除的结点
    p->next = del_node->next;     // 前驱结点跳过待删除结点，连接后续结点
    delete del_node;              // 释放待删除结点的内存，避免内存泄漏
    L->length--;

   
    LinkList output_p = L->next;  // 从首元结点开始遍历输出
    while (output_p != NULL) {
        cout << output_p->data.no << " "
             << output_p->data.name << " "
             << fixed << setprecision(2) << output_p->data.price << endl;
        output_p = output_p->next;
    }

    return OK;
}