#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//多文件输入——采用全局变量保存输入字符
char letters[80];
int i = 0;


//二叉树
typedef struct Node {
	char data;
	struct Node * leftchild;
	struct Node * rightchild;

} BiTNode, *BiTree;

void CreateBiTree(BiTree * root) {
	char val = letters[i++];

	if (val == '*') { //'*'代表虚结点——对应子树为空
		*root = NULL;
	} else {
		//根
		*root = (BiTNode *)malloc(sizeof(BiTNode));//申请结点并初始化
		(*root)->data = val;
		CreateBiTree(&((*root)->leftchild));//左
		CreateBiTree(&((*root)->rightchild));//右
	}
}

//队列(顺序循环队列)
#define MaxSize 80
typedef struct {
	BiTNode * elem[MaxSize];
	int front;
	int rear;//rear始终指向下一个入队元素的位置
} SeqQueue;
//初始化
void InitQueue(SeqQueue * Q) {
	Q->front = Q->rear = 0; //队首、队尾指针初始化
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
void EnterQueue(SeqQueue * Q, BiTree val) {
	if (!isFull(*Q)) {
		Q->elem[Q->rear] = val; //结点入队
		Q->rear = (Q->rear + 1) % MaxSize; //后移
	}
}
//判空
int isEmpty(SeqQueue Q) {
	if (Q.rear == Q.front) {
		return 1;
	} else {
		return 0;
	}
}
//出队
BiTree DeleteQueue(SeqQueue * Q) {
	if (isEmpty(*Q)) {
		return NULL;
	} else {
		BiTree first = Q->elem[Q->front];//首元素出队
		Q->front = (Q->front + 1) % MaxSize; //队首指针后移
		return first;
	}
}

//层序遍历
int LevelOrder(BiTree root) {
	//创建辅助队列并初始化
	SeqQueue Q;
	InitQueue(&Q);
	//根节点入队
	if (root == NULL) { //为空则不需入队，层序遍历不存在
		return 0;
	} else {
		EnterQueue(&Q, root);
		int maxWidth = 1;
		int width = 0;
		int last = Q.rear;//保存最右结点的下标——用来判断1层是否遍历完
		while (!isEmpty(Q)) {
			//元素出队并将其子结点插入队列
			BiTree temp = DeleteQueue(&Q);
			width++;//同层元素加一
			if (temp->leftchild != NULL) {
				EnterQueue(&Q, temp->leftchild);
			}
			if (temp->rightchild != NULL) {
				EnterQueue(&Q, temp->rightchild);
			}
			//一层遍历完成，判断最大宽度是否有更新
			if (Q.front == last) { //队首指针与上一次的队尾指针重合

				if (maxWidth < width) {
					maxWidth = width;
				}
				last = Q.rear; //更新每一层最右结点的位置
				width = 0; //一层遍历完毕，重置下一次的宽度
			}
		}
		return maxWidth;
	}


}

int main() {
	BiTree root;

	while (scanf("%s", letters) != EOF) {
		//先序创建二叉树
		CreateBiTree(&root);
		//层序遍历
		printf("maxWidth: %d\n", LevelOrder(root));
		//重置字符串和循环变量
		memset(letters, 0, MaxSize); //字符数组清除
		i = 0;
	}

	return 0;
}
