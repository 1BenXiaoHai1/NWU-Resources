#include<stdio.h>
#include<stdlib.h>

typedef struct TNode {
	char ch;
	struct TNode * LChild;
	struct TNode * RChild;
} BiTNode, *BiTree;

void CreateBiTree(BiTree * root) {
	char ch;
	ch = getchar();
	if (ch == '#') {
		*root = NULL;
	} else {
		//先序创建
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->ch = ch;
		CreateBiTree(&((*root)->LChild));
		CreateBiTree(&((*root)->RChild));
	}
}

void InOrder(BiTree T) {
	if (T == NULL) {
		return;
	} else {
		InOrder(T->LChild);
		printf("%c", T->ch);
		InOrder(T->RChild);
	}
}

void InOrder_Exchange(BiTree T) {
	if (T == NULL) {
		return;
	} else {
		InOrder_Exchange(T->RChild);
		printf("%c", T->ch);
		InOrder_Exchange(T->LChild);
	}
}

int main() {
	BiTree T;

	CreateBiTree(&T);
	InOrder(T);//中序遍历——左根右
	printf("\n");
	InOrder_Exchange(T);//交换二叉树的中序遍历——右根左

	return 0;
}
