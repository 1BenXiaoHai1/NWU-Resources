#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
//����Ķ���
//��㡢����(ָ��ͷ����һ��ָ��)
typedef struct Node {
	int data;
	struct Node *next;
} Node, *LinkList;

//������ز���
void InitList(LinkList *L);
void CreateFromHead(LinkList L);//ͷ�巨
void CreateFromTail(LinkList L);//β�巨
Node * Get(LinkList L, int i); //����Ų���
int LocateLinkList(LinkList L, int key); //��ֵ����
int ListLength(LinkList L);//��������
int InsLinkList(LinkList L, int i, int e); //����Ԫ��
int DelLinkList(LinkList L, int i, int *e); //ɾ��Ԫ��
void PrintList(LinkList list);//�����ӡ

//������
int main() {
	LinkList L;
	int sel, i, x;
	int e;//�洢�����Ԫ���Լ�ɾ�������ص�Ԫ��
	Node *s;

	InitList(&L);

	while (1) {

		printf("===============================\n");
		printf("0.�˳�\n");
		printf("1.��λ�ò���Ԫ��\n");
		printf("2.��Ԫ��ֵ����Ԫ��\n");
		printf("3.��ͷ�巨��������\n");
		printf("4.��β�巨��������\n");
		printf("5.��λ�ò���Ԫ��\n");
		printf("6.��λ��ɾ��Ԫ��\n");
		printf("7.��������\n");
		printf("             ˵��������λ�ô�0��ʼ\n");
		printf("===============================\n");
		PrintList(L);
		printf("ѡ�������") ;
		scanf("%d", &sel) ;
		if (sel == 0) break;

		switch (sel) {
			case 1:
				printf("\t1.��λ�ò���Ԫ��\n");
				printf("\t����λ�ã�");
				scanf("%d", &i);
				s = Get(L, i);
				if (!s) printf("\t\tλ�ô���!\n\n");
				else printf("\t\tλ��[%d]����Ԫ��Ϊ[%d]\n\n", i, s->data);
				break;
			case 2:
				printf("\t2.��Ԫ��ֵ����Ԫ��\n");
				printf("\t����Ԫ��ֵ��");
				scanf("%d", &e);
				i = LocateLinkList(L, e);
				if (i == -1) printf("\t\t����û��Ԫ��[%d]!\n\n", e);
				else printf("\t\tԪ��[%d]����λ��Ϊ[%d]\n\n", e, i );
				break;
			case 3:
				printf("\t3.��ͷ�巨��������\n");
				printf("\t����Ԫ��ֵ��-1���������������");
				CreateFromHead(L);
				break;
			case 4:
				printf("\t4.��β�巨��������\n");
				printf("\t����Ԫ��ֵ��-1���������������");
				CreateFromTail(L);
				break;
			case 5:
				printf("\t5.��λ�ò���Ԫ��\n");
				printf("\t����λ�ü�����Ԫ�أ�");
				scanf("%d %d", &i, &e);
				x = InsLinkList(L, i, e);
				if (x == ERROR) printf("\t\t����λ��[%d]����!\n\n", i);
				else printf("\t\t����ɹ�\n");
				break;
			case 6:
				printf("\t6.��λ��ɾ��Ԫ��\n");
				printf("\t����ɾ��λ�ã�");
				scanf("%d", &i);
				x = DelLinkList(L, i, &e);
				if (x == ERROR ) printf("\t\tɾ��λ��[%d]����!\n\n", i);
				else printf("\t\tɾ���ɹ�!ɾ��Ԫ��Ϊ:%d\n", e);
				break;
			case 7:
				printf("\t7.��������\n");
				x = ListLength(L);
				printf("\t\t������Ϊ:%d\n\n", x);
				break;
			default:
				printf("ѡ�����\n");
				break;
		}
		system("pause")	;
	}
}

//����������
void InitList(LinkList *L) {
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL; //������
}

void CreateFromHead(LinkList L) {
	int c;
	int flag = 1;
	while (flag) {
		scanf("%d", &c);
		if (c != -1) {
			//������㲢��ֵ
			Node *s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next; //ͷ�巨������ͷ����������½��
			L->next = s;
		} else {
			flag = 0;
		}
	}
}

void CreateFromTail(LinkList L) {
	Node *r;//rָ��ǰ��������һ��Ԫ��
	int c;
	int flag = 1;
	r = L;
	while (flag) {
		scanf("%d", &c);
		if (c != -1) {
			//������㲢��ֵ
			Node *s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = NULL;
			r->next = s;
			r = r->next; //r����
		} else {
			flag = 0;
			r->next = NULL;
		}
	}
}

Node * Get(LinkList L, int i) {
	int j;
	Node *p;
	if (i < 0) {
		return NULL;
	}
	p = L->next;
	j = 0;
	while ((p->next != NULL) && (j < i)) {
		p = p->next; //p����һ�����
		j++;
	}
	if (i == j) {
		return p;
	} else {
		return NULL;
	}
}

int  LocateLinkList(LinkList L, int key) {
	Node *p;
	p = L->next;
	int k = 0;
	while (p != NULL) {
		if (p->data != key) {
			p = p->next;
			k++;
		} else {
			break;
		}
	}
	//û�ҵ���Ԫ��
	if (p == NULL) {
		k = -1;
	}
	return k;
}

int ListLength(LinkList L) {
	Node *p;
	p = L->next;
	int j = 0;
	//��pΪ���һ�������ָ�����һ������ַ����NULL��ʱ��ѭ������
	while (p != NULL) {
		j++;
		p = p->next;
	}
	return j;
}

int InsLinkList(LinkList L, int i, int e) {
	Node *pre = L;//preָ��������ǰһ�����
	int k = 0;
	if (i < 0) {
		return ERROR;
	}
	//pre���ָ�����һ����㣬����ָ�����һ�������ָ�����һ�����ĵ�ַ����NULL������Ϊ���ܴ��������һ��λ�ò���Ԫ��
	while (pre != NULL && k <= i - 1) {
		pre = pre->next;
		k++;
	}
	//pre����ָ�����һ�����
	if (pre == NULL) {
		return ERROR;
	}
	Node *s = (Node*)malloc(sizeof(Node));
	s->data = e;
	//�����½��
	s->next = pre->next;
	pre->next = s;
	return OK;
}

int DelLinkList(LinkList L, int i, int *e) {
	Node *pre = L, *r;
	int k = 0;
	while (pre->next != NULL && k <= i - 1) {
		pre = pre->next;
		k++;
	}
	//ѭ��������preָ��ɾ��Ԫ�ص�ǰһ����㣬kΪi-1
	//pre����ָ�����һ��������һ����㣨��Ϊ���һ������ɾ����
	if (pre->next == NULL) {
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);
	return OK;
}

//�����ӡ
void PrintList(LinkList list) {
	Node *p = list->next;//pָ���׽��(ͷ������һ��Ԫ��)
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next; //p����
	}
	printf("\n");
	return;
}
