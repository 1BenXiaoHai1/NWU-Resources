/*
 * ex5_6.cpp
 *
 *  6. ��д�������ַ�����a �е�ǰn���ַ�����������b�У�����a��b������n�ɲ������롣
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


