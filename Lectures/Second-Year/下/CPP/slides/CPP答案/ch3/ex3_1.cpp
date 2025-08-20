/*
 * ex3_1.cpp
 * 1. 编写程序，从控制台读入double类型的摄氏温度，将其转换为华氏温度，并显示结果。
 * 转换公式：华氏温度 = (9/5) * 摄氏温度 + 32
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



