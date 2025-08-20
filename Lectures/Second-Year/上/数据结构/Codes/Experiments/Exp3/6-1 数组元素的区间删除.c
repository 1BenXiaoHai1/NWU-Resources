#include <stdio.h>

#define MAXN 20

int Delete( int A[], int L, int minA, int maxA );

int main() {
	int A[MAXN], L, minA, maxA, i;

	scanf("%d", &L);
	for (i = 0; i < L; i++) scanf("%d", &A[i]);
	scanf("%d %d", &minA, &maxA);
	L = Delete(A, L, minA, maxA);
	for (i = 0; i < L; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}

/* 你的代码将被嵌在这里 */
//双循环变量-就地删除
int Delete( int A[], int L, int minA, int maxA ) {
	int i = 0, j = 0;
	while (i < L) {
		if (A[i] >= minA && A[i] <= maxA) {
			i++;//删除区间范围，直接跳过，不给赋值
			continue;
		} else {
			A[j] = A[i];
			i++;
			j++;
		}
	}
	return j;
}
