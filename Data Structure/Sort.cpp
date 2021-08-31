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

void QuickSort(ElemType A[], int low, int high) {
	if (low<high)
	{
		int pivotpos = Partition(A, low, high);
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}
int Partition(ElemType A[], int low, int high) {
	ElemType pivot = A[low];
	while (low<high)
	{
		while (low<high && A[high]>pivot) --high;
		A[low] = A[high];
		while (low<high && A[low]>pivot) ++low;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}//øÏÀŸ≈≈–Ú