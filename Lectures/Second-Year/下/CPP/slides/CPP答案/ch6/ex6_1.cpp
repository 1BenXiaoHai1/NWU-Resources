/*
 * ex6_1.cpp
 *
 * 1. 定义下列类的数据成员并提供适当的初始化方法：
 * （1）日期Date
 * （2）员工Employee
 * （3）学生Student
 *
 *
 */
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Date{
	int year = 1970;
	int month = 1;
	int day = 1;
public:
	//constructor
	Date(int y, int m, int d){
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
	//default constructor
	Date() : Date(1970, 1, 1){}

private:
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool leapYear() const{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

};

class Employee{
	string name;
	unsigned int id;
	string department;
	string title;
	double salary = 0;
	string address;
	vector<string> phone;
public:
	Employee(string ename, unsigned eid) : name(ename), id(eid){}
	Employee(string ename, unsigned eid, string dept, string ttl)
	: name(ename), id(eid), department(dept), title(ttl)	{}
};

class Student{
	string name;
	unsigned int id;
	string department;
public:
	Student(string sname, unsigned sid) : name(sname), id(sid){}
	Student(string sname, unsigned sid, string dept) : name(sname), id(sid), department(dept){}

};

int main()
{

	return 0;
}




