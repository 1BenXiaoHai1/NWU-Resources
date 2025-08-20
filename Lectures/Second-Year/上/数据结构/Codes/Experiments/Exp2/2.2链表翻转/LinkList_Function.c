#include"LinkList.h"

//建立空链表
void InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; //空链表
}

void CreateFromHead(LinkList L) {
	char c;
	int flag = 1;
	while (flag) {
		c = getchar();
		if (c != '$') {
			//创建结点并赋值
			Node *s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next; //头插法——在头结点后面插入新结点
			L->next = s;
		} else {
			flag = 0;
		}
	}
}

void CreateFromTail(LinkList L) {
	Node *r;//r指向当前链表的最后一个元素
	char c;
	int flag = 1;
	r = L;
	while (flag) {
		c = getchar();
		if (c != '$') {
			//创建结点并赋值
			Node *s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = NULL;
			r->next = s;
			r = r->next; //r后移
		} else {
			flag = 0;
			r->next = NULL;
		}
	}
}

Node * Get(LinkList L, int i) {
	int j;
	Node *p;
	if (i <= 0) {
		return NULL;
	}
	p = L;
	j = 0;
	while ((p->next != NULL) && (j < i)) {
		p = p->next; //p后移一个结点
		j++;
	}
	if (i == j) {
		return p;
	} else {
		return NULL;
	}
}

Node * LocateLinkList(LinkList L, int key) {
	Node *p;
	p = L->next;
	while (p != NULL) {
		if (p->data != key) {
			p = p->next;
		} else {
			break;
		}
	}
	return p;
}

int ListLength(LinkList L) {
	Node *p;
	p = L->next;
	int j = 0;
	//当p为最后一个结点所指向的下一个结点地址（即NULL）时，循环结束
	while (p != NULL) {
		p = p->next;
		j++;
	}
	return j;
}

int InsLinkList(LinkList L, int i, int e) {
	Node *pre = L;//pre指向删除结点的前一个结点
	int k = 0;
	if (i < 0) {
		return ERROR;
	}
	//pre最多指向最后一个结点，不能指向最后一个结点所指向的下一个结点的地址（即NULL），因为可能存在在最后一个位置插入元素
	while (pre != NULL && k < i - 1) {
		pre = pre->next;
		k++;
	}
	//pre不能指向最后一个结点
	if (pre == NULL) {
		printf("插入位置不合理!");
		return ERROR;
	}
	Node *s = (Node*)malloc(sizeof(Node));
	s->data = e;
	//插入新结点
	s->next = pre->next;
	pre->next = s;
	return OK;
}

int DelLinkList(LinkList L, int i, int *e) {
	Node *pre = L, *r;
	int k = 0;
	while (pre->next != NULL && k < i - 1) {
		pre = pre->next;
		k++;
	}
	//循环结束后，pre指向删除元素的前一个结点，k为i-1
	//pre不能指向最后一个结点的下一个结点（因为最后一个结点可删除）
	if (pre->next == NULL) {
		printf("删除结点的位置i不合理!");
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);
	return OK;
}

LinkList mergeLinkList(LinkList LA, LinkList LB) {
	Node *pa, *pb, *r;
	LinkList LC;
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	LC->next = NULL;
	r = LC;//r指向LC表的最后一个结点
	while (pa != NULL && pb != NULL) {
		if (pa->data <= pb->data) {
			r->next = pa;
			r = pa;
			pa = pa->next;
		} else {
			r->next = pb;
			r = pb;
			pb = pb->next;
		}
	}
	if (pa) {
		r->next = pa;
	} else {
		r->next = pb;
	}
	free(LB);
	return LC;
}
