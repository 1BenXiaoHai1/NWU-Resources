#include<stdio.h>

int Bsearch(int *a, int n, int k, int *p);

int main() {
	int n, cmp, *p = &cmp; //比较次数
	int pos, num = 0; //查找位置
	int low = 0, high, mid, k;
	while (~scanf("%d", &n)) {
		int a[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &k);
		int pos = Bsearch(a, n, k, p);
		printf("%d\n%d\n", pos, cmp);
	}
	return 0;
}
/* 请在这里填写答案 */
int Bsearch(int *a, int n, int k, int *p) {
	int low = 0, high = n - 1; //区间初值
	*p = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		(*p)++;//比较次数+1
		//数组升序排列
		if (a[mid] < k) { //查找元素在右区间
			low = mid + 1;
		} else if (a[mid] > k) { //查找元素在左区间
			high = mid - 1;
		} else { //找到了
			return mid;
		}
	}

	return -1;//未找到
}
