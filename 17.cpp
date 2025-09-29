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
int Locate_L(LinkList L)
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        // 读取当前待查找的位置序号（用户输入为1-based索引）
        int target_pos;
        cin >> target_pos;

        if (target_pos < 1 || target_pos > L->length) {
            cout << "Sorry，the book on the best position doesn't exist!" << endl;
            continue; 
        }


        LinkList p = L->next;  // 从首元结点（对应1号位置）开始
        int current_pos = 1;   // 记录当前遍历到的位置（初始为1）


        while (current_pos < target_pos && p != NULL) {
            p = p->next;       // 指针后移
            current_pos++;     // 当前位置计数+1
        }


        cout << p->data.no << " "
             << p->data.name << " "
             << fixed << setprecision(2) << p->data.price << endl;
    }

    return OK;
}