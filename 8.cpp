#include<iostream>
#include <string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book *elem;                   //存储空间的基地址
    int length;                   //图书表中当前图书个数
}SqList;

int Insert_Sq(SqList &L)
{//新图书的入库和输出
    
    int pos;
    cin >> pos;
    Book new_book;
    cin >> new_book.no    // 读取新图书ISBN
        >> new_book.name  // 读取新图书书名
        >> new_book.price;// 读取新图书价格

    if (pos < 1 || pos > L.length + 1) {
        cout << "Sorry，the position to be inserted is invalid!" << endl;
        return ERROR;
    }


    for (int i = L.length; i >= pos; i--) {
        L.elem[i] = L.elem[i - 1];  
    }

   
    L.elem[pos - 1] = new_book;

   
    L.length++;

    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i].no << " " 
             << L.elem[i].name << " " 
             << fixed << setprecision(2) << L.elem[i].price << endl;
    }

    return OK;
}