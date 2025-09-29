#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000                                  //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[20];                                        //图书ISBN
    char name[60];                                     //图书名字
    float price;                                       //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book *elem;                                         //存储空间的基地址
    int length;                                        //图书表中当前图书个数
}SqList;


int Input_Sq(SqList &L)
{
    int n;
    cin >> n;
    if (n < 0 || n > MAXSIZE) {
        return ERROR; 
    }
    for (int i = 0; i < n; i++) {
      
        cin >> L.elem[i].no    // 读取书号（char[20]）
            >> L.elem[i].name  // 读取书名（char[60]）
            >> L.elem[i].price;// 读取价格（float）
    }
   
    L.length = n;

    for (int i = 0; i < n / 2; i++) {
       
        Book temp = L.elem[i];
       
        L.elem[i] = L.elem[n - 1 - i];
        L.elem[n - 1 - i] = temp;
    }
    return OK; 
}