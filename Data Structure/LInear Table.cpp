#include <iostream>
#include<stdio.h>
#include<string.h>
#include "LInear Table.h"
#include"Stack.cpp"
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
}LNode, * LinkList;//链式存储结构

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
	int j = 0;
	LNode* p = L->next;
	if (i == 0)
	{
		return L;
	}
	if (i < 1)
	{
		return L;
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

int Delete_Mini(SqList& L, ElemType x) {
	if (L.length == 0) return false;
	int pos = 0;
	L.data[pos]= L.data[0];
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] < L.data[pos])
			pos = i;
	}
	cout << L.data[pos];
	L.data[pos] = L.data[L.length - 1];
	L.length -= 1;
	return true;
}//P17应用题1

void Reverse(SqList& L) {
	ElemType temp;
	
	for (int i = 0; i < (L.length) / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - 1 - i] = temp;
	}
}//P17应用题2

void Delete_X(SqList& L, ElemType x) {
	ElemType k=0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == x) {
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
	}
	L.length -= k;
}//P17应用题3

bool Delete_range1(SqList& L, ElemType s, ElemType t) {
	int k = 0;
	if (s >= t&&L.length==0) return false;
	
	for (int i = 0; i < L.length&&L.data[i]<t; i++)
	{
		if (L.data[i] > s && L.data[i] < t)
		{
			k++;
		}
		L.data[i - k] = L.data[i];
		L.length -= k;
		return true;
	}
}//P17应用题4

bool Delete_range2(SqList& L, ElemType s, ElemType t) {
	int k = 0;
	if (s >= t && L.length == 0) return false;

	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] > s && L.data[i] < t)
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
	}
		L.length -= k;
		return true;
}//P17应用题5

bool Delete_same(SqList& L) {
	int k = 0;
	if (L.length == 0) return false;
	for (int i = 0; i < L.length-1; i++)
	{
		if (L.data[i] == L.data[i + 1]) 
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];
		}
	}
	L.length -= k;
	return true;
}//P17应用题6

SqList Combine(SqList& L1, SqList& L2) {
	SqList c;
	int i = 0, j = 0, k = 0;
	if (i < L1.length - 1 && j < L2.length - 1)
	{
		if (L1.data[i]<L2.data[j])
		{
			c.data[k++] = L1.data[i++];
		}
		else if (L1.data[i] < L2.data[i])
		{
			c.data[k++] = L2.data[j++];
		}
	}
	if (i == L1.length - 1)
	{
		for (j; j < L2.length; j++)
		{
			c.data[k++] = L2.data[j];
		}
		return c;
	}
	else if (i == L2.length - 1)
	{
		for ( i; i < L1.length; i++)
		{
			c.data[k++] = L1.data[i];
		}
		return c;
	}
	else
		return c;
}//P17应用题7

void Reverse(int a[], int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2,temp=0;
	
	for (int i = 0; i < mid - left; i++)
	{
		temp = a[left+i];
		a[left+i] = a[right-i];
		a[right-i] = temp;
	}
}
void Exchange(int a[], int n, int m) {
	Reverse(a, 0, n+m - 1);
	Reverse(a, 0, n - 1);
	Reverse(a, n, m - 1);
}//P17应用题8

bool Exchange_or_Insert(SqList& L, ElemType x) {
	int low = 0, mid = 0, high = 0;
	high = L.length - 1;
	if (L.data[L.length-1] == x) return;
	while (low<high)
	{
		mid = (high + low) / 2;
		if (L.data[mid] == x && mid != L.length - 1)
		{
			L.data[mid] = L.data[mid + 1];
			L.data[mid + 1] = x;
		}
		else if (L.data[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	for (int i = L.length - 1; i >= high; i--)
		L.data[i + 1] = L.data[i];
	L.data[high] = x;

}//P17应用题9

bool Delete_X2(LinkList& L, ElemType x) {
	LNode* p;
	if (L == NULL) return;
	if (p->data == x)
	{
		p = L;
		L = L->next;
		free(p);
		Delete_X2(L, x);
	}
	else
	{
		Delete_X2(L->next, x);
	}

}//P37应用题1

bool Delete_X3(LinkList& L, ElemType x) {
	LNode* p, * q, * pre;
	q = L->next;
	pre = L;
	while (q!=NULL)
	{
		if (q->data==x)
		{
			p = q;
			q = q->next;
			pre->next = q;
			free(p);
		}
		else
		{
			pre->next = q;
			q = q->next;
		}
	}
}//P38应用题2

void Outprint(LinkList L) {
	ElemType x;
	Sqstack S;
	while (L->next=NULL)
	{
		x = L->data;
		Push(S, x);
		L = L->next;
	}
	while (S.top!=-1)
	{
		Pop(S, x);
	}
}//P38应用题3

LinkList Delete_Mini(LinkList& L) {
	LNode* p, * min, * pre, * minp;
	pre = L->next;
	p = pre->next;
	min = L->next;
	minp = pre;
	while (p!=NULL)
	{
		if (p->data < min->data)
		{
			minp = pre;
			min = p;
		}
		pre = p;
		p = p->next;
	}
	minp->next = min->next;
	free(min);
	return L;
}//P39应用题4

LinkList ReverseLink(LinkList& L) {
	LNode* p, * r;
	p = L->next;
	L->next = NULL;
	while (p!=NULL)
	{
		r = p->next;
		p->next = NULL;
		L->next = p;
		p = r;
	}
	return L;
}//P39应用题5