#include <stdio.h>
#include<stdlib.h>

#define N 20
int  match (char *exp);

int main() {
	char s[N];
	int flag;
	scanf("%s", s);
	flag = match(s);
	if (flag)
		printf("%s match", s);
	else
		printf("%s not match", s);
	return 0;
}

/* 请在这里填写答案 */
//求表达式的中括号是否匹配
int  match (char *exp) {
	//返回值为1或0，如果为1，则表示括号匹配，0表示不匹配。
	//顺序栈的定义和初始化
	char Stack[N] = "";//顺序栈 定义一个字符数组并初始化为空
	int top = -1;//栈顶指针

	//遍历字符串,只将中括号插入顺序栈中
	for (int i = 0; exp[i] != '\0'; i++) {
		//只判断括号
		switch (exp[i]) {
			//左括号全部压入栈中
			case '{':
			case '[':
			case '(':
				//压栈
				top++;
				Stack[top] = exp[i];
				break;
			case '}':
				//如果当前堆栈没有元素了，则说明右括号多余，匹配失败
				if (top == -1) { //top为-1说明堆栈为空
					return 0;
				} else { //不为空则进行出栈比较
					char xTop = Stack[top];//保存出栈元素
					//判断-若不为中括号左侧，则说明匹配失败
					if (xTop != '{') {
						return 0;
					}
					//为中括号左栈则继续比较
					top--;//栈顶指针下移-出栈
				}
				break;
			case ']':
				if (top == -1) {
					return 0;
				} else {
					char xTop = Stack[top];
					if (xTop != '[') {
						return 0;
					}
					top--;
				}
				break;
			case ')':
				if (top == -1) {
					return 0;
				} else {
					char xTop = Stack[top];
					if (xTop != '(') {
						return 0;
					}
					top--;
				}
				break;
		}

	}

	//判断左侧括号是否多余
	if (top != -1) {
		return 0;
	}

	return 1;//匹配成功
}


