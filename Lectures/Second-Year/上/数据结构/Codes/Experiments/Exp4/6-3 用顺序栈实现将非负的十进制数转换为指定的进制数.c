#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE  100

typedef int DataType;
typedef struct {
	DataType items[STACKSIZE];   /*存放栈中元素的一维数组*/
	int top;                     /*用来存放栈顶元素的下标*/
} SqStack;

int InitSqStack(SqStack *S); /* 初始化顺序栈, 细节在此不表 */
int SqStackPush( SqStack *S, DataType e );  /* 压栈函数, 细节在此不表 */
int SqStackPop(SqStack *S, DataType *e);  /* 出栈函数, 细节在此不表 */
int SqStackEmpty(SqStack S) ;  /* 判栈空函数, 细节在此不表 */

int DecimalConvert(SqStack *s, int dec, int scale);   /* 本题要求完成的函数 */

int main() {
	SqStack s;
	char ch[] = "0123456789ABCDEF";  //二、八、十六进制所使用的数字
	unsigned dec, scale;
	DataType tmp;

	InitSqStack( &s );
	scanf_s("%d %d", &dec, &scale);

	if ( DecimalConvert(&s, dec, scale ) ) {
		printf("十进制数:%d,转换为:%d进制数,结果为:", dec, scale);
		while ( !SqStackEmpty(s)) {
			SqStackPop(&s, &tmp);
			printf("%c", ch[tmp]);
		}
	} else
		printf("数制转换未成功！");

	printf("\n");

	return 1;
}

/* 请在这里填写答案 */
int DecimalConvert(SqStack *s, int dec, int scale) {
	// 函数返回值：1，表示函数执行完成；0，表示函数未成功执行。
	/*整数进制转换-除转换进制的奇数，取余数。
	  并且余数由下往上(先算的放在最低位，后算的放在最高位)——先进后出*/
	if(dec<0){
		return 0;
	}
	while (dec != 0) {
		int n = dec % scale;
		dec = dec / scale;
		SqStackPush(s, n); //压栈
	}
	return 1;
}
