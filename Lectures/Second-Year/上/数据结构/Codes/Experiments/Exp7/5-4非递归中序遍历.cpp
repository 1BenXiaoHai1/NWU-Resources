#include<iostream>
using namespace std;

typedef struct BiNode
{                
	char data;                        
	struct BiNode *lchild,*rchild;    
}BiTNode,*BiTree;

typedef struct StackNode
{
	BiTNode data;
	struct StackNode *next;
}StackNode,*LinkStack;

void CreateBiTree(BiTree &T)
{    
	char ch;
	cin >> ch;
	if(ch=='#')  T=NULL;        
	else{                            
		T=new BiTNode;
		T->data=ch;                    
		CreateBiTree(T->lchild);    
		CreateBiTree(T->rchild);    
	}                        
}

void InitStack(LinkStack &S)
{
	S=NULL;
}

bool StackEmpty(LinkStack S)
{
	if(!S)
		return true;
	return false;
}

void Push(LinkStack &S,BiTree e)
{
	StackNode *p=new StackNode;
	p->data=*e;
	p->next=S;
	S=p;
}

void Pop(LinkStack &S,BiTree e)
{
	if(S!=NULL)
	{    
		*e=S->data;
		StackNode *p=S;
		S=S->next;
		delete p;
	}
}

//非递归中序遍历
void InOrderTraverse1(BiTree T)
{ 
	LinkStack S; BiTree p;
	BiTree q=new BiTNode;
	InitStack(S); p=T;
	while(p||!StackEmpty(S))
	{
		if(p)//树不为空 
		{                            
			Push(S,p);                
			p=p->lchild;
		}       
		else
		{                             
			Pop(S,q);               
			cout<<q->data;
			p=q->rchild; 
		}
	}                                
}                                

int main()
{
	BiTree tree;
	CreateBiTree(tree);
	InOrderTraverse1(tree);
	return 0;
}
