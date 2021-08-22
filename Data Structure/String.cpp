#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int ElemType;
#define MaxSize 255
typedef struct {
	char ch[MaxSize];
	int length;
}SString;//定长顺序存储

typedef struct {
	char* ch;
	int length;
}HString;//堆分配存储

int String_Sign(HString& S, char* ch) {
	if (S.ch) 
		free(S.ch);
	int len = 0;
	char* c = ch;
	while (*c)
	{
		len++;
		c++;
	}
	if (len==0)
	{
		S.ch = NULL;
		S.length = 0;
		return 1;
	}
	else
	{
		S.ch = (char*)malloc(sizeof(char) * (len + 1));
		if (S.ch==NULL)
		{
			return 0;
		}
		else 
		{
			c = ch;
			for (int i = 0; i <=len; i++,c++)
			{
				S.ch[i] = *c;
			}
			S.length = len;
			return 1;
		}
	}
}//赋值操作

int Lenth(HString S) {
	return S.length;
}//取串长度

int Compare(HString S1, HString S2) {
	for (int i = 0; i < S1.length&&i<S2.length; i++)
	{
		if (S1.ch[i]!=S2.ch[i])
		{
			return S1.ch[i] - S2.ch[i];
		}
	}
	return S1.length - S2.length;
}//串比较

int Concat(HString& S, HString S1, HString S2) {
	if (S.ch)
	{
		free(S.ch);
		S.ch = NULL;
	}
	S.ch = (char*)malloc(sizeof(char) * (S1.length+S2.length));
	if (S.ch == NULL)
	{
		return 0;
	}
	int i = 0;
	while (i<S1.length)
	{
		S.ch[i] = S1.ch[i];
		i++;
	}
	int j = 0;
	while (j <= S2.length)
	{
		S.ch[i+j] = S2.ch[j];
		j++;
	}
	S.length = S1.length + S2.length;
	return 1;
}//串连接

int Index(SString S, SString T) {
	int i = 1, j = 1, k = 2;
	while (i<=S.length&&j<=T.length)
	{
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else
		{
			i = k;
			j = 1;
			k++;
		}
	}
	if (j > T.length)
		return false;
	else
		return 0;
}//简单模式匹配

