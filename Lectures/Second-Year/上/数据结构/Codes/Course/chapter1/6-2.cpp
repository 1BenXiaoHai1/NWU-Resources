# include<stdio.h>
int Bsearch(int *p, int n, int x);
int main(void) {
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int x, m;
	scanf("%d", &x);
	m = Bsearch(a, 10, x);
	if (m >= 0)
		printf("Index is %d\n", m);
	else
		printf( "Not Found\n");

	return 0;
}

/* 请在这里填写答案 */
int Bsearch(int *p, int n, int x) {
	//二分查找-先排序再查找(本题目已排好序)
	int left = 0, right = n;//左右边界
	int flag = -1;
	int mid = 0;
	while (left <= right) {
		//确定所属区间
		mid = (left + right) / 2;
		//x位于右区间
		if (p[mid] < x) {
			left = mid + 1;
			mid = (left + right) / 2;
		}
		//x位于左区间
		else if (p[mid] > x) {
			right = mid - 1;
			mid = (left + right) / 2;
		}
		//
		else {
			flag = 0;
			break;
		}
	}
	if (flag == -1) {
		return -1;
	} else {
		return mid;
	}
}
