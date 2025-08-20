/*
 * ex3_2.cpp
 * 2. 编写程序，读取一个0~1000之间的整数，并将该整数的各位数字相加。
 * 例如，输入整数372，各位数字之和为12。
 */

#include<iostream>
using namespace std;
int main()
{
	cout << " enter a number between 0 and 1000: " << endl;
	int number;
	cin >> number;
	int sum = 0;
	//方法一：1000以内
	sum += number % 10;			// 个位
	sum += (number / 10) % 10;	// 十位
	sum += number / 100;		// 百位

//或者用循环解：任何正整数
//	for(int k = number; k > 0; k /= 10) sum += k%10;
//
	cout << "sum of digits in " << number << " is: " << sum << endl;
	return 0;
}



