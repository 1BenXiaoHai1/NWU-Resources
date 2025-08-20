/*
 * ex5_6.cpp
 *
 *  6. 编写函数将字符数组a 中的前n个字符拷贝到数组b中；数组a、b和整数n由参数传入。
 *
 *
 */

#include <iostream>
#include <cstring>
using namespace std;
void copystring(char* src, char* dest, int n)
{
	if(strlen(dest)<n)
		return;
	while(n-- &&*src){
		*dest++ = *src++;
	}
}
int main()
{
	const int max = 1024;
	char a[max],b[max];
	cout<<"Please input a:"<<endl;
	cin>>a;
	cout<<"Please input b:"<<endl;
	cin>>b;
	copystring(a,b,10);
	cout<<a<<endl;
	cout<<b<<endl;

}


