#include <stdio.h>
#include<string.h>
char* StrMid(char *dst, const char *src, int start, int len);

int main() {
	char a[1024], b[1024];
	int s, n;
	gets(a);
	scanf("%d%d", &s, &n);
	StrMid(b, a, s, n);
	puts(b);
	return 0;
}

/* 你提交的代码将被嵌在这里 */
char* StrMid(char *dst, const char *src, int start, int len) {
	//起始位置是否合理
	if (start < 0 || start > (int)strlen(src)) { //strlen返回值为size_t类型——无符号类型
		dst[0] = '\0'; //因为dst未初始化，所以设置第一个字符为'\0'，这样就不会读到垃圾值
	} else { //起始位置合理情况
		int i;//为什么把i放到外面——是因为要在dst字符串后面手动加入'\0'
		if (start + len <= (int)strlen(src)) { //len合理
			for (i = start; i < len + start; i++) {
				dst[i - start] = src[i];
			}
		} else { //len不合理
			for (i = start; i < (int)strlen(src); i++) {
				dst[i - start] = src[i];
			}
		}
		dst[i - start] = '\0';//手动添加结束标志
	}
	return dst;
}
