#include<stdio.h>
#include<cstring>
#include<stdlib.h>

void GetMemory1(char *p)
{
	p = (char*)malloc(100);
}

void text1(void)
{
	char *str = NULL;
	GetMemory1(str);
	strcpy(str,"hello world");
	printf(str);
	printf("\n");
}

char *GetMemory2(void)
{
	char p[] = "hello world";
	return p;
}
void text2(void)
{
	char *str = NULL;
	str = GetMemory2();
	printf(str);
	printf("\n");
}
void GetMemory3(char **p,int num)
{
	*p = (char *)malloc(num);
}
void text3(void)
{
	char *str = NULL;
	GetMemory3(&str,100);
	strcpy(str,"hello");
	printf(str);
	printf("\n");
}

int main()
{
	text1();
	text2();
	text3();
}
