#include<stdio.h>

#define MaxSize 6 //队列最大长度
#define QueueElemType int //队列类型为int型
#define true 1
#define false 0

//顺序循环栈
typedef struct {
	QueueElemType elem[MaxSize];
	int front; //队头指针
	int rear; //队尾指针
	int tag; //标志位，用来判满
} SeqQueue;

void InitQueue(SeqQueue * Q) {
	//初始化为空队列
	Q->front = 0;
	Q->rear = 0;
	Q->tag = 0;//队列为空
}

//入队
int EnterQueue(SeqQueue * Q, QueueElemType x) {
	//判满
	if (Q->rear == Q->front && Q->tag == 1) { //满-tag为1，并且队首和队尾重合
		return false;
	} else {
		//rear指针指向最后一个元素的下一个位置
		Q->elem[Q->rear] = x; //插入元素
		Q->rear = (Q->rear + 1 ) % MaxSize; //后移
		//判断队列是否已满——队尾指针和队首指针重合，
		if (Q->front == Q->rear) {
			Q->tag = 1; //修改标志为1
		}
	}
}

//出队
int DeleteQueue(SeqQueue * Q, QueueElemType * x) {
	//判空
	if (Q->tag == 0 && Q->front == Q->rear) { //空队列-队尾指针和队头指针重合，并且标志位为0
		return false;
	} else {
		*x = Q->elem[Q->front];
		Q->front = (Q->front + 1) % MaxSize; //队首指针后移
		//判空
		if (Q->front == Q->rear) {
			Q->tag = 0;
		}
	}
}


int main() {
	SeqQueue Q;

	InitQueue(&Q);//初始化

	return 0;
}
