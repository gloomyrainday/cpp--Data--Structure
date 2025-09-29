#include<iostream>
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
int Delete_Sq(SqList &L)
{
    int del_pos;
    cin >> del_pos;


    if (del_pos < 1 || del_pos > L.length) {
        // 删除失败：输出指定提示
        cout << "Sorry，the position to be deleted is invalid!" << endl;
        return ERROR;
    }

    int del_idx = del_pos - 1;  // 转换为顺序表的0-based索引
    for (int i = del_idx; i < L.length - 1; i++) {
        L.elem[i] = L.elem[i + 1];  // 元素前移1位
    }

    L.length--;

    for (int i = 0; i < L.length; i++) {
        cout << L.elem[i].no << " " 
             << L.elem[i].name << " " 
             << fixed << setprecision(2) << L.elem[i].price << endl;
    }

    return OK;
}