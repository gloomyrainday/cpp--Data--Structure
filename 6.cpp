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

int FindFavorite_Sq(SqList L)
{
    int m;
    cin >> m;  // 读取查找次数
    
    // 处理m次查找
    for (int i = 0; i < m; i++) {
        char target[50];
        cin >> target;  // 读取待查找的书名
        
        // 统计匹配数量
        int count = 0;
        for (int j = 0; j < L.length; j++) {
            if (strcmp(L.elem[j].name, target) == 0) {
                count++;
            }
        }
        
        // 输出结果
        if (count == 0) {
            // 查找失败
            cout << "Sorry，there is no your favourite!" << endl;
        } else {
            // 查找成功：输出数量和图书信息
            cout << count << endl;
            for (int j = 0; j < L.length; j++) {
                if (strcmp(L.elem[j].name, target) == 0) {
                    cout << L.elem[j].no << " "
                         << L.elem[j].name << " "
                         << fixed << setprecision(2) << L.elem[j].price << endl;
                }
            }
        }
    }
    
    return OK;
}
    