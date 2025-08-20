#include<stdio.h>


int LinkLength(LinkList L)
‎ {
	Node* p = L->next;
	int i = 0;

	while (p != NULL) {
		i++;
		p = p->next; //后移
	}

	return i;    //返回链表长度

}

‎
