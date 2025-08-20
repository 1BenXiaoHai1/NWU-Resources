#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;//数据元素类型定义
//结点、二叉树定义
typedef struct {
	ElemType data;
	struct BiTNode * leftchild;//左孩子
	struct BiTNode * rightchild;//右孩子
} BiTNode, *BiTree;

//先序遍历创建二叉树
void CreateBiTree_PreOrder(BiTree * T) {
	char ch;
	ch = getchar();
	if (ch == '#') { //#代表该二叉树是空树
		*T = NULL;
	} else {
		//根
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		//左子树
		CreateBiTree_PreOrder(&((*T)->leftchild));
		//右子树
		CreateBiTree_PreOrder(&((*T)->rightchild));
	}
}

//先序遍历输出
void PreOrder(BiTree T) {
	if (T != NULL) {
		//根
		printf("%c", T->data);
		//左子树
		PreOrder(T->leftchild);
		//右子树
		PreOrder(T->rightchild);
	}
}
//中序遍历输出
void InOrder(BiTree T) {
	if (T != NULL) {
		InOrder(T->leftchild);//左
		printf("%c", T->data); //根
		InOrder(T->rightchild);//右
	}
}
//后序遍历输出
void PostOrder(BiTree T) {
	if (T != NULL) {
		PostOrder(T->leftchild);//左
		PostOrder(T->rightchild);//右
		printf("%c", T->data); //根
	}
}
//统计叶子结点
int LeafNum = 0;//全局变量
void CountLeafNum(BiTree T) {
	if (T != NULL) {
		if (T->leftchild == NULL && T->rightchild == NULL) { //叶子结点-无左右孩子
			LeafNum++;
		}
		CountLeafNum(T->leftchild);
		CountLeafNum(T->rightchild);
	}
}

int main() {
	BiTree T;

	CreateBiTree_PreOrder(&T);//创建树
	if (T != NULL) {
		PreOrder(T);//先序遍历
		printf("\n");
		InOrder(T);//中序遍历
		printf("\n");
		PostOrder(T);//后序遍历
		printf("\n");
	}
	//输出叶子结点数
	CountLeafNum(T);
	printf("%d", LeafNum);
}
