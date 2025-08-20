/*
 * ex3_8.cpp
 *
 *  8. 编写程序，提示用户输入0~15之间的一个整数，显示其对应的十六进制数。例如，输入13，则显示D；输入5，则显示5。
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



