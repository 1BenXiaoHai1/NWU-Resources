/*
 * ex3_1.cpp
 * 1. ��д���򣬴ӿ���̨����double���͵������¶ȣ�����ת��Ϊ�����¶ȣ�����ʾ�����
 * ת����ʽ�������¶� = (9/5) * �����¶� + 32
 */

#include<iostream>
using namespace std;
int main()
{
	cout << "enter temperature in Celsius degree:" << endl;
	double celsius, fahrenheit;
	cin >> celsius;
	fahrenheit = (9.0 / 5) * celsius + 32;
	cout << celsius << "C is " << fahrenheit << "F" << endl;

	return 0;
}



