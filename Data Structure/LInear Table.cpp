#include <iostream>
#include<stdio.h>
#include<string.h>
#include"Stack.cpp"
#pragma once
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

typedef struct DNode {
	ElemType data;
	struct DNode* prior, * next, * fred;
}DNode,*DLinklist;

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
	pre = L;
	p = pre->next;
	min = p;
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
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}//P39应用题5

LinkList OrderLink(LinkList& L) {
	LNode* p, * max, * pre, * maxp, * r;
	pre = L->next;
	p = pre->next;
	maxp = L->next;
	max = pre;
	L->next = NULL;
	while (p != NULL)
	{
		if (p->data > max->data)
		{
			maxp = pre;
			max = p;
		}
		pre = p;
		p = p->next;
	}
	maxp->next = max->next;
	while (max!=NULL)
	{
		max->next = L->next;
		L->next = max;
	}
	return L;
}//P38应用题6

void Delete_Range(LinkList& L, int min, int max) {
	LNode* p, * pre, * x;
	pre = L;
	p = pre->next;
	while (p!=NULL)
	{
		if (p->data>min&&p->data<max)
		{
			x = p;
			p = p->next;
			pre->next = p;
			free(x);
		}
		else
		{
			p = p->next;
			pre->next = p;
		}
	}
}//P38应用题7

LinkList Find_Together(LinkList& L1, LinkList& c, LinkList& L2) {
	LNode* p, * q;
	c->next = NULL;
	p = L1->next;
	q = L2->next;
	while (p!=NULL&&q!=NULL)
	{
		for (p;p!=NULL; p=p->next)
		{
			for (q; q!=NULL; q=q->next)
			{
				if (p==q)
				{
					c->next = q;
				}
			}
			
		}
	}
	return c;
}//P38应用题8

void FindMin(LinkList& head) {
	LNode* p, * pre, * min, * minp;
	pre = head;
	p = pre->next;
	min = p;
	minp = pre;
	if (head->next != NULL)
	{
		while (p!=NULL)
			{
				if (p->data<min->data)
				{
					min = p;
					minp = pre;
				}
				p = p->next;
				pre->next = p;
			}
			minp->next = min->next;
			cout << min->data;
			free(min);
			FindMin(head);
	}
	free(head);
}//P38应用题9

LinkList DivisionLink(LinkList& L) {
	LinkList L1 = (LinkList)malloc(sizeof(LNode));;
	LinkList L2 = (LinkList)malloc(sizeof(LNode));
	LNode* p, * q, * s;
	s = L->next;
	p = L1;
	q = L2;
	int k = 0;
	while (s!=NULL)
	{
		if (k%2==1)
		{
			p->next = s;
			p = s;
		}
		else
		{
			q->next = s;
			q = s;
		}
		s = s->next;
		k++;
	}
	p->next = NULL;
	q->next = NULL;
	free(L);
	return L1, L2;
}//P38应用题10

LinkList DivisionLink2(LinkList& A) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	LNode* p, * q, * r;
	r = A->next;
	p = A;
	ElemType k = 0;
	while (r!=NULL)
	{
		if (k%2==0)
		{
			p->next = r;
			p = r;
		}
		else
		{
			q = r;
			q->next = B->next;
			B->next = q;
		}
		r = r->next;
		k++;
	}
}//P38应用题11

void DeleteSame(LinkList& L) {
	LNode* p, * pre, * r;
	p = L->next;
	pre = L;
	while (p!=NULL)
	{
		if (p->data=p->next->data)
		{
			r = p;
			p = p->next;
			free(r);
		}
		else
		{
			pre->next = p;
			pre = p;
			p = p->next;
		}
	}
}//P38应用题12

void OrderTogether(LinkList L1, LinkList L2) {
	LinkList c = (LinkList)malloc(sizeof(LNode));
	LNode* p, * q, * s;
	p = L1->next;
	q = L2->next;
	while (p!=NULL&&q!=NULL)
	{
		if (p->data<q->data)
		{
			s = p->next;
			p->next = c->next;
			c->next = p;
			p = s;
		}
		else
		{
			s = q->next;
			q->next = c->next;
			c->next = q;
			q = s;
		}
	}
	while (p == NULL && q != NULL)
	{
		s = q->next ;
		q->next=c->next;
		c->next = q;
		q = s;
	}
	while (p != NULL && q == NULL)
	{
		s = p->next;
		p->next = c->next;
		c->next = p;
		p = s;
	}
	free(L1);
	free(L2);
}//P38应用题13

void NewTogether(LinkList A, LinkList B) {
	LinkList C = (LinkList)malloc(sizeof(LNode));
	LNode* q, * p, * s;
	p = A->next;
	q = B->next;
	while (p != NULL && q != NULL)
	{
		if (p->data<q->data)
		{
			p = p->next;
		}
		else if (q->data<p->data)
		{
			q = q->next;
		}
		else
		{
			s = (LNode*)malloc(sizeof(LNode));
			s->data = p->data;
			s->next = C->next;
			C->next = s;
			p = p->next;
			q = q->next;
		}
	}
}//P38应用题14

LinkList Together(LinkList& A, LinkList& B) {
	LNode* p = A->next, * q = B->next, * r = A->next, * s;
	while (p!=NULL&&q!=NULL)
	{
		if (p->data == q->data)
		{
			s = q->next;
			r->next = p;
			r = p;
			p = p->next;
			q = q->next;
			free(s);
		}
		else if (p->data < q->data)
		{
			s = p;
			p = p->next;
			free(s);
		}
		else
		{
			s = q;
			q = q->next;
			free(s);
		}
	}
	while (q!=NULL)
	{
		s = q;
		q = q->next;
		free(s);
	}
	while (p!=NULL)
	{
		s = p;
		p = p->next;
		free(s);
	}
	r->next = NULL;
	free(B);
}//P38应用题15

bool IsSubLink(LinkList A, LinkList B) {
	LNode* p = A->next, * q = B->next, * r = A->next;
	while (p!=NULL&&q!=NULL)
	{
		if (p->data == q->data) 
		{
			p = p->next;
			q = q->next;
		}
		else
		{
			r = r->next;
			p = r;
			q = B->next;
		}
		
	}
	if (q == NULL)
	{
		return true;
	}
	else
	{
		return false;	
	}
	
}//P38应用题16

bool IsSame(DLinklist L) {
	DNode* q = L->next, * r = L->prior;
	while (q != r && r->next != q)
	{
		if (q->data==r->data)
		{
			q = q->next;
			r = r->prior;
		}
		else
		{
			return false;
		}
	}
	return true;
}//P38应用题17

void LinkedLink(LinkList& L1, LinkList& L2) {
	LNode* p = L1, * q = L2;
	while (p->next!=L1)
	{
		p = p->next;
	}
	while (q->next!=L2)
	{
		q = q->next;
	}
	p->next = L2;
	q->next = L1;
}//P38应用题18

void Free_Mini(LinkList& L) {
	LNode* p, * min, * minp, * pre;
	while (L->next!=L)
	{
		p = L->next;
		pre = L;
		min = p;
		minp = pre;
		while (p != L)
		{
			if (p->data < min->data)
			{
				pre = minp;
				min = p;
			}
			pre = p;
			p = p->next;
		}
		minp->next = min->next;
		cout << min->data;
		free(min);
	}
		
	free(L);
}//P38应用题19

DLinklist Locate(DLinklist& L, ElemType x) {
	DNode* p = L->next, * q;
	while (p&&p->data!=x)
	{
		p = p->next;
	}
	if (!p)
	{
		return false;
	}
	else
	{
		p->fred++;
		if (p->next!=NULL)
		{
			p->next->prior = p->prior;
		}
		p->prior->next = p->next;
		q = q->prior;
		while (q!=L&&q->fred<=p->fred)
		{
			q = q->prior;
		}
		p->next = q->next;
		q->next->prior = p;
		p->prior = q;
		q->next = p;
	}
	return p;
}////P38应用题20