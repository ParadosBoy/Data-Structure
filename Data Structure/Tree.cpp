#include <iostream>
#include<stdio.h>
#include<string.h>
#include"Stack.cpp"
#include"Queue.cpp"
using namespace std;
typedef int ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

typedef struct ThreadNode {
	ElemType data;
	struct ThreadNode* lchild, * rchild;
	int ltag, rtag;
}ThreadNode,* ThreadTree;

ElemType Visit(BiTree T) {
	return T->data;
}

void PreOdrder(BiTree T) {
	if (T != NULL) {
		Visit(T);
		PreOdrder(T->lchild);
		PreOdrder(T->rchild);
	}
}//先序遍历

void InOdrder(BiTree T) {
	if (T != NULL) {
		PreOdrder(T->lchild);
		Visit(T);
		PreOdrder(T->rchild);
	}
}//中序遍历

void PostOdrder(BiTree T) {
	if (T != NULL) {
		PreOdrder(T->lchild);
		PreOdrder(T->rchild);
		Visit(T);
	}
}//后序遍历

void InOrder2(BiTree T) {
	Sqstack S;
	InitStack(S);
	BiTree p = T;
	while (p||!StackEmpty)
	{
		if (p)
		{
			Push(S,p->data);
			p = p->lchild;
		}
		else
		{
			Pop(S, p->data);
			Visit(p);
			p = p->rchild;
		}
	}
}//非递归中序遍历

void PreOrder2(BiTree T) {
	Sqstack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty)
	{
		if (p)
		{
			Visit(p); 
			Push(S, p->data);
			p = p->lchild;
		}
		else
		{
			Pop(S, p->data);
			p = p->rchild;
		}
	}
}//非递归先序遍历

void LevelOrder(BiTree T) {
	SqQueue Q;
	InitQueue(Q);
	BiTree p;
	EnQueue(Q, T->data);
	while (!isEmpty(Q))
	{
		DeQueue(Q, p->data);
		Visit(p);
		if (p->lchild!=NULL)
		{
			EnQueue(Q, p->lchild->data);
		}
		if (p->rchild!=NULL)
		{
			EnQueue(Q, p->rchild->data);
		}
	}
}//层序遍历

int SearchParent(BiTree T[], int i, int j) {
	if (T[i] != NULL && T[j] != NULL)
	{
		while (T[i]!=T[j])
		{
			if (i>j)
			{
				i = i / 2;
			}
			else
			{
				j = j / 2;
			}
		}
	}
	return T[i]->data;
}//P127应用题5