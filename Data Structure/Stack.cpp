#pragma once
#include"Linear Table.cpp"
#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
typedef int ElemType;
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int top;
}Sqstack;//顺序存储结构

void InitStack(Sqstack& S) {
	S.top = -1;
}//初始化


bool StackEmpty(Sqstack& S) {
	if (S.top == -1)
	{
		return true;
	}
	else {
		return false;
	}
}//判空

bool Push(Sqstack& S, ElemType x) {
	if (S.top == MaxSize - 1)
		return false;
	S.data[++S.top] = x;
	return true;
}//进栈

bool Pop(Sqstack& S, ElemType x) {
	if (S.top == -1)
	{
		return false;
	}
	x = S.data[S.top--];
	return true;
}//出栈

bool GetTop(Sqstack& S, ElemType x) {
	if (S.top == -1)
	{
		return false;
	}
	x = S.data[S.top];
	return true;
}//读取栈元素

typedef struct LinkNode {
	ElemType data;
	struct Linknode* next;
}*LiStack;//链式存储结构

bool R_Or_F(char A[]) {
	ElemType i = 0, in = 0, out = 0, stack = 0;
	for (i; i < 8; i++)
	{
		if (A[i]=='O')
		{
			stack--;
		}
		else
		{
			stack++;
		}
		if (stack < 0) return false;
	}
	if (stack != 0)
	{
		return false;
	}
	else return true;
}//P66应用题3

bool Is_Symmetry(LinkList L) {
	LNode* p=L->next;
	Sqstack S;
	StackEmpty(S);
	char x;
	while (p!=NULL)
	{
		Push(S, p->data);
		p = p->next;
	}
	p = L->next;
	while (p!=NULL)
	{
		Pop(S, x);
		if (p->data!=x)
		{
			return false;
		}
		p = p->next;
	}
	return true;
}//P66应用题4