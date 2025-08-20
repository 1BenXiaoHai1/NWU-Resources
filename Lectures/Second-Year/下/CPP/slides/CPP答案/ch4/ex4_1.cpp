/*
 * ex4_1.cpp
 *
 *	1. 编写程序，提示用户输入一个十进制整数，然后输出对应的二进制值。
 *
 */

////方法一：使用vector
//#include<iostream>
//#include<vector>
//using namespace std;

//int main()
//{
//	int n = 0;
//	cout << "Enter an integer in decimal: " ;
//	cin >> n;
//	vector<char> digits;
//
//	while(n != 0){
//		digits.push_back((n % 2) + '0');
//		n /= 2;
//	}
//
//	cout << "Binary: ";
//	for(auto it = digits.rbegin(); it != digits.rend(); ++it)
//		cout << *it;
//
//	return 0;
//}

//方法二：使用string
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cout << "Enter an integer in decimal: " ;
	cin >> n;
	string digits;

	while(n != 0){
		digits.push_back((n % 2) + '0');
		n /= 2;
	}

	cout << "Binary: ";
	for(auto it = digits.rbegin(); it != digits.rend(); ++it)
		cout << *it;

	return 0;
}


