//工种超类的声明
#ifndef PEOPLE_H_INCLUDE
#define PEOPLE_H_INCLUDE
#include<iostream>
#include<string>
#include"Basic.h"

using namespace std;

class Employee {
	private:
		string WorkNo;//工号
		string Name;
		Date WorkBeginTime;//开始工作时间
		Date DistributeTime;//结发工资时间
		Date WorkTime;//实际工作时长
	public:
		//成员函数
		//构造函数
		Employee();//默认构造函数
		Employee(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime); //隐式类型转换构造函数
		Employee(const Employee&a);//拷贝构造函数
		//访问器和修改器
		string getWorkNo();
		void setWorkNo(string WorkNo);
		string getName();
		void setName(string Name);
		Date getWorkBeginTime();
		void setWorkBeginTime(Date WorkBeginTime);
		Date getDistributeTime();
		void setDistributeTime(Date DistributeTime);
		Date getWorkTime();
		
		
		//虚函数——希望子类覆盖的函数
		virtual void Information();//显示信息——const成员函数，对对象不修改
		virtual	Salary CalTotalMoney();//计算总工资
};


#endif

