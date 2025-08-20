#ifndef STRING_H
#define STRING_H
#include<stdio.h>
#define false 0
#define ok 1

//定长顺序串
#define MaxSize 50
typedef struct{
	char ch[MaxSize];
	int len;//串长度
}SString;

int StrInsert(SString *s,int pos,SString t);//指定位置插入指定串
int StrDelete(SString *s,int pos,int len);//删除指定长度
int StrCompare(SString s,SString t);//比较两个串
int StrIndex(SString s,int pos,SString t);//简单模式匹配定位函数


#endif
