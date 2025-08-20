#include <stdio.h>
#include "BinTree.h"

int main() {
	TNODE *r;
	BinTreeCreate(&r);
	BinTreeInput(&r);
	printf("%d\n", BinTreeDepth(r));
	BinTreeDestroy(&r);
	return 0;
}

//求二叉树的深度
int BinTreeDepth(const TNODE *root) {
	int hleft, hright, max;
	
	if (root != NULL) {
		hleft = BinTreeDepth(&(root->lchild));
		hright = BinTreeDepth(&(root->rchild));
		max = hleft > hright ? hleft : hright; //子树深度为左右子树的最大值
		return max + 1; //子树高度加根节点
	} else {
		return 0;//高度为零
	}
	
}
