#include<stdio.h>
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define OK 1
#define ERROR 0

//顺序表的定义
#define MAXSIZE 100

typedef struct{
	int elem[MAXSIZE];
	int last;
}SeqList;
//顺序表相关操作
int max(int a, int b);
int Locate(SeqList L, int e);
int DelList(SeqList *L, int i, int *e);
int InsList(SeqList *L, int i, int e);
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC);

#endif
