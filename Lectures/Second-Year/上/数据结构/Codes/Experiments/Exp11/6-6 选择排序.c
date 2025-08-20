#include <stdio.h>

#define N 1000
int arr[N];

/* 对长度为n的数组arr执行选择排序 */
void selectionSort(int arr[], int n);

/* 打印长度为n的数组arr */
void printArray(int arr[], int n);

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	selectionSort(arr, n);
	printArray(arr, n);
	return 0;
}
/* 打印长度为n的数组arr */
void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d", arr[i]);
		if (i < n - 1)  /* 下标0..n-2每个元素后面有个空格 */
			printf(" ");/*下标n-1,也就是最后一个元素后面没有空格*/
	}
	printf("\n");/* 一行打印完后换行 */
}

/* 你的代码将嵌在这里 */
//从小到大排列
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;//假设当前i位置为最小值
		//在i后面寻找最小的元素
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		if (min != i) { //如果当前i位置元素不为最小值，则进行交换
			swap(&arr[i], &arr[min]);
		}
	}
}
