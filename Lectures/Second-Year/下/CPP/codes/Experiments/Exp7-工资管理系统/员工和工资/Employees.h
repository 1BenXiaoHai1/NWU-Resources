//子类的声明
#ifndef EMPLOYS_H_INCLUDE
#define EMPLOYS_H_INCLUDE
#include"Employee.h"
#include<vector>

using namespace std;

//生产线员工
class ProducePerson : public Employee {
protected:
		Salary DaySalary = 500;//流水线员工每天月薪500元——调用隐式类型转换构造函数
		int WorkDays;//工作总日期
public:
		//构造函数
		ProducePerson();//默认构造函数
		ProducePerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime);
		//覆盖父类的函数（虚函数）
		Salary CalTotalMoney() override;
		void Information() override;
};
//销售员工
class SalesPerson : virtual public Employee {
protected:
		Salary DaySalary = 400;//销售员工日薪为400元
		Salary SaleSalary = 50;//每销售一件提成50元
		int WorkDays;//工作总日期
		int SalesNum;//销售产品件数
public:
		//构造函数
		SalesPerson();
		SalesPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum);
		//虚函数-覆盖父类的函数
		Salary CalTotalMoney() override;//薪资计算-覆盖基类的函数
		void Information() override;//信息显示
};
//顾问员工-虚基类继承Employee 因为后面的 SalesConsultPerson要继承，如果不设置为虚基类，会导致二义性
class ConsultPerson : virtual public Employee {
protected:
		Salary ConsultSalary = 300;//每次咨询费300元
		int ConsultTimes;//咨询次数
public:
		ConsultPerson();
		ConsultPerson(string WorkNo, string Name, int ConsultTimes);
		//覆盖父类的函数
		Salary CalTotalMoney() override;
		void Information() override;
};

//销售顾问
class SalesConsultPerson :public SalesPerson,public ConsultPerson {
public:
	SalesConsultPerson();
	SalesConsultPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum,int ConsultTimes);
	Salary CalTotalMoney() override;
	void Information() override;
};


//工资管理员
class SalaryManager {
public:
	//成员变量
	vector<Employee*> Workers;//存储所有员工——动态数组（向上类型转换）
	//成员函数
	SalaryManager(){};
	Salary getTotalSalary();//获取所有员工的总工资
	void getAllInfo();//所有信息

};


#endif
