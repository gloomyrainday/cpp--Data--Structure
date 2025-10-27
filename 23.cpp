#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct
{
    char* base;
    char* top;
    int stacksize;
}SqStack;

int InitStack(SqStack& S)
{//初始化栈：分配空间，设置空栈状态
    S.base = new char[MAXSIZE];
    if (!S.base) exit(OVERFLOW); // 内存分配失败
    S.top = S.base;              // 栈顶=栈底，空栈
    S.stacksize = MAXSIZE;
    return OK;
}

// 修正：补充入栈元素参数e（原函数缺省，需添加以实现入栈逻辑）
int Push(SqStack& S, char e)
{//入栈：将元素e压入栈顶
    if (S.top - S.base >= S.stacksize) return ERROR; // 栈满
    *S.top++ = e; // 元素入栈，栈顶指针上移
    return OK;
}

int Pop(SqStack& S)
{//出栈：弹出栈顶元素（逻辑删除）
    if (S.top == S.base) return ERROR; // 栈空，出栈失败
    S.top--; // 栈顶指针下移，实现出栈
    return OK;
}

int IsEmpty(SqStack S)
{//判断栈是否为空：空返回1，非空返回0
    return (S.top == S.base) ? 1 : 0;
}

bool Judge(char a[], SqStack& S)
{//判断IO序列是否合法：合法返回true，否则false
    for (int i = 0; a[i] != '\0'; i++) {
        if (a[i] == 'I') {
            // 遇到入栈操作，执行Push
            Push(S, 'I'); // 压入任意标记（此处用'I'），仅需记录入栈状态
        } else if (a[i] == 'O') {
            // 遇到出栈操作，先判断栈是否为空
            if (IsEmpty(S) == 1) {
                return false; // 栈空时出栈，序列非法
            }
            Pop(S); // 栈非空，执行出栈
        } else {
            // 出现非I/O字符，序列非法
            return false;
        }
    }
    // 序列遍历结束后，栈需为空（终态为空）
    return (IsEmpty(S) == 1) ? true : false;
}
