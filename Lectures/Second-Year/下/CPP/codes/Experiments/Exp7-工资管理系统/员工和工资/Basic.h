//�����������
#ifndef BASIC_H_INCLUDE
#define BASIC_H_INCLUDE
#include<iostream>
#include<string>

using namespace std;

//Date��
class Date {
	int Year;
	int Month;
	int Day;
public:
	Date();//Ĭ�Ϲ��캯��
	Date(int _year,int _month,int _day);//��ʽ����ת�����캯��
	Date(const Date& a);//�������캯��
	//���������޸���
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int _year);
	void setMonth(int _month);
	void setDay(int _day);
	
	friend const  Date operator-( Date& left, Date& right);//-˫Ŀ��������ء����ǳ�Ա����
	
};


class Salary {
	int Pay;
public:
	Salary();//Ĭ�Ϲ��캯��
	Salary(int Pay);//��ʽ����ת�����캯��
	Salary(const Salary &a);//�������캯��
	int getPay();
	void setPay(int Pay);
	//���������
	const Salary operator +(const Salary& right) const;
	const Salary operator -(const Salary&right) const;
};


#endif
