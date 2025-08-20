/*
 * ex6_6.cpp
 *
 * 6. ��Ʋ�ʵ��һ��������Date��Ҫ��
 ��1���б�ʾ�ꡢ�¡��յ����ݳ�Ա��
 ��2����ȷ��ʼ�������գ�����֤���ݺϷ��ԣ���ʼ��������ֵ���䣻
 ��3���л�ȡ�ꡢ�¡��յ�get������
 ��5��ʵ��Date nextDay()���������ر�ʾ��һ���Date����
 ��6��ʵ��int difference(Date)���������ص�ǰ����Ͳ���ָ������֮��������
 ��7����yyyy-mm-dd�ĸ�ʽ�����ǰ���ڡ�
 ��д���Գ���
 *
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Date{
public:
	//constructor
	Date(int y, int m, int d);
	Date();

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	Date nextDay()const;
	int difference(const Date& date);

	string toString()const;

private:
	int year = 1970;
	int month = 1;
	int day = 1;
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static bool leapYear(int year);
	bool leapYear()const;
	int daysInTheYear()const;
};

Date::Date(int y, int m, int d){
	if (y > 0)
		year = y;
	else
		year = 1970;

	if(m >= 1 && m <= 12)
		month = m;
	else
		month = 1;

	if(leapYear() && month == 2){
		if(d >= 1 && d <= 29)
			day = d;
		else
			day = 1;
	}
	else{
		if(d >= 1 && d <= days[month])
			day = d;
		else
			day = 1;
	}
}

Date::Date() : Date(1970, 1, 1){}

Date Date::nextDay() const {

	if(day == 31 && month == 12)
		return Date(year + 1, 1, 1);

	if(day == 29 && month == 2 && leapYear())
		return Date(year, 3, 1);

	if(day == days[month] && month != 12)
		return Date(year, month + 1, 1);

	return Date(year, month, day+1);
}

int Date::difference(const Date& date)
{
	int dif = 0;
	if(this->year == date.year)
		dif = this->daysInTheYear() - date.daysInTheYear();
	else if(this->year < date.year)
	{
		for(int y = this->year; y < date.year; ++y)
		{
			if(leapYear(y))
				dif += 366;
			else
				dif += 365;
		}
		dif = dif - this->daysInTheYear() + date.daysInTheYear();
	}
	else{
		for(int y = date.year; y < this->year; ++y)
		{
			if(leapYear(y))
				dif += 366;
			else
				dif += 365;
		}
		dif = dif - date.daysInTheYear() + this->daysInTheYear();
	}

	return dif;
}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}
bool  Date::leapYear(int year){
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
bool  Date::leapYear() const{
	return leapYear(year);
}

string Date::toString() const {
	ostringstream os;
	os << year << "-" << month << "-" << day;
	return os.str();
}

int  Date::daysInTheYear()const{
	int sum = 0;
	for(int i = 1; i < month; ++i)
		sum += days[i];
	sum += day;

	if(leapYear() && month > 2)
		++sum;
	return sum;
}
//---------------------------------------------

int main()
{
	Date d1(2016, 2, 29);
	Date d2(2015, 2, 28);
	Date d3(2011, 9, 30);
	Date d4(2011, 12, 31);
	Date d5(2010, 9, 10);

	cout << d1.toString() << endl;
	cout << d1.nextDay().toString() << endl;

	cout << d1.toString() << "\t" << d2.toString() << "\t"
			<< d1.difference(d2) << endl;

	cout << d4.toString() << "\t" << d4.nextDay().toString() << endl;

	cout << d5.toString()<< "\t" << d3.toString()
			<< "\t" << d5.difference(d3) << endl;

	cout << d3.toString() << "\t" << d3.nextDay().toString() << endl;
	cout << d5.toString() << "\t" << d5.nextDay().toString() << endl;


	return 0;
}

