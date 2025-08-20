#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct SNode
{  
	DataType data;            
	struct SNode *next;        
}SNode,*LinkStack;            
int InitLinkStack( LinkStack *top )
{
	*top = (LinkStack)malloc( sizeof(SNode) );
	if( *top == NULL ) 
	{ 
		printf("初始化链栈出错");
		return 0;    
	}
	(*top)->next = NULL;
	return  1;
}
int LinkStackEmpty( LinkStack top )
{
	if( top->next == NULL ) 
		return 1;
	else
		return 0;
}
int Push(LinkStack top, DataType e)
{
	SNode *p;
	p = (SNode*)malloc(sizeof(SNode));
	if (!p)
	{
		printf("入栈操作出错!\n");
		return 0;
	}
	p->data = e;
	p->next = top->next;
	top->next = p;
	return 1;
}
int Pop(LinkStack top, DataType *e)
{
	SNode *p;
	if (!top->next)
	{
		printf("栈已空，无法完成出栈操作!\n");
		return 0;
	}
	p = top->next;
	top->next = p->next;
	*e = p->data;
	free(p);
	return 1;
}
int Destroy(LinkStack top)
{
	SNode *p;
	while (top)
	{
		p = top;
		top = top->next;
		free(p);
	}
	return 1;
}
typedef struct QNode
{
	DataType data;            
	struct QNode *next;        
}LQNode,*PQNode ;
typedef struct 
{ 
	PQNode front, rear;        
}LinkQueue;
int InitLinkQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (PQNode)malloc(sizeof(LQNode));
	if (!Q->front)
	{
		printf("初始化队列失败！\n");
		return 0;
	}
	Q->front->next = NULL;
	return 1;
}
int LinkQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear) return 1;
	else return 0;
}
int EnLinkQueue(LinkQueue* Q, DataType e)
{
	PQNode p;
	p = (PQNode)malloc(sizeof(LQNode));
	if (!p)
	{
		printf("内存分配失败，不能完成入队操作！\n");
		return 0;
	}
	p->data = e;
	p->next = NULL;//初始化入队结点
	Q->rear->next = p;
	Q->rear = p;
	return 1;
}
int DeLinkQueue(LinkQueue* Q, DataType* e)
{
	PQNode p;
	if (Q->front == Q->rear)
	{
		printf("队列已空，不能完成出队操作！\n");
		return 0;
	}
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	free(p);
	if (Q->rear == p) //若删除的队列是最后一个结点，则移动队尾指针
	{
		Q->rear = Q->front;
	}
	return 1;
}
int DestroyLinkQueue(LinkQueue* Q)
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
		
	}
	return 1;
}
int JudgePalindrome(LinkStack st,LinkQueue qu);
int main()
{
	LinkStack s;
	LinkQueue q;
	char ch;
	int rst;
	InitLinkStack(&s);
	InitLinkQueue(&q);
	while((ch=getchar())!='\n')
	{
		Push(s,ch);
		EnLinkQueue(&q,ch);
	}
	rst = JudgePalindrome(s,q);
	if ( rst == 0 )
	{
		printf("不是回文字符串\n");
	} 
	else
	{
		printf("是回文字符串\n");
	}
	Destroy(s);
	DestroyLinkQueue(&q);
	return 0;
}

/* 请在这里填写答案 */
int JudgePalindrome(LinkStack st, LinkQueue qu) {
	//栈:先进后出（出栈可看成字符串从后往前读） 队列:先进先出（出队列可看作字符串从前往后读）
	//回文字符串正读和反读都一样的字符串
	//算法思路——出栈元素等于出队元素(终止条件:队列、栈为空)
	LinkStack p_st = st->next;
	PQNode  p_qu = qu.front->next;
	
	while (p_st != NULL && p_qu != NULL) {
		if (p_st->data == p_qu->data) { //相等比较下一个对应位置的元素
			p_st = p_st->next;
			p_qu = p_qu->next;
		} else {
			//元素不相等——不为回文字符串
			return 0;
		}
	}
	
	return 1;
}
