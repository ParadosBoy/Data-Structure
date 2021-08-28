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
}SqQueue;//˳��洢�ṹ

void InitQueue(SqQueue& Q) {
	Q.rear = Q.front = 0;
}//��ʼ��

bool isEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}//�п�

bool EnQueue(SqQueue& Q, ElemType x) {
	if ((Q.rear + 1) % MaxSize == Q.front)
	{
		return false;
	}
	Q.date[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}//����

bool DeQueue(SqQueue& Q, ElemType x) {
	if (Q.front == Q.rear)
	{
		return false;
	}
	x = Q.date[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}//����

typedef struct LinkNode{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;//��ʽ�洢�ṹ

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}//��ʼ��

bool IsEmpty(LinkQueue& Q) {
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}//�п�

void EnQueue(LinkQueue& Q, ElemType x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}//���

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
}//����

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
}//P80Ӧ����1

void Reverse(SqQueue& Q) {
	ElemType x = 0;
	Sqstack S;
	while (!isEmpty(Q))
	{
		DeQueue(Q, x);
		Push(S, x);
	}
	while (!StackEmpty)
	{
		Pop(S, x);
		EnQueue(Q,x);
	}
}//P80Ӧ����2

bool QueueEmpty(Sqstack S1, Sqstack S2) {
	if (S1.top==-1&&S2.top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Enqueue(Sqstack& S1, Sqstack& S2, ElemType x) {
	if (S1.top!=MaxSize-1)
	{
		Push(S1, x);
		return true;
	}
	if (S1.top==MaxSize-1&&S2.top==-1)
	{
		while (S1.top!=-1)
		 {
			Pop(S1, x);
			Push(S2, x);
		 }
	}
	if (S1.top==MaxSize-1&&S2.top==MaxSize-1)
	{
		return false;
	}
}
bool Dequeue(Sqstack& S1, Sqstack& S2, ElemType x) {
	if (S1.top==-1&&S2.top==-1)
	{
		return false;
	}
	if (S2.top!=-1)
	{
		Pop(S2, x);
		return true;
	}
	else if (S2.top==-1&&S1.top!=-1)
	{
		while (S1.top != -1)
		{
			Pop(S1, x);
			Push(S2, x);
		}
		Pop(S2, x);
	}
}//P80Ӧ����3

void Match(char s) {

}

void CrossRiver(SqQueue& Q1, SqQueue& Q2) {
	#define Max 10
	ElemType i = 0;
	ElemType e, j = 0;
	while (j<Max)
	{
		if (i < 4 && !isEmpty(Q1))
		{
			i++;
			j++;
			DeQueue(Q1, e);
		}
		else if (i == 4 && !isEmpty(Q2))
		{
			i = 0;
			j++;
			DeQueue(Q2, e);
		}
		else if (isEmpty(Q1) && i < 4)
		{
			j++;
			DeQueue(Q2, e);
		}
		else if (isEmpty(Q2) && !isEmpty(Q1))
		{
			while (!isEmpty(Q1))
			{
				DeQueue(Q1, e);
			}	
		}
		else if (isEmpty(Q2) && isEmpty(Q1))
		{
			j = 11;
		}
	}
}//P90Ӧ����4