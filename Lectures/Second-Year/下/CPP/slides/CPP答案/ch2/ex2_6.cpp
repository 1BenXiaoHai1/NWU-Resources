/*
 * ex2_6.cpp
 *
 *  ��д��������������������������ǽ��мӣ�+��������-�����ˣ�*��������/���ļ�������
 */

#include<iostream>
#include<cassert>
using namespace std;
int main()
{
	int a, b;
	cout << "enter two numbers: " << endl;
	cin >> a >> b;
	cout << a << "+" << b << "=" << a+b << endl;
	cout << a << "-" << b << "=" << a-b << endl;
	cout << a << "*" << b << "=" << a*b << endl;
	assert(b != 0);
	cout << a << "/" << b << "=" << a/b << endl;
	return 0;
}


