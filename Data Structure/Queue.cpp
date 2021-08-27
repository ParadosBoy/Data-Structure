#include <iostream>
#include<stdio.h>
#include<string.h>
#include"Stack.cpp"
using namespace std;
typedef int ElemType;
#define MaxSize 50

typedef struct {
    ElemType date[MaxSize];
    int front, rear;
}SqQueue;//顺序存储结构

void InitQueue(SqQueue& Q) {
    Q.rear = Q.front = 0;
}//初始化

bool isEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}//判空

bool EnQueue(SqQueue& Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
    {
        return false;
    }
    Q.date[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}//进队

bool DeQueue(SqQueue& Q, ElemType x) {
    if (Q.front == Q.rear)
    {
        return false;
    }
    x = Q.date[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}//出队

typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
}LinkNode;
typedef struct {
    LinkNode* front, * rear;
}LinkQueue;//链式存储结构

void InitQueue(LinkQueue& Q) {
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}//初始化

bool IsEmpty(LinkQueue& Q) {
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}//判空

void EnQueue(LinkQueue& Q, ElemType x) {
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}//入队

bool DeQueue(LinkQueue& Q, ElemType& x) {
    if (Q.front == Q.rear)
    {
        return false;
    }
    LinkNode* p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear = p)
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}//出队

typedef struct {
    ElemType date[MaxSize];
    int front, rear, tag;
}SQueue;
bool EnQueue(SQueue& S, ElemType x) {
    if (S.front==S.rear&&S.tag==1)
    {
        return false;
    }
    else
    {
        S.date[S.rear] = x;
        S.rear = (S.rear + 1) % MaxSize;
        S.tag = 1;
        return true;
    }
}
bool DeQueue(SQueue& S, ElemType x) {
    if (S.rear==S.front&&S.tag==0)
    {
        return false;
    }
    else
    {
        x = S.date[S.front];
        S.front = (S.front + 1) % MaxSize;
        S.tag = 0;
        return true;
    }
}//P80应用题1

void Reverse(SqQueue& Q) {
    ElemType x = 0;
    Sqstack S;
    while (!isEmpty)
    {
        DeQueue(Q, x);
        Push(S, x);
    }
    while (!StackEmpty)
    {
        Pop(S, x);
        EnQueue(Q,x);
    }
}//P80应用题2