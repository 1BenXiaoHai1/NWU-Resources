//超类成员函数定义
#include"Employee.h"

using namespace std;


//默认构造函数(采用初始化列表初始化)——期中类的直接初始化会调用相应的构造函数
Employee::Employee(): WorkNo("NULL"), Name("John Doe"), WorkBeginTime(), DistributeTime() {
}
//隐式类型转换构造函数
Employee::Employee(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime) {
	this->WorkNo = WorkNo;
	this->Name = Name;
	this->WorkBeginTime = WorkBeginTime; //调用Date类的拷贝构造函数
	this->DistributeTime = DistributeTime;
	//实际工作时长等于工资发放时间减开始工作时间
	this->WorkTime = DistributeTime - WorkBeginTime; //调用Date类的-号运算符重载函数
//	this->TotalMoney = CalTotalMoney(); //总工资由函数计算得到，调用Salary类的拷贝构造函数
}
//拷贝构造函数
Employee::Employee(const Employee&a) {
	WorkNo = a.WorkNo;
	Name = a.Name;
	WorkBeginTime = a.WorkBeginTime;
	DistributeTime = a.DistributeTime;
	WorkTime = a.WorkTime;
}

//访问器
string Employee::getWorkNo()  {
	return WorkNo;
}

string Employee::getName()  {
	return Name;
}

Date Employee::getWorkBeginTime() {
	return WorkBeginTime;
}
Date Employee::getDistributeTime() {
	return DistributeTime;
}
Date Employee::getWorkTime() { //获取实际工作时长
	return WorkTime;
}


void Employee::setWorkNo(string WorkNo) {
	this->WorkNo = WorkNo;
	cout << "工号修改成功" << endl;
	return;
}
void Employee::setName(string Name) {
	this->Name = Name;
	cout << "姓名修改成功" << endl;
	return;
}

void Employee::setWorkBeginTime(Date WorkBeginTime) {
	this->WorkBeginTime = WorkBeginTime;
	cout << "开始工作时间修改成功" << endl;
	return;
}
void Employee::setDistributeTime(Date DistributeTime) {
	this->DistributeTime = DistributeTime;
	cout << "工作发放时间修改成功" << endl;
	return;
}

//父类中没有实际用处，需要在子类中重写覆盖

//员工信息显示(虚函数-不同子类打印的信息不同)
void Employee::Information()  {
	return;
}

//计算所得工资(虚函数-不同子类打印的信息不同)
Salary Employee:: CalTotalMoney() {
	return 0;
}


