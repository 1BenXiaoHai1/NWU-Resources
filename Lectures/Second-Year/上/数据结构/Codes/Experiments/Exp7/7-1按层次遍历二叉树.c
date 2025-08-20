#include<stdio.h>
#include<stdlib.h>

#define MaxSize 80

//树结点及二叉树定义
typedef struct Node {
	char data;
	struct Node * LChild;
	struct Node * RChild;
} BiTNode, *BiTree;

//队列(顺序队列)创建及相关操作创建
typedef struct {
	BiTree elem[MaxSize];
	int front;
	int rear;//尾指针始终指向下一个插入元素的位置
} SeqQueue;

//队列初始化
void InitQueue(SeqQueue * Q) {
	Q->front = 0;
	Q->rear = 0;
}
//判空
int isEmpty(SeqQueue Q) {
	if (Q.rear == Q.front) {
		return 1;
	} else {
		return 0;
	}
}
//判满
int isFull(SeqQueue Q) {
	if ((Q.rear + 1) % MaxSize == Q.front) {
		return 1;
	} else {
		return 0;
	}
}
//入队
void EnterQueue(SeqQueue * Q, BiTree x) {
	if (!isFull(*Q)) {
		Q->elem[Q->rear] = x; //插入元素
		Q->rear = (Q->rear + 1) % MaxSize; //尾指针后移
	}
}
//出队
BiTree DeleteQueue(SeqQueue *Q) {
	if (isEmpty(*Q)) { //队列为空
		return NULL;
	} else {
		BiTree temp = Q->elem[Q->front];//首元素出队
		Q->front = (Q->front + 1) % MaxSize; //队首指针后移
		return temp;
	}
}

//先序遍历创建二叉树
void CreateBiTree(BiTree * root) {
	char ch;
	ch = getchar();
	if (ch == '#') { //'#'代表该树为空树
		*root = NULL;
	} else {
		//先序创建
		*root = (BiTree)malloc(sizeof(BiTNode));
		(*root)->data = ch;
		CreateBiTree(&((*root)->LChild));
		CreateBiTree(&((*root)->RChild));
	}
}

void LevelOrder(BiTree root) {
	//辅助队列——创建并初始化
	SeqQueue Q;
	InitQueue(&Q);
	//先读入根节点
	if (root == NULL) {
		return;
	} else {
		EnterQueue(&Q, root); //根入队
		while (!isEmpty(Q)) {
			BiTree temp = DeleteQueue(&Q);//队首元素出栈
			printf("%c", temp->data);
			if (temp->LChild) { //左子树根节点入队
				EnterQueue(&Q, temp->LChild);
			}
			if (temp->RChild) { //右子树根节点入队
				EnterQueue(&Q, temp->RChild);
			}
		}
	}

}

int main() {
	BiTree T;

	CreateBiTree(&T);
	LevelOrder(T);

	return 0;
}
