#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef int ElemType;

void InsertSort(ElemType A[], ElemType n) {
	ElemType i=0, j=1;
	for (i = 2; i <= n; i++)
	{
		if (A[i] < A[i - 1])
		{
			A[0] = A[i];
			for (j = i - 1; A[0] < A[j]; j--)
			{
				A[j + 1] = A[j];
			}
			A[j + 1] = A[0];
		}
	}
}

void InsertSort(ElemType A[], ElemType n) {
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		A[0] = A[i];
		low = 1;
		high = i - 1;
		while (low<high)
		{
			mid = (low + high) / 2;
			if (A[mid]>A[0])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
			for (j = i - 1; j >= high; --j)
			{
				A[j + 1] = A[j];
			}
			A[high + 1] = A[0];
		}
	}
}//’€∞Î≤Â»Î≈≈–Ú

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