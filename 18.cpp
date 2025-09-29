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
int Insert_L(LinkList &L)
{//将新图书入库并输出
   
    int insert_pos;
    cin >> insert_pos;  // 待插入的位置（1-based）
    
    Book new_book;
    cin >> new_book.no >> new_book.name >> new_book.price;  // 新图书信息

    if (insert_pos < 1 || insert_pos > L->length + 1) {
        cout << "Sorry，the position to be inserted is invalid!" << endl;
        return ERROR;
    }

   
    LinkList p = L;  // 从表头开始
    int current_pos = 0;  // 头结点对应位置0，用于定位插入点前的结点
    
    while (current_pos < insert_pos - 1) {
        p = p->next;
        current_pos++;
    }

   
    LinkList new_node = new LNode;
    new_node->data = new_book;       
    new_node->next = p->next;        
    p->next = new_node;              

   
    L->length++;

    
    LinkList output_p = L->next;  // 从首元结点开始遍历
    while (output_p != NULL) {
        cout << output_p->data.no << " "
             << output_p->data.name << " "
             << fixed << setprecision(2) << output_p->data.price << endl;
        output_p = output_p->next;
    }

    return OK;
}
