#include<iostream>
using namespace std;
#define MAXSIZE 100
#define OK 0
#define OVERFLOW -1
#define ERROR -2

typedef struct
{
    int* base;       // 队列存储空间
    int front;       // 队头指针
    int rear;        // 队尾指针
    int tag;         // 标志：0表示空，1表示满（用于front==rear时区分状态）
}SqQueue;

int InitQueue(SqQueue& Q)
{// 初始化空队列
    Q.base = new int[MAXSIZE];  // 分配队列存储空间
    if (!Q.base) return OVERFLOW;  // 内存分配失败
    Q.front = 0;    // 队头初始化为0
    Q.rear = 0;     // 队尾初始化为0
    Q.tag = 0;      // 初始状态为空（tag=0）
    return OK;
}

int EnQueue(SqQueue& Q, int e)
{// 入队：将元素e插入队尾
    // 判断队列是否满（front==rear且tag=1表示满）
    if (Q.front == Q.rear && Q.tag == 1) {
        return ERROR;  // 队列满，入队失败
    }
    Q.base[Q.rear] = e;  // 元素放入队尾位置
    Q.rear = (Q.rear + 1) % MAXSIZE;  // 队尾指针循环后移
    Q.tag = 1;  // 标记本次操作为入队（可能导致满状态）
    return OK;
}

int DeQueue(SqQueue& Q)
{// 出队：删除队头元素并返回其值
    // 判断队列是否空（front==rear且tag=0表示空）
    if (Q.front == Q.rear && Q.tag == 0) {
        return ERROR;  // 队列空，出队失败
    }
    int e = Q.base[Q.front];  // 获取队头元素
    Q.front = (Q.front + 1) % MAXSIZE;  // 队头指针循环后移
    Q.tag = 0;  // 标记本次操作为出队（可能导致空状态）
    return e;   // 返回出队元素
}
