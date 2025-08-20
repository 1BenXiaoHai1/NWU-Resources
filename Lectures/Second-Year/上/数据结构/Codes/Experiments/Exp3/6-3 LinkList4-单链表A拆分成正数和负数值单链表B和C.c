#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node {
	DataType data;      // data域用于存储数据元素
	struct Node *next;  // next域用于存放指向其后继的指针
} LNode, *PNode, *LinkList; // LinkList为头指针


int InitLinkList(LinkList *head);       /* 初始化链表, 细节在此不表 */
PNode LinkListInsert(LinkList h, int pos, DataType x)    ;   /* 向链表插入新元素，返回新插入链点的指针，细节在此不表 */
void TraverseLinkList(LinkList h);   /* 遍历单链表，细节在此不表 */
void DestroyLinkList(LinkList h);    /* 销毁单链表，细节在此不表 */
int BnotinA(LinkList a, LinkList b);   /* 判定B中的链点是否来自于A ，如果链点来自A，则返回1，否则返回0，细节在此不表 */

void SplitList( LinkList a, LinkList *b, LinkList *c );      /*  本题要求函数 */

int main() {
	LinkList aa, aa1, bb, cc;
	DataType x;
	char ch;
	int pos = 1;
	InitLinkList(&aa);
	InitLinkList(&aa1);
	InitLinkList(&bb);
	InitLinkList(&cc);
	do {
		scanf("%d", &x);
		LinkListInsert( aa, pos++, x );
		if (pa != NULL) {
			LinkListInsert(aa1, pos, (DataType)pa);
		}
	} while ((ch = getchar()) != '\n');
	SplitList( aa, &bb, &cc );
	if ( (bb->next == NULL && BnotinA(aa1, cc) != 1 ) || ( cc->next == NULL && BnotinA(aa1, bb) != 1 )  ) {
		printf("单链表B和C的链点来自于单链表A\n");
	} else if ( ( BnotinA(aa1, bb) != 1 ) &&  ( BnotinA(aa1, cc) != 1 ) ) {
		printf("单链表B和C的链点来自于单链表A\n");
	}

	printf("单链表B是\n");
	TraverseLinkList( bb );
	printf("单链表C是\n");
	TraverseLinkList( cc );
	DestroyLinkList(aa);
	DestroyLinkList(bb);
	DestroyLinkList(cc);
	return 0;
}

void SplitList( LinkList a, LinkList *b, LinkList *c ) {
	LinkList pa = a->next;//pa指向首结点
	LinkList r = a;//r为假的头指针（用来处理为零的情况）
	//尾插法——尾指针
	LinkList pb_tail = *b;//指向b表最后一个结点
	LinkList pc_tail = *c;
	while (pa != NULL) {
		//如果为负数，采用尾插法插入b中
		if (pa->data < 0) {
			r->next = pa->next; //保存剩余链的地址
			//尾插法
			pa->next = pb_tail->next;
			pb_tail->next = pa;
			pb_tail = pb_tail->next; //pb_tail指向最后一个元素
			pa = r->next;
		} else if (pa->data > 0) {
			r->next = pa->next;
			//尾插法
			pa->next = pc_tail->next;
			pc_tail->next = pa;
			pc_tail = pc_tail->next;
			pa = r->next;
		} else { //等于零不进行操作
			a->next = pa;
			r = r->next; //0结点此时可看作为假的新链表的首结点
			pa = pa->next; //pa后移
		}

	}
}
