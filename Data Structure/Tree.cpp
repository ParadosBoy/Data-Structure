#include <iostream>
#include<stdio.h>
#include<string.h>
#include"Stack.cpp"
using namespace std;
typedef int ElemType;
typedef struct BiTNode {
	ElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

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

void INOdrder(BiTree T) {
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

