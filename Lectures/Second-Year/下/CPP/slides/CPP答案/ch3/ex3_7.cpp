/*
 * ex3_7.cpp
 *
 *  7. ��д������ʾ�û�������ݺ��·ݣ���ʾ����µ����������磬�������Ϊ2016�·�Ϊ2����Ӧ���29�졣
 */

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int year, month;
	cout << "enter year: ";
	cin >> year;
	cout << "enter month: ";
	cin >> month;

	if(year < 0 || month < 1 || month > 12){
		cerr<<"invalid input." << endl;
		exit(1);
	}
	int day = 31;
	if(month == 2)
		if((year %4 == 0 && year % 100 !=0) || year % 400 == 0)
			day = 29;
		else
			day = 28;
	else if(month == 4 || month == 6 || month == 9 || month == 11)
			day = 30;

	cout << month << " of " << year << " has " << day << " days. " << endl;

	return 0;
}



