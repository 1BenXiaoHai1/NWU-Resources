#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100        /* 栈最大容量 */
int top;                /* 栈顶指针 */
int mystack[MaxSize];    /* 顺序栈 */

/*判栈是否为空，空返回true，非空返回false */
bool isEmpty();

/* 元素x入栈 */
void Push(int x);

/* 取栈顶元素 */
int getTop();

/* 删除栈顶元素 */
void Pop();

/* 十进制正整数转换为二进制 */
void dec2bin(int x) {
	top = -1;            /* 初始化栈顶指针 */
	while (x) {
		Push(x % 2);
		x >>= 1;
	}
	while (!isEmpty()) {
		int t = getTop();
		Pop();
		printf("%d", t);
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		dec2bin(n);
	}
	return 0;
}

/* 请在这里填写答案 */
/*判栈是否为空，空返回true，非空返回false */
bool isEmpty() {
	//栈顶指针为-1，即为空
	if (top == -1) {
		return true;
	} else {
		return false;
	}
}

/* 元素x入栈 */
void Push(int x) {
	//先需要判断栈是否满了
	//指针上移，插入元素
	top++;
	mystack[top] = x;
}

/* 取栈顶元素 */
int getTop() {
	return mystack[top];//返回栈顶元素
}

/* 删除栈顶元素 */
void Pop() {
	//栈顶指针下移
	top--;
}
