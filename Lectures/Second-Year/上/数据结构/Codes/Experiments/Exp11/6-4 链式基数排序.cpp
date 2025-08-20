#include <iostream>

using namespace std;

#define Maxdigit 5
#define Radix 10


typedef struct node * ptrnode;
//结点
typedef struct node{
	int key;
	struct node * next;
}node;
//头结点
struct headnode{
	ptrnode head,tail;
};

void radixsort(ptrnode &L);//链式基数排序 
void createlist(ptrnode &L);//输入序列正序存入链表

int main()
{
	ptrnode L,P;
	createlist(L);
	radixsort(L);
}
/* 请在这里填写答案 */
void radixsort(ptrnode &L){
	
}
