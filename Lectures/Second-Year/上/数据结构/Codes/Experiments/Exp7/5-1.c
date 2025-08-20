#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode {
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

void CreatBinTree(BiTree  *T);
void preorder( BiTree T );
void swap(BiTree T);

int main() {
	BiTree T;
	CreatBinTree(&T);
	preorder(  T );
	swap(T);
	printf("\n");
	preorder(T);
	
	return 0;
}
void preorder( BiTree T ) {
	if (T) {
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void swap(BiTree T){ // 只传了一个根结点T
	if(T!=NULL){
		swap(T->lchild);  // 递归地交换左子树
		swap(T->rchild);  // 递归地交换右子树
		BiTree temp=T->lchild;  // 和交换ab的方法一样，借助temp完成交换
		T->lchild=T->rchild;
		T->rchild=temp;
	}
}


void CreatBinTree(BiTree  *T) {
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreatBinTree(&((*T)->lchild));
		CreatBinTree( &((*T)->rchild));
	}
}
