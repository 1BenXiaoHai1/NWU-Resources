/*
 * ex4_1.cpp
 *
 * 5. 编写程序，将字符数组a 中的前n个字符拷贝到b数组去。
 *
 *
 */

#include<iostream>
using namespace std;


void copyarray(char a[], char b[], int n){
	for(int i = 0; i < n; ++i)
		b[i] = a[i];
}

int main()
{
	char s1[] = "12345abcd";
	char s2[20];

	copyarray(s1, s2, 5);

	return 0;
}


