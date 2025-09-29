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
int FindFavorite_L(LinkList &L)
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        // 读取当前待查找的书名
        char target_name[50];
        cin >> target_name;

        int count = 0;
        LinkList p = L->next;  // 从首元结点开始遍历
        while (p != NULL) {
            // 使用strcmp比较书名（区分大小写）
            if (strcmp(p->data.name, target_name) == 0) {
                count++;
            }
            p = p->next;
        }

        
        if (count == 0) {
            cout << "Sorry，there is no your favourite!" << endl;
        } else {
            cout << count << endl;
            p = L->next; 
            while (p != NULL) {
                if (strcmp(p->data.name, target_name) == 0) {
                    cout << p->data.no << " "
                         << p->data.name << " "
                         << fixed << setprecision(2) << p->data.price << endl;
                }
                p = p->next;
            }
        }
    }

    return OK;
}
