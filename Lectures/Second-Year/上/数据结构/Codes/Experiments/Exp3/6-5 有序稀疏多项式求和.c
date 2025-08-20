#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define N 5

typedef struct node {
	float ceof;
	int exp;
	struct node *next;
} node, *ptr;

ptr creat();//表尾插入法构造链表,在此不表
ptr add(ptr ha, ptr hb);

void output(ptr h) {
	ptr p;
	p = h->next;
	while (p != NULL) {
		printf("%+.1fx^%d", p->ceof, p->exp);
		p = p->next;
	}
	printf("\n");
}

int main() {
	ptr h1, h2, h3;
	h1 = creat();
	h2 = creat();
	h3 = add(h1, h2);
	output(h1);
	output(h2);
	output(h3);
	return 0;
}

/* 请在这里填写答案 */
ptr add(ptr ha, ptr hb) {
	//创建一个c表
	ptr hc = (ptr)malloc(sizeof(node));
	hc->next = NULL;
	ptr tail = hc; //指向c表尾部结点
	ptr p = ha->next;
	ptr q = hb->next;
	//因为ha、hb要保留，所以不能直接使用其结点，应该新创建结点
	while (p!=NULL&&q!=NULL) {
		if (p->exp < q->exp) { //p<q
			//创建结点并赋值
			ptr s = (ptr)malloc(sizeof(node));
			s->ceof = p->ceof;
			s->exp = p->exp;
			//尾插法插入元素
			s->next = tail->next;
			tail->next = s;
			tail = s; //tail后移——指向最后一个元素
			p = p->next; //p后移
		} else if (p->exp > q->exp) { //p>q
			ptr s = (ptr)malloc(sizeof(node));
			s->ceof = q->ceof;
			s->exp = q->exp;
			s->next = tail->next;
			tail->next = s;
			tail = s;
			q = q->next;
		} else { //相等
			if (p->ceof + q->ceof == 0) {
				//比较a、b表下一个结点
				p = p->next;
				q = q->next;
			} else {//a、b相加
				ptr s = (ptr)malloc(sizeof(node));
				s->ceof = p->ceof + q->ceof;
				s->exp = q->exp;
				s->next = tail->next;
				tail->next = s;
				tail = s;
				//后移
				p = p->next;
				q = q->next;
			}
		}
	}
	//p不为空，q为空
	while(p!=NULL){
		ptr s = (ptr)malloc(sizeof(node));
		s->ceof = p->ceof;
		s->exp = p->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s; //tail后移——指向最后一个元素
		p = p->next; //p后移
	}
	//p为空，q不为空
	while(q!=NULL){
		ptr s = (ptr)malloc(sizeof(node));
		s->ceof = q->ceof;
		s->exp = q->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s;
		q = q->next;
	}
	
	return hc;
}
