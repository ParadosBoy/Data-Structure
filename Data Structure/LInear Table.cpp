#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;//静态分配

#define InitSize 100
typedef struct {
	ElemType* data;
	int MaxSize1, length;
}SeList;//动态分配

bool ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length > MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j + 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}//插入操作

bool ListDelete(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}//删除操作

int LocateElem(SqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}//按值查找

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

LinkList List_HeadInsert(LinkList& L) {
	LNode* s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
};//头插法

LinkList List_TailInsert(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	cin >> x;
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
};//尾插法

LNode* GetElem(LinkList L, int i) {
	int j;
	LNode* p = L->next;
	if (i == 0)
	{
		return L;
	}
	if (i < 1)
	{
		return false;
	}
	while (p && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}//按序号查找

LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}//按值查找

int main()
{
	SeList L;
	L.data = new ElemType[InitSize];
}

bool Delete(SqList L, ElemType x) {
	if (L.length == 0) return false;
	int pos;
	L.data[pos]= L.data[0];
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] < L.data[pos])
			pos = i;
	}
	cout << L.data[pos];
	L.data[pos] = L.data[MaxSize - 1];
	L.length - 1;
	return true;
}//P17应用题1