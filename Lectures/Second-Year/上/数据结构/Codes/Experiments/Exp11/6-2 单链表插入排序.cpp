#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;    //元素的数据类型

typedef struct LNode {
	ElemType data;        //结点的数据域
	struct LNode *next;    //指向后继结点
} LinkNode;             //单链表结点类型

//尾插法建立单链表,细节不表
void CreateListR(LinkNode *&L, ElemType a[], int n);

//输出线性表,细节不表
void DispList(LinkNode *L);

//单链表插入排序：元素递增排序
void insertion_sort(LinkNode *&L);

int main() {
	int n;

	scanf("%d", &n);
	ElemType a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	LinkNode *A;
	CreateListR(A, a, n);

	insertion_sort(A);
	printf("排序后的单链表: ");
	DispList(A);

	return 0;
}

/* 请在下面填写答案 */
void insertion_sort(LinkNode *&L) {
	//使用原链表构建一个有序区
	LNode * p = L->next->next;//保留首结点之后的元素-无序区
	L->next->next = NULL; //首结点-有序区中第一个元素
	//从L的第二个元素开始遍历，直至表尾
	while (p != NULL) {
		LNode * q = p->next;
		LNode * pre = L;
		//在有序区中寻找插入位置（插入位置后的元素值大于等于插入元素值）
		while (pre->next != NULL && pre->next->data < p->data) {
			pre = pre->next;
		}
		//插入结点
		p->next = pre->next;
		pre->next = p;
		p = q;//无序区下一个元素
	}

}
