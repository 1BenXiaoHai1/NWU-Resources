#include <iostream>

#define MAXSIZE 1000
using namespace std;

typedef struct {
	int key;
	char *otherinfo;
} ElemType;

//顺序表
typedef struct {
	ElemType *r;
	int  length;
} SqList;

//创建顺序表
void Create_Sq(SqList &L) {
	int i, n;
	cin >> n;  //输入的值不大于 MAXSIZE
	for (i = 1; i <= n; i++) {
		cin >> L.r[i].key;
		L.length++;
	}
}
//输出顺序表
void show(SqList L) {
	int i;
	for (i = 1; i <= L.length; i++)
		if (i == 1)
			cout << L.r[i].key;
		else
			cout << " " << L.r[i].key;
}

void HeapAdjust(SqList &L, int s, int m); //筛选法调整堆
void CreatHeap(SqList &L); //把无序序列L.r[1..n]建成大根堆
void HeapSort(SqList &L);//对顺序表L进行堆排序

int main() {
	SqList L;
	L.r = new ElemType[MAXSIZE + 1];
	L.length = 0;
	Create_Sq(L);
	HeapSort(L);
	show(L);
	return 0;
}
/* 请在这里填写答案 */
void HeapAdjust(SqList &L, int s, int m) {
	ElemType temp = L.r[s];//暂存根s的信息
	int x = L.r[s].key;//根s的关键字
	int i = s, j = 2 * i; //j为根节点的孩子结点
	bool finished = false;
	//寻找根节点左右子树中选择较大的，与根节点进行交换
	while (j <= m && finished == false) {
		if (j + 1 <= m && L.r[j].key < L.r[j + 1].key) {
			j += 1; //右子树的根节点较大
		}
		if (x >= L.r[j].key) {
			finished = true;
		} else {
			L.r[i] = L.r[j];
			i = j;
			j = 2 * i;
		}
	}
	L.r[i] = temp;
}

void CreatHeap(SqList &L) {
	for (int i = L.length / 2; i >= 1; i--) { //从最后一个非叶子结点（n/2）开始
		HeapAdjust(L, i, L.length);//将每个子树调整为堆
	}
}

void HeapSort(SqList &L) {
	CreatHeap(L);//建立堆
	//将堆顶元素与堆尾元素进行交换
	for (int i = L.length; i >= 2; i--) {
		ElemType top = L.r[1];//堆顶元素
		L.r[1] = L.r[i];
		L.r[i] = top;
		HeapAdjust(L, 1, i - 1); //将1...i-1变成堆
	}
}
