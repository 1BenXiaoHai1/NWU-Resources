#include<stdio.h>
#include<stdlib.h>
#ifndef LINKLIST_H
#define LINKLIST_H

#define OK 1
#define ERROR 0
//链表的定义
//结点、链表(指向头结点的一个指针)
typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

//链表相关操作
void InitList(LinkList *L);
void CreateFromHead(LinkList L);//头插法
void CreateFromTail(LinkList L);//尾插法
Node * Get(LinkList L,int i);//按序号查找
Node * LocateLinkList(LinkList L,int key);//按值查找
int ListLength(LinkList L);//求链表长度
int InsLinkList(LinkList L,int i,int e);//插入元素
int DelLinkList(LinkList L,int i,int *e);//删除元素
LinkList mergeLinkList(LinkList LA,LinkList LB);//链表合并
#endif
