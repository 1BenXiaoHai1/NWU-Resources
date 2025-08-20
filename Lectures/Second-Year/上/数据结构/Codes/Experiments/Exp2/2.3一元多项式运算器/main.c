#include <stdio.h>
#include <stdlib.h>
#include<math.h>

//结点——系数、指数、指针域
typedef struct _node {
	float ceof;
	int exp;
	struct node *next;
} Node, *LinkList;

void InitList(LinkList *L);//建立空链表
void CreateFromTail(LinkList L);//尾插法创建多项式
LinkList add(LinkList La, LinkList Lb);//多项式求和
LinkList sub(LinkList La, LinkList Lb);//多项式求差
void PrintPolynomial(LinkList L);//多项式英文-polynomial
double CalPolynomial(LinkList L,double x);//计算多项式的值

int main(int argc, char *argv[]) {
	LinkList function1,function2;
	printf("-----------多项式计算器----------\n\n");
	//初始化
	InitList(&function1);
	InitList(&function2);
	//创建多项式
	printf("请输入多项式1(0 0代表结束)\n");
	CreateFromTail(function1);
	printf("请输入多项式2(0 0代表结束)\n");
	CreateFromTail(function2);
	//输出多项式
	printf("多项式1为:");
	PrintPolynomial(function1);
	printf("多项式2为:");
	PrintPolynomial(function2);
	printf("\n");
	int flag = -1;
	while(1){
		printf("\t1.多项式求和\n");
		printf("\t2.多项式做差\n");
		printf("\t3.多项式计算\n\n");
		printf("请选择功能:");
		loop : scanf("%d",&flag);
		switch (flag) {
		case 1:
			printf("\n\n------多项式求和------\n\n");
			LinkList addRes = add(function1,function2);
			printf("计算结果为:");
			PrintPolynomial(addRes);
			printf("\n--------------------------\n");
			break;
		case 2:
			printf("\n\n----------多项式做差----------\n\n");
			LinkList subRes = sub(function1,function2);
			printf("计算结果为:");
			PrintPolynomial(subRes);
			printf("\n--------------------------\n");
			break;
		case 3:
			printf("\n\n------多项式计算------\n\n");
			printf("请输入x:");
			float x = 0;
			scanf("%f",&x);
			printf("请选择计算的多项式(1 or 2):");
			int n;
			scanf("%d",&n);
			double result;
			if(n==1){
				result = CalPolynomial(function1,x);
			}else{
				result = CalPolynomial(function2,x);
			}
			printf("计算结果为%.3f",result);
			printf("\n--------------------------\n");
			break;
		default:
			printf("输入有误,请重新输入\n");
			goto loop;
		}
	}
	
	
	
	return 0;
}

//建立空链表
void InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; //空链表
}

void CreateFromTail(LinkList L) {
	Node *r=L;//r始终指向当前链表的最后一个结点
	int exp = 0;
	float coef = 0;
	scanf("%f %d",&coef,&exp);
	while (coef!=0&&exp!=0) {
		//创建结点并赋值
		Node *s = (Node*)malloc(sizeof(Node));
		s->ceof=coef;
		s->exp=exp;
		s->next=r->next;
		//尾插
		r->next = s;
		r = r->next; //r后移
		scanf("%f %d",&coef,&exp);
	}
	
}

LinkList add(LinkList La, LinkList Lb) {
	//创建一个c表
	LinkList Lc = (LinkList)malloc(sizeof(Node));
	Lc->next = NULL;
	Node * tail = Lc; //指向c表尾部结点
	Node * p = La->next;
	Node * q = Lb->next;
	//因为ha、hb要保留，所以不能直接使用其结点，应该新创建结点
	while (p!=NULL&&q!=NULL) {
		if (p->exp < q->exp) { //p<q
			//创建结点并赋值
			Node * s = (Node *)malloc(sizeof(Node));
			s->ceof = p->ceof;
			s->exp = p->exp;
			//尾插法插入元素
			s->next = tail->next;
			tail->next = s;
			tail = s; //tail后移——指向最后一个元素
			p = p->next; //p后移
		} else if (p->exp > q->exp) { //p>q
			Node * s = (Node *)malloc(sizeof(Node));
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
				Node * s = (Node *)malloc(sizeof(Node));
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
		Node * s = (Node *)malloc(sizeof(Node));
		s->ceof = p->ceof;
		s->exp = p->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s; //tail后移——指向最后一个元素
		p = p->next; //p后移
	}
	//p为空，q不为空
	while(q!=NULL){
		Node * s = (Node *)malloc(sizeof(Node));
		s->ceof = q->ceof;
		s->exp = q->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s;
		q = q->next;
	}
	
	return Lc;
}

LinkList sub(LinkList La, LinkList Lb) {
	//创建一个c表
	LinkList Lc = (LinkList)malloc(sizeof(Node));
	Lc->next = NULL;
	Node * tail = Lc; //指向c表尾部结点
	Node * p = La->next;
	Node * q = Lb->next;
	//因为ha、hb要保留，所以不能直接使用其结点，应该新创建结点
	while (p!=NULL&&q!=NULL) {
		//指数不同
		if (p->exp < q->exp) { //p<q,减数是小的,运算结果先放小的（减数，为正，不需要修改)
			//创建结点并赋值
			Node * s = (Node *)malloc(sizeof(Node));
			s->ceof = p->ceof;
			s->exp = p->exp;
			//尾插法插入元素
			s->next = tail->next;
			tail->next = s;
			tail = s; //tail后移——指向最后一个元素
			p = p->next; //p后移
		} else if (p->exp > q->exp) { //p>q,被减数是小的,被减数系数取负数.
			Node * s = (Node *)malloc(sizeof(Node));
			s->ceof = -q->ceof;
			s->exp = q->exp;
			s->next = tail->next;
			tail->next = s;
			tail = s;
			q = q->next;
		} else { //指数相同
			if (p->ceof - q->ceof == 0) {//做差为零不表示
				//比较a、b表下一个结点
				p = p->next;
				q = q->next;
			} else {//a、b相加
				Node * s = (Node *)malloc(sizeof(Node));
				s->ceof = p->ceof - q->ceof;
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
		Node * s = (Node *)malloc(sizeof(Node));
		s->ceof = p->ceof;
		s->exp = p->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s; //tail后移——指向最后一个元素
		p = p->next; //p后移
	}
	//p为空，q不为空
	while(q!=NULL){
		Node * s = (Node *)malloc(sizeof(Node));
		s->ceof = -q->ceof;//注意被减数的符号
		s->exp = q->exp;
		s->next = tail->next;
		tail->next = s;
		tail = s;
		q = q->next;
	}
	
	return Lc;
}

void PrintPolynomial(LinkList L) {
	Node * p;//遍历指针——用来遍历链表
	p = L->next;
	printf("%.1fx^%d ", p->ceof, p->exp);//先把第一个结点打印出来，为了便于处理符号
	p = p->next;
	while (p != NULL) {
		if(p->ceof>0){//系数大于零
			printf("+ %.1fx^%d ", p->ceof, p->exp);
		}else{//小于零
			printf(" %.1fx^%d ", p->ceof, p->exp);
		}
		p = p->next;//后移
	}
	printf("\n");
}

double CalPolynomial(LinkList L,double x){
	Node * p = L->next;
	double Res = 0;//统计运算结果
	
	while(p!=NULL){
		Res += pow((p->ceof)*x,p->exp); 
		p=p->next;
	}
	
	return Res;
}
