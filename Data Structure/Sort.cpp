#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int ElemType;

void InsertSort(ElemType A[], ElemType n) {
	ElemType i, j;
	for (i = 0; i <= n; i++)
	{
		if (A[i] < A[i - 1])
		{
			A[0] = A[i];
			for (j = j - 1; A[0] < A[j]; j--)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}