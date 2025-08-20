#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
	ElementType *Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main() {
	int N, Tag, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while ( !done ) {
		switch ( GetOp() ) {
			case push:
				scanf("%d %d", &Tag, &X);
				if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
				break;
			case pop:
				scanf("%d", &Tag);
				X = Pop(S, Tag);
				if ( X == ERROR ) printf("Stack %d is Empty!\n", Tag);
				break;
			case end:
				PrintStack(S, 1);
				PrintStack(S, 2);
				done = 1;
				break;
		}
	}
	return 0;
}

/* 你的代码将被嵌在这里 */
Stack CreateStack( int MaxSize ) {
	Stack s = (Stack *)malloc(sizeof(Stack));//定义一个栈s
	//初始化
	//动态内存分配——未知数量的数组
	s->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize); //数组初始化
	//栈指针初始化-数组下标为0-（Maxsize-1）
	s->Top1 = -1;
	s->Top2 = MaxSize;
	s->MaxSize = MaxSize; //堆栈最大容量
	
	return s;
}


bool Push( Stack S, ElementType X, int Tag ) {
	//如果堆栈已满，Push函数必须输出“Stack Full”并且返回false
	//判断堆栈是否满了
	if (S->Top1 + 1 == S->Top2) { //双堆栈指针相邻即为满
		printf("Stack Full\n");
		return false;
	} else {
		//判断那个栈进行压栈操作
		if (Tag == 1) { //1号栈
			S->Top1++;//1号栈指针上移
			S->Data[S->Top1] = X; //插入元素
		} else {
			S->Top2--;//2号栈指针下移
			S->Data[S->Top2] = X;
		}
		return true;//压栈成功
	}
}


ElementType Pop( Stack S, int Tag ) {
	/*如果某堆栈是空的，则Pop函数必须输出“Stack Tag Empty”
	  （其中Tag是该堆栈的编号），并且返回ERROR。*/
	//判空
	if (Tag == 1) {
		if (S->Top1 == -1) {
			printf("Stack 1 Empty\n");
			return ERROR;
		} else {
			//出栈
			ElementType res = S->Data[S->Top1];
			S->Top1--;//出栈——1号栈指针下移
			return res;
		}
	} else {
		if (S->Top2 == S->MaxSize) {
			printf("Stack 2 Empty\n");
			return ERROR;
		} else {
			//出栈
			ElementType res = S->Data[S->Top2];
			S->Top2++;//出栈——2号栈指针上移
			return res;
		}
	}
}
