#include<iostream>
using namespace std;
#define MAXSIZE 100  // 队列最大容量，满足测试用例需求
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct
{
    int* base;   // 队列存储空间
    int front;   // 队头指针（指向队头元素）
    int rear;    // 队尾指针（指向队尾元素的后一个位置，牺牲此位置区分满空）
}SqQueue;

int InitQueue(SqQueue& Q)
{// 构造空队列：front和rear初始化为0（空队列标志：front == rear）
    Q.base = new int[MAXSIZE];
    if (!Q.base) return OVERFLOW;  // 内存分配失败
    Q.front = 0;
    Q.rear = 0;
    return OK;
}

int EnQueue(SqQueue& Q, int e)
{// 队头入队（向下标小的方向）：新元素插入队头，需先判断队列是否满
    // 满队列判断：front的前一个位置（循环左移1位）等于rear（牺牲该位置区分满空）
    if ((Q.front - 1 + MAXSIZE) % MAXSIZE == Q.rear) {
        return ERROR;  // 队列满，入队失败
    }
    // 队头指针循环左移（向下标小的方向）
    Q.front = (Q.front - 1 + MAXSIZE) % MAXSIZE;
    Q.base[Q.front] = e;  // 存入新元素
    return OK;
}

int DeQueue(SqQueue& Q)
{// 队尾出队：删除队尾元素并返回其值，需先判断队列是否空
    if (Q.front == Q.rear) {  // 空队列标志：front == rear
        return ERROR;  // 队列空，出队失败（测试场景中不会触发）
    }
    // 计算队尾元素位置（rear指向队尾后一个位置，需循环左移1位）
    int tail_pos = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
    int e = Q.base[tail_pos];  // 取出队尾元素
    Q.rear = tail_pos;  // 队尾指针左移，指向新的队尾后一个位置
    return e;
}
