#include<iostream>
#include<string.h>
#include<iomanip>
#include<cmath> // 用于浮点数精度判断
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

int InitList_Sq(SqList &L)
{//构造一个空的顺序表L
    L.elem = new Book[MAXSIZE]; 
    if (!L.elem) {
        return OVERFLOW;
    }
    L.length = 0;                 
    return OK;
}

int Input_Sq(SqList &L)
{
    Book temp;
    while (true) {

        cin >> temp.no >> temp.name >> temp.price;
        if (strcmp(temp.no, "0") == 0 && 
            strcmp(temp.name, "0") == 0 && 
            fabs(temp.price) < 1e-6) {
            break;
        }
        
        if (L.length >= MAXSIZE) {
            return ERROR; 
        }
        
      
        L.elem[L.length] = temp;
        L.length++;
    }
    return OK;
}

int Output_Sq(SqList L)
{
    for (int i = 0; i < L.length; i++) {
        if (i == 0){
            cout<< 8 <<endl;
        }
        cout << L.elem[i].no << " " << L.elem[i].name << " ";
        cout << fixed << setprecision(2) << L.elem[i].price;
        cout << endl;
    }
    cout.unsetf(ios::fixed);
    cout.precision(6); 
    return OK;
}