#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int ElemType;
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}Sqstack;//˳��洢�ṹ

void InitStack(Sqstack& S) {
	S.top = -1;
}//��ʼ��


bool StackEmpty(Sqstack& S) {
	if (S.top == -1)
	{
		return true;
	}
	else {
		return false;
	}
}//�п�

bool Push(Sqstack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}//��ջ

bool Pop(Sqstack& S, ElemType x) {
	if (S.top == -1)
	{
		return false;
	}
	x = S.data[S.top--];
	return true;
}//��ջ

bool GetTop(Sqstack& S, ElemType x) {
	if (S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}//��ȡջԪ��

typedef struct LinkNode {
	ElemType data;
	struct Linknode* next;
}*LiStack;//��ʽ�洢�ṹ