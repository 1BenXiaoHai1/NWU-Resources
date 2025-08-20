#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arr_size);          /* 打印数组,细节不表 */
void merge(int* a, int m, int* b, int n, int* c); /* 合并a和b为c */

int main(int argc, char const *argv[]) {
	int m, n, i;
	int *a, *b, *c;

	scanf("%d", &m);
	a = (int*)malloc(m * sizeof(int));
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &n);
	b = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	c = (int*)malloc((m + n) * sizeof(int));
	merge(a, m, b, n, c);
	printArray(c, m + n);

	return 0;
}

/* 请在这里填写答案 */
void merge(int* a, int m, int* b, int n, int* c) {
	int i = 0, j = 0, k = 0;
	//a、b公共部分
	while (i < m && j < n) {
		if (a[i] > b[j]) {
			c[k] = b[j];
			j++;
			k++;
		} else {
			c[k] = a[i];
			i++;
			k++;
		}
	}
	//a长
	while (i < m) {
		c[k] = a[i];
		i++;
		k++;
	}
	//b长
	while (j < n) {
		c[k] = b[j];
		j++;
		k++;
	}

}
