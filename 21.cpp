#include <iostream>
#include <cstdlib> // 用于exit函数
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct
{//符号栈
    char* base;
    char* top;
    int stacksize;
}SqStack1;

int InitStack1(SqStack1& S)
{//符号栈初始化
    S.base = new char[MAXSIZE];
    if (!S.base) exit(OVERFLOW); // 内存分配失败
    S.top = S.base;              // 栈顶指针初始指向栈底
    S.stacksize = MAXSIZE;
    return OK;
}

int Push1(SqStack1& S, char e)
{//符号栈入栈
    if (S.top - S.base >= S.stacksize) return ERROR; // 栈满
    *S.top++ = e; // 元素入栈，栈顶指针上移
    return OK;
}

int Pop1(SqStack1& S)
{//符号栈出栈
    if (S.top == S.base) return ERROR; // 栈空
    S.top--; // 栈顶指针下移（逻辑出栈）
    return OK;
}

char GetTop1(SqStack1 S)
{//符号栈取栈顶元素
    if (S.top != S.base) {
        return *(S.top - 1); // 返回栈顶元素
    }
    return '\0'; // 栈空时返回无效字符
}

typedef struct
{//数字栈
    double* base;
    double* top;
    int  stacksize;
}SqStack2;

int InitStack2(SqStack2& S)
{//数字栈初始化
    S.base = new double[MAXSIZE];
    if (!S.base) exit(OVERFLOW); // 内存分配失败
    S.top = S.base;              // 栈顶指针初始指向栈底
    S.stacksize = MAXSIZE;
    return OK;
}

int Push2(SqStack2& S, double e)
{//数字栈入栈
    if (S.top - S.base >= S.stacksize) return ERROR; // 栈满
    *S.top++ = e; // 元素入栈，栈顶指针上移
    return OK;
}

int Pop2(SqStack2& S)
{//数字栈出栈
    if (S.top == S.base) return ERROR; // 栈空
    S.top--; // 栈顶指针下移（逻辑出栈）
    return OK;
}

double GetTop2(SqStack2 S)
{//数字栈取栈顶元素
    if (S.top != S.base) {
        return *(S.top - 1); // 返回栈顶元素
    }
    return 0.0; // 栈空时返回0
}

double Calculate(double a, char op, double b)
{//算术表达式的求值（a op b）
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // 假设输入合法，不处理除零
        default: return 0.0;
    }
}

char Precede(char a, char b)
{//比较运算符优先级（a为栈顶运算符，b为当前运算符）
    // 根据优先级表返回'>'（a优先级高）、'<'（b优先级高）、'='（优先级相等）
    if (a == '=') {
        return (b == '=') ? '=' : '<';
    }
    if (a == '(') {
        return (b == ')') ? '=' : '<';
    }
    if (b == '(') {
        return '<';
    }
    if (b == ')') {
        return '>';
    }
    // 处理+、-、*、/的优先级
    bool a_high = (a == '*' || a == '/');
    bool b_high = (b == '*' || b == '/');
    if (a_high) {
        return (b_high) ? '>' : '>'; // 乘除优先级高于加减，同优先级左结合
    } else {
        return (b_high) ? '<' : '>'; // 加减遇到乘除则优先级低，同优先级左结合
    }
}
