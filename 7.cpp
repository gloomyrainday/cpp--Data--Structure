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

int FindLocate_Sq(SqList L)
{//查找最佳位置图书并输出数据
   
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        // 读取当前待查找的位置序号（用户输入为1-based索引）
        int target_pos;
        cin >> target_pos;

        
        if (target_pos < 1 || target_pos > L.length) {
            
            cout << "Sorry，the book on the best position doesn't exist!" << endl;
        } else {
        
            int idx = target_pos - 1;
            cout << L.elem[idx].no << " ";
            cout << L.elem[idx].name << " ";
            cout << fixed << setprecision(2) << L.elem[idx].price << endl;
        }
    }

    return OK;
}