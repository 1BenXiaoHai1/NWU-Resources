#include <iostream>
#include<string>
#include"Basic.h"
#include"Employee.h"
#include"Employees.h"

using namespace std;

int main(int argc, char** argv) {
	const Date timeBegin(2021, 2, 10); //上次发工资时间
	const Date timeEnd1(2021, 4, 10); //本次发工资时间
	//生产线员工
	ProducePerson Worker1("001", "张三", timeBegin, timeEnd1);
	//销售员工
	SalesPerson Worker2("002", "李四", timeBegin, timeEnd1, 50);
	//顾问类员工
	ConsultPerson Worker3("003", "王五", 40);
	//销售顾问类员工
	SalesConsultPerson Worker4("004","赵六",timeBegin, timeEnd1, 50, 40);
	//工资管理员
	SalaryManager Boss;
	Boss.Workers = {&Worker1,&Worker2,&Worker3,&Worker4};//数组赋值
	Boss.getAllInfo();
	cout<<"所有员工总工资为:"<<Boss.getTotalSalary().getPay()<<endl;	
	system("pause");

	return 0;
}
