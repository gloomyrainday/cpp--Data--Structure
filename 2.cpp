#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000
using namespace std;
typedef struct
{
    char no[20];
    char name[60];
    float price;
}Book;
typedef struct
{
    Book *elem;
    int length;
}SqList;
//阿玛特拉斯
int BubbleSort_Sq(SqList L)
{
for (int i = 0; i < L.length; i++) {
    for (int j = 0; j < L.length; j++) {
        if(L.elem[i].price>L.elem[j].price){
            Book temp = L.elem[i];
            L.elem[i] = L.elem[j];
            L.elem[j] = temp ;   
        }

    }  
}
   
}
