//基础类的声明
#ifndef BASIC_H_INCLUDE
#define BASIC_H_INCLUDE
#include<iostream>
#include<string>

using namespace std;

//Date类
class Date {
	int Year;
	int Month;
	int Day;
public:
	Date();//默认构造函数
	Date(int _year,int _month,int _day);//隐式类型转换构造函数
	Date(const Date& a);//拷贝构造函数
	//访问器和修改器
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int _year);
	void setMonth(int _month);
	void setDay(int _day);
	
	friend const  Date operator-( Date& left, Date& right);//-双目运算符重载——非成员函数
	
};


class Salary {
	int Pay;
public:
	Salary();//默认构造函数
	Salary(int Pay);//隐式类型转换构造函数
	Salary(const Salary &a);//拷贝构造函数
	int getPay();
	void setPay(int Pay);
	//运算符重载
	const Salary operator +(const Salary& right) const;
	const Salary operator -(const Salary&right) const;
};


#endif
