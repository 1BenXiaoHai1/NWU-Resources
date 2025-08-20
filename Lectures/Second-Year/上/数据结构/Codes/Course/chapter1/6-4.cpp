#include <stdio.h>
#include <string.h>

int Input(char*pstr[], char (*s)[21]);
void Find_max(char*pstr[], int count, int*Max);

int main(void) {
	char *pStr[10], str[10][21];
	int Count = 0, max;
	Count = Input(pStr, str);
	if (Count == 0) {
		printf("NO WORD\n");
	} else {
		Find_max(pStr, Count, &max); //寻找最长字符串并返回下标
		printf("max = %s", pStr[max]);
	}
}

int Input(char*pstr[], char (*s)[21]) {
	char str[22] = {};//存储输入的字符串s
	scanf("%s", str); //这里只能用scanf（gets读到回车键停止）
	int i = 0; //有效字符串数
	//若字符串1等于字符串2，返回结果等于零。
	while (strcmp(str, "*****") && i < 10) {
		//字符串数组赋值
		strcpy(*(s + i), str);
		*(pstr + i) = *(s + i);
		i++;
		scanf("%s", str);; //输入下一个字符串
	}
	return i;//有效字符串数
}
void Find_max(char*pstr[], int count, int*Max) {
	*Max = 0;
	for (int i = 1; i < count; i++) {
		if (strcmp(*(pstr + i), *(pstr + *Max)) > 0)
			*Max = i;
	}
}

