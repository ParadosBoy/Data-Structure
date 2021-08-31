#include <iostream>
#include<stdio.h>
#include<string.h>
#include"Linear Table.cpp"
#pragma once
using namespace std;
#define MaxSize 50
typedef int ElemType;

typedef struct {
	ElemType* elem;//0∫≈µ•Œª¡Ùø’
	int TableLen;
}SSTable;

typedef struct {
	int key;
	int low, high;
}indexElem;

int Search_Seq(SSTable ST, ElemType key) {
	ST.elem[0] = key;
	int i;
	for (i = ST.TableLen; ST.elem[i] != key; i--);
	return i;
}//À≥–Ú≤È’“

int Biary_Search(SeList L, ElemType key) {
	int low = 0, high = L.length - 1, mid = 0;
	while (low<high)
	{
		mid = (low + high) / 2;
		if (L.data[mid] == key)
			return mid;
		else if (L.data[mid]>key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		return -1;
	}
}//’€∞Î≤È’“

