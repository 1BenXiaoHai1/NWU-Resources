#include <stdio.h>

int cal( char *s );

int main() {

	char a[100];
	int res;
	scanf("%s", a);

	res = cal(a);

	printf("%d", res);

	return 0;

}

int cal(char *s) {
	//顺序栈
	int numStack[100] = {0}; //数据栈
	int numTop = -1; //栈顶指针

	int i = 0;
	char oper;//保存运算符
	//运算符仅有四种：+、-、* 、/没有括号，两个整数的运算，只有一个运算符，无需考虑优先级
	//数字栈
	while (s[i] != '\0') {
		if (s[i] >= '0' && s[i] <= '9') {
			//如果为数字，不断查看下一个元素，直到不是数字结束，并将数字压入数据栈中
			int num = 0;
			do {
				int digit = s[i] - '0'; //将字符转换为整形数字
				num = num * 10 + digit;
				i++;
			} while (s[i] >= '0' && s[i] <= '9'); //为数字继续执行循环
			//压栈
			numTop++;
			numStack[numTop] = num; //插入元素
		} else {
			//只保存运算符,不保存等号
			if (s[i] != '=') {
				oper = s[i]; //保存运算符
			}
			i++;
		}
	}

	//栈中元素
	//后进先出
	int b = numStack[numTop];
	numTop--;
	int a = numStack[numTop];

	int res = 0;
	switch (oper) {
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			res = a / b;
			break;
	}

	return res;
}

