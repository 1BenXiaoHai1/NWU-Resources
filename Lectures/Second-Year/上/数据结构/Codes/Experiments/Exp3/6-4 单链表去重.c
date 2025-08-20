#include<stdio.h>

typedef struct _NODE_ {
	int data;
	struct _NODE_ *next;
} NODE;


void Unique(NODE *head);


int main() {
	NODE *h;
	Create(&h);
	Input(h);
	Unique(h);
	Output(h);
	putchar('\n');
	Destroy(&h);
	return 0;
}

//链表去重
void Unique(NODE *head) {
	NODE *r = head->next;
	//时间复杂度为O(n^2)——双重循环
	while (r != NULL) { //外循环为r
		NODE *pre = r;
		NODE *p = pre->next;
		while (p != NULL) {
			if (p->data == r->data) { //相等删除结点
				//删除节点
				pre->next = p->next;
				free(p);
				p = pre->next;
			} else {//不相等
				pre = p;
				p = pre->next;
			}
		}
		r = r->next; //r后移
	}
		
}

