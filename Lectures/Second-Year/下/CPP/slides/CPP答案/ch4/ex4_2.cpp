/*
 * ex4_2.cpp
 *
 * 2. ��д������ʾ�û������ַ����ԡ�#���������ֱ�ͳ��������ַ�����ĸ�����ֺ������ַ��ĸ����������
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



