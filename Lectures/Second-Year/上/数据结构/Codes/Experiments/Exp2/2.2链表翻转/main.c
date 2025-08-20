#include<stdio.h>
#include"LinkList.h"

//链表打印
void PrintList(LinkList list) {
	Node *p = list->next;//p指向首结点(头结点的下一个元素)
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next; //p后移
	}
	printf("\n");
	return;
}

//链表反转函数
//算法思路——链表就地逆置，可看成一个老链表的结点向新链表进行头插操作(头插操作的性质是链表顺序和输入顺序相反)
void ReverseList(LinkList list) {
	Node *r, *p;
	//老链表
	r = list->next;//r的作用是为了暂时保存下一个进行头插的结点地址,防止链表丢失（挂链）
	p = r; //p始终指向需要进行头插的元素

	//新链表——没有结点，为空
	list->next = NULL;

	//头插法
	while (p != NULL) {
		r = p->next;//r保存下一个进行头插法的结点地址
		//将p结点所指向的元素利用头插法插入到list链表
		p->next = list->next;
		list->next = p;
		p = r; //指向下一个需要头插的结点
	}

}

int main() {
	LinkList list;
	InitList(&list);
	//头插法
	CreateFromHead(list);//输入'$'字符串代表输入结束
	PrintList(list);
	ReverseList(list);//翻转链表
	PrintList(list);
	return 0;
}
