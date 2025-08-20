/*
 * ex4_2.cpp
 *
 * 2. 编写程序，提示用户输入字符，以‘#’结束。分别统计输入的字符中字母、数字和其他字符的个数并输出。
 *
 *
 */
#include<string>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	cout << "Enter characters, end with #" << endl;
	int cntDigit = 0, cntLetter = 0, cntOther = 0;
	char ch;
	do{
		cin >> ch;

		if(isalpha(ch))
			++cntLetter;
		else if(isdigit(ch))
			++cntDigit;
		else
			++cntOther;

	}while(ch != '#');

	cout << "Letters: " << cntLetter << endl;
	cout << "Digits: " << cntDigit << endl;
	cout << "Other: " << cntOther << endl;

	return 0;
}



