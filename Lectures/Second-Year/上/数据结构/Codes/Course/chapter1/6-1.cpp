#include <stdio.h>
#include <string.h>
void   fun ( char  s[  ] );

int main() {
	char    str[21];
	gets(str);
	fun(str);
//	puts(str);
	return 0;

}

/* 你提交的代码将被嵌在这里 */
void fun(char s[]) {
	//奇数字符串
	char odd[21] = {}; //定义静态字符串（给定长度）并赋初值
	//偶数字符串
	char even[21] = {};
	int i_odd = 0, i_even = 0;
	int length = strlen(s);
	for (int i = 0; i < length; i++) {
		//如果为偶数放到偶数数组
		int t = s[i] - '0';
		if (t % 2 == 0) {
			even[i_even] = s[i];
			i_even++;
		} else {
			odd[i_odd] = s[i];
			i_odd++;
		}
	}
	//s赋值为奇偶字符串连接后的结果
	strcat(odd, even); //连接
	strcpy(s, odd); //替换
}

