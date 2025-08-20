#include <stdio.h>

int StrCmp(const char *str1, const char *str2);

int main() {
	char a[1024], b[1024];
	int r;
	gets(a);
	gets(b);
	r = StrCmp(a, b);
	if (r > 0) {
		puts("a > b");
	} else if (r < 0) {
		puts("a < b");
	} else { // r == 0
		puts("a == b");
	}
	return 0;
}

/* 你提交的代码将被嵌在这里 */
int StrCmp(const char *str1, const char *str2) {
	//str1大于str2 返回值为正值 小于返回负值 相等返回零
	int i;
	//判断二者共有部分是否相同
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	//多出来的字符串
	if (str1[i] == '\0' && str2[i] == '\0') {
		return 0;//相等
	} else {
		if (str1[i] == '\0') {
			return -1;//str2比str1长
		} else {
			return 1;
		}
	}
}
