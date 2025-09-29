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

int HighestPrice_Sq(SqList L)
{
   
    if (L.length == 0) {
        return ERROR;
    }


    float max_price = L.elem[0].price;  // 初始化最高价格为第一本图书的价格
    for (int i = 1; i < L.length; i++) {
        if (L.elem[i].price > max_price) {
            max_price = L.elem[i].price;  // 更新最高价格
        }
    }

 
    int count = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].price == max_price) {
            count++;  // 计数加1
        }
    }

   
    cout << count << endl;  // 输出最高价格图书的数量
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].price == max_price) {
            // 输出图书信息，价格保留两位小数
            cout << L.elem[i].no << " " 
                 << L.elem[i].name << " " 
                 << fixed << setprecision(2) << L.elem[i].price << endl;
        }
    }

    return OK;
}
    