#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define ERROR -1

typedef enum {false, true} bool;

typedef struct TNode * BinTree;   /* 二叉树类型 */
typedef char ElementType;
struct TNode {   /* 树结点定义 */
	ElementType Data;  /* 结点数据 */
	BinTree Left;   /* 指向左子树 */
	BinTree Right;   /* 指向右子树 */
};

typedef struct QNode * PtrToQNode; /* 队列 */
struct  QNode {
	BinTree Data[MAXSIZE];
	int  front, rear;
};
typedef PtrToQNode Queue;

void LevelorderTraversal ( BinTree BT ); /* 二叉树的层序遍历 */
Queue CreatQueue();
bool IsFullQ(Queue Q);
bool AddQ(Queue Q, BinTree X);
bool IsEmptyQ(Queue Q);
BinTree DeleteQ(Queue Q);

//按层序次序输入二叉树中结点的值（一个字符），@表示空树，构造二叉链表表示二叉树T
BinTree CreatBinTree() {
	ElementType Data;
	BinTree BT, T;
	Queue Q = CreatQueue(); /* 创建空队列 */
	/* 建立第1个结点，即根结点 */
	scanf("%c", &Data);
	if ( Data != '@') {
		/* 分配根结点单元，并将结点地址入队 */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT); //入队
	} else
		return NULL;   /* 若第1个数据就是0，返回空数 */
	//利用队列存储每一层的结点，对每个结点分别输入其左右结点
	while (!IsEmptyQ(Q)) {
		T = DeleteQ(Q);  /* 从队列中取出一结点地址 */
		scanf("%c", &Data);   /* 读入T的左孩子 */
		if ( Data == '@')
			T->Left = NULL;
		else { /* 分配新结点，作为出队结点左孩子；新结点入队 */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
		}
		scanf("%c", &Data);  /* 读入T的右孩子 */
		if (Data == '@')
			T->Right = NULL;
		else { /* 分配新结点，作为出队结点右孩子；新结点入队 */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
	}  /* 结束while */
	return BT;
}

Queue CreatQueue() {
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = Q->rear = 0;
	return Q;
}

//队尾指针始终指向当前队列的最后一个元素
bool IsFullQ(Queue Q) {
	if ( (Q->rear + 1) % MAXSIZE == Q->front ) //首尾指针重合代表队列已满
		return true;
	else
		return false;
}

bool AddQ(Queue Q, BinTree X) {
	if ( IsFullQ(Q) ) {
		printf("队列满");
		return false;
	} else {
		Q->rear = (Q->rear + 1) % MAXSIZE;
		Q->Data[Q->rear] = X;
		return true;
	}
}

bool IsEmptyQ(Queue Q) {
	if ( Q->front == Q->rear )
		return true;
	else
		return false;
}

BinTree DeleteQ(Queue Q) {
	if ( IsEmptyQ(Q) ) {
		printf("队列空");
		return NULL;
	} else  {
		Q->front = (Q->front + 1) % MAXSIZE;
		return  Q->Data[Q->front];
	}

}

int main() {
	BinTree BT;
	BT = CreatBinTree();

	if (BT == NULL) {
		printf("\n空树！\n");
	} else {
		printf("层序遍历的结果为：");
		LevelorderTraversal ( BT );
	}
	return 0;
}
/* 请在这里填写答案 */
void LevelorderTraversal ( BinTree BT ) { /* 二叉树的层序遍历 */
	BinTree T;
	Queue Q = CreatQueue(); /* 创建空队列 */
	//根结点
	if (BT != NULL) {
		printf("%c", BT->Data);
		//入队
		AddQ(Q, BT);
		//利用队列存储每一层的结点，对每个结点分别输入其左右结点
		while (!IsEmptyQ(Q)) {
			T = DeleteQ(Q);  /* 从队列中取出一结点*/
			//输出当前子树左孩子，并将左子树保存到队列中
			if (T->Left != NULL) {
				printf("%c", T->Left->Data);
				AddQ(Q, T->Left);
			}
			//输出右孩子，并将右子树保存起来
			if (T->Right != NULL) {
				printf("%c", T->Right->Data);
				AddQ(Q, T->Right);
			}
		}

	}
}
