#include <stdio.h>
#include <ctype.h>
#include<string.h>

char* StrTrim(char *str);

int main() {
	char a[1024];
	gets(a);
	StrTrim(a);
	puts(a);
	return 0;
}

/* 你的代码将被嵌在这里 */
char* StrTrim(char *str) {
	int i_head = 0;
	int i_tail = strlen(str) - 1;
	//删去str开始之前的空白符——统计第一个出现的非空白字符的下标
	while (isspace(str[i_head])) {
		i_head++;
	}
	//删除str之后的空白字符——统计后端出现的第一个空白字符的位置
	while (isspace(str[i_tail])) {
		i_tail--;
	}
	//字符串自赋值
	int k = i_head;
	int j;
	for (j = 0; k <= i_tail; j++, k++) {
		str[j] = str[k];
	}
	str[j] = '\0'; //手动插入结束标志
	
	return str;
}
