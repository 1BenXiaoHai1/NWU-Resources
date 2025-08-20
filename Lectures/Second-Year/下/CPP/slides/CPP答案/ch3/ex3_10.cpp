/*
 * ex3_10.cpp
 *
 *  10. 编写程序，读入不定个数的整数，判断读入的正数和负数各有多少个，0不计数，
 *  然后计算这些输入值的总和及其平均值。当输入0时，表面程序结束。
 *
 *  输出各项统计信息，其中平均值以浮点数格式显示，2位小数。
 */


#include<iostream>
using namespace std;

int main()
{
	int number, sum = 0, neg = 0, pos = 0;
	cout << "enter integers, end with 0" << endl;
	do{
		cin >> number;

		if(number == 0)
			break;
		else if(number > 0)
			++pos;
		else
			++neg;

		sum += number;

	}
	while(number != 0);


	cout << "positive numbers : " << pos << endl;
	cout << "negative numbers : " << neg << endl;
	cout.precision(2);
	if(pos + neg != 0)
		cout << "average value: " << fixed << (sum * 1.0 / (pos + neg))<<endl;
	else
		cout <<  "average value is 0." << endl;

	return 0;
}

