#include<stdio.h>

int n, tree[1001]; //顺序存储二叉树

//寻找最近的公共祖先
int Find_LowestCommonAncestors(int n, int m) {
	//寻找m、n除2的最大因数——不需考虑左右结点，因为/运算符自动舍弃余数
	while (m != n) {
		//m中放较大的数
		if (m < n) {
			int temp = m;
			m = n;
			n = temp;
		}
		//寻找较大的结点的祖先——因为较大的结点的祖先可能是n，所以m/2
		m = m / 2;
	}
	return m;
}

int main() {

	scanf("%d", &n);
	//顺序存储二叉树的输入——从1开始，这样才满足左孩子为2*i，右孩子为2*i+1
	for (int i = 1; i <= n; i++) {
		scanf("%d", &tree[i]);
	}
	int i, j;
	scanf("%d %d", &i, &j);
	//i或j输入为空结点
	if (tree[i] == 0 || tree[j] == 0) {
		if (tree[i] == 0) {
			printf("ERROR: T[%d] is NULL", i);
		} else {
			printf("ERROR: T[%d] is NULL", j);
		}
	} else {
		//寻找最小公共祖先
		int n = Find_LowestCommonAncestors(i, j);
		printf("%d %d", n, tree[n]);
	}

	return 0;
}
