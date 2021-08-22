#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int ElemType;
#define MaxSize 255
typedef struct {
	char ch[MaxSize];
	int length;
}SString;//∂®≥§À≥–Ú¥Ê¥¢

typedef struct {
	char* ch;
	int length;
}HString;//∂—∑÷≈‰¥Ê¥¢

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
}//ºÚµ•ƒ£ Ω∆•≈‰