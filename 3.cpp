#include<iostream>
#include<string.h>
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
//ez压力
int RevisePrice_Sq(SqList &L)
{
    double av_price = 0;  
    for (int i = 0; i < L.length; i++){
        av_price += L.elem[i].price;
    }
    av_price = av_price / L.length;  
    for (int i = 0; i < L.length; i++){
        if(L.elem[i].price < av_price){
            L.elem[i].price += 0.2 * L.elem[i].price;  
        }
        else{
            L.elem[i].price += 0.1 * L.elem[i].price;  
        }  
    }
    cout << fixed << setprecision(2) << av_price<<endl;;

    
}  
