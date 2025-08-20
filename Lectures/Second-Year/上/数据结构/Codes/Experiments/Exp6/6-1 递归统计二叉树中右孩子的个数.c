#include <stdio.h>
#include <stdlib.h>

typedef char DataType;//数据域元素类型

//二叉树结点定义——链式存储
typedef struct BTreeNode {
	DataType data;
	struct BTreeNode *leftchild;//指向左孩子
	struct BTreeNode *rightchild;//指向右孩子
} BinTreeNode;
typedef BinTreeNode *BinTree;//二叉树

//创建二叉树并返回二叉树——递归创建
BinTree CreateBinTree_Recursion() {
	char ch;
	BinTree bt;
	scanf("%c", &ch);
	//输入@代表创建结束
	if (ch == '@')
		bt = NULL;
	else {
		//根
		bt = (BinTreeNode *)malloc(sizeof(BinTreeNode));
		bt->data = ch;
		bt->leftchild = CreateBinTree_Recursion();//左子树
		bt->rightchild = CreateBinTree_Recursion();//右子树
	}
	return bt;
}

/* 请在这里填写答案 */
int CountRightNode(BinTree bt) {
	int cnt = 0;

	//递归程序编写，不要考虑太复杂情况，考虑最简单的情况
	if (bt != NULL) {
		//根
		if (bt->rightchild != NULL) { //存在右孩子
			cnt++;
		}
		cnt += CountRightNode(bt->leftchild);//左子树
		cnt += CountRightNode(bt->rightchild);//右子树
	}

	return cnt;
}

//摧毁二叉树
void DestroyBinTree(BinTree bt) {
	//释放结点
	if (bt != NULL) {
		//释放顺序——左右根
		DestroyBinTree(bt->leftchild);
		DestroyBinTree(bt->rightchild);
		free(bt);
	}
}

int main() {
	BinTree bt = NULL;
	int rightcount;
	bt = CreateBinTree_Recursion();
	rightcount = CountRightNode(bt);
	printf("%d", rightcount);
	DestroyBinTree(bt);
	return 0;
}

