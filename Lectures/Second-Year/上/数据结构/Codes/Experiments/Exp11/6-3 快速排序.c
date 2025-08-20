#include <stdio.h>

#define MAXLEN 50
typedef int KeyType;

typedef  struct {
	KeyType  key;
} elementType;

//顺序表
typedef  struct {
	elementType   data[MAXLEN + 1];
	int   len;
} SeqList;

//创建顺序表
void creat(SeqList *L) {
	int i;
	scanf("%d", &L->len);
	for (i = 1; i <= L->len; i++)
		scanf("%d", &L->data[i].key);
}

void print(SeqList L);  /*细节在此不表*/

void partition(SeqList *L, int low, int high, int *cutpoint);
void quickSort(SeqList *L, int low, int high);

int main () {
	SeqList L;
	int low, high;
	creat(&L);
	low = 1;
	high = L.len;
	quickSort(&L, low, high);
	print(L);
	return 0;
}

/* 请在这里填写答案 */
void partition(SeqList *L, int low, int high, int *cutpoint) {
	//低位元素为中心元素
	L->data[0] = L->data[low];
	int pivotkey = L->data[low].key;
	while (low < high) {
		//寻找小于中心元素的元素
		while (low < high && L->data[high].key >= pivotkey) {
			--high;
		}
		L->data[low] = L->data[high];//放到低位，放完后高子表有空位
		//寻找大于中心元素的元素
		while (low < high && L->data[low].key <= pivotkey) {
			++low;
		}
		L->data[high] = L->data[low];//放到高位，放完后低子表有空位
	}
	L->data[low] = L->data[0]; //插入中心元素
	*cutpoint = low;
}
void quickSort(SeqList *L, int low, int high) {
	if (low < high) {
		int pivotloc;
		partition(L, low, high, &pivotloc); //寻找中心位置，将L分为两个子表，pivotloc为枢轴元素
		quickSort(L, low, pivotloc - 1); //对低子表递归排序
		quickSort(L, pivotloc + 1, high); //对高子表递归排序
	}
}

void print(SeqList L) {
	printf("\n");
	for (int i = 1; i <= L.len; i++) {
		printf("%d ", L.data[i].key);
	}
}
