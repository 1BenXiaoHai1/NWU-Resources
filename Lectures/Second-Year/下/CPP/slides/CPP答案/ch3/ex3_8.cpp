/*
 * ex3_8.cpp
 *
 *  8. ��д������ʾ�û�����0~15֮���һ����������ʾ���Ӧ��ʮ�������������磬����13������ʾD������5������ʾ5��
 */

#include<iostream>
using namespace std;
int main()
{
	cout << "Enter a number between 0 and 15: " << endl;
	int decimal;
	cin >> decimal;

	char hexDigit;
	if(decimal >= 0 && decimal <=9)
		hexDigit = decimal + '0';
	else if(decimal >= 10 && decimal <= 15)
		hexDigit = decimal - 10 + 'A';
	else{
		cerr << "Invalid input." << endl;
		return 1;
	}

	cout << "hex digit is: " << hexDigit << endl;

	return 0;
}



