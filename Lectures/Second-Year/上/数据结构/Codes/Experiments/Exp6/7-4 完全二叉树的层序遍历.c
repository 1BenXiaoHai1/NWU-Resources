#include <stdio.h>
#include <stdlib.h>

//二叉树顺序存储结构
int n, tree[31];  // 结点的个数，顺序存储完全二叉树的数组

void CreateBiTree(int i) {
	//如果i>n说明该处无结点，不需要进行输入，即创建结点。
	if (i > n)
		return;
	//后序遍历创建二叉树——左右根
	CreateBiTree(2 * i);//当前结点为i，其左孩子结点为2*i
	CreateBiTree(2 * i + 1);//右孩子结点为2*i+1
	scanf("%d", &tree[i]);
}

int main() {
	scanf("%d", &n);
	CreateBiTree(1);//后续遍历创建二叉树
	//层序遍历
	for (int i = 1; i <= n; i++) {
		//输出格式控制
		if (i == 1)
			printf("%d", tree[i]);
		if (i > 1)
			printf(" %d", tree[i]);
	}
	return 0;
}

