#include <stdio.h>
#define N 10
int fun ( int *a, int n );
int main( ) {
	int x, b[N] = {11, 5, 12, 0, 3, 6, 9, 7, 10, 8}, n = 10, i;
	for ( i = 0; i < n; i++ ) printf("%d ", b[i]);
	printf("\n");
	fun ( b, n );
	for ( i = 0; i < n; i++ ) printf("%d ", b[i]);
	printf("\n");
	return 0;
}


/* 请在这里填写答案 */
int fun ( int *a, int n ) {
	//先找最大值
	int max_pos = 0;
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			max_pos = i;
		}
	}
	//最大值交换
	int temp = a[0];
	a[0] = max;
	a[max_pos] = temp;
	//次大值
	int sub_max_pos = 1;
	int sub_max = a[1];
	for (int i = 1; i < n; i++) {
		if (a[i] > sub_max) {
			sub_max = a[i];
			sub_max_pos = i;
		}
	}
	//次大值交换
	int sub_temp = a[1];
	a[1] = sub_max;
	a[sub_max_pos] = sub_temp;

}
