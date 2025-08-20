#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
//链表的定义
//结点、链表(指向头结点的一个指针)
typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

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

void Classify(LinkList list){
	Node *p, *q, *base, *pre;
	base = list->next;	//p1指向list单链表的第一个元素 
	p = base->next;	//p指向遍历当前结点 	
	pre = base;		//pre指向当前结点的前一个结点
	
	while(p!=NULL){	//遍历单链表 
		q=p->next;//q用来进行挂链，保存下一个进行比较的结点
		//遇到比第一个元素小的则进行头插操作
		if(p->data <= base->data){	
			//进行头插操作
			pre->next = p->next;
			p->next = list->next;
			list->next = p;
			p=q;
		} 
		else{	//其他则继续往后遍历 
			pre = p;
			p = p->next;
		}	
	}
}

int main(){
	LinkList list;
	InitList(&list);
	CreateFromHead(list);//头插法
	PrintList(list);
	Classify(list);
	PrintList(list);
	
	return 0;
}
