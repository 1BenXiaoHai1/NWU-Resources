/*
 * ex2_6.cpp
 *
 *  编写程序，输入两个整数，输出对它们进行加（+）、减（-）、乘（*）、除（/）的计算结果。
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


