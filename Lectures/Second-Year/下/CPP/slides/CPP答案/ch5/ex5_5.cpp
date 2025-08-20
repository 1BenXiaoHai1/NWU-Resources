/*
 * ex5_1.cpp
 *
 *  5. 编写函数，反向显示一个整数，例如reverse(3456)输出6543。
 *
 *  函数原型为：int reverse(int number);
 *
 */


#include<iostream>
using namespace std;

int reverse(int number){
	int rnumber = 0;
	while(number > 0){
		rnumber = rnumber * 10 + number % 10;
		number /= 10;
	}
	return rnumber;
}

int main()
{
	cout << "Enter an integer: " << endl;
	int n;
	cin >> n;
	cout << "reverse(" << n << ") is " << reverse(n) << endl;

	return 0;
}

