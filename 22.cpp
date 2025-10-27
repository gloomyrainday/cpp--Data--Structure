#include<iostream>
using namespace std;
#define  MAXSIZE  100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct
{
    int* base;
    int* top;
    int stacksize;
}SqStack;

int InitSqStack(SqStack& S)
{//栈的初始化：分配空间，初始化栈顶指针和栈大小
    S.base = new int[MAXSIZE];  // 分配MAXSIZE大小的数组空间
    if (!S.base) exit(OVERFLOW);  // 内存分配失败则退出
    S.top = S.base;  // 栈顶指针初始指向栈底（空栈）
    S.stacksize = MAXSIZE;  // 栈的最大容量为MAXSIZE
    return OK;
}

int Push(SqStack& S, int e)
{//入栈：将元素e压入栈顶
    if (S.top - S.base >= S.stacksize)  // 栈满判断
        return ERROR;
    *S.top++ = e;  // 元素入栈，栈顶指针上移
    return OK;
}

int Pop(SqStack& S)
{//出栈：将栈顶元素弹出（逻辑删除，移动栈顶指针）
    if (S.top == S.base)  // 栈空判断
        return ERROR;
    S.top--;  // 栈顶指针下移，实现出栈
    return OK;
}

int GetTop(SqStack S)
{//取栈顶元素：返回当前栈顶元素的值
    if (S.top != S.base)  // 栈非空时
        return *(S.top - 1);  // 返回栈顶元素（top指向栈顶下一个位置）
    return -1;  // 栈空时返回无效值（实际使用前需判断栈是否为空）
}

void InOutS(SqStack& S, int a[], int n)
{//处理入栈和出栈操作：ai!=-1时入栈；ai=-1时出栈并输出，异常时输出提示
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            // 元素非-1，执行入栈
            Push(S, a[i]);
        } else {
            // 元素为-1，执行出栈并输出
            if (S.top == S.base) {  // 栈空，出栈异常
                cout << "POP ERROR" << endl;
                break;  // 终止本组数据处理
            } else {
                // 栈非空，输出栈顶元素后出栈
                cout << GetTop(S) << endl;
                Pop(S);
            }
        }
    }
}
