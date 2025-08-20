//子类成员函数定义
#include"Employees.h"

using namespace std;

//生产线员工

//构造函数
//默认
ProducePerson::ProducePerson():Employee() {
	this->WorkDays = 0;
}
//隐式类型转换
ProducePerson::ProducePerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime) :Employee(WorkNo,Name,WorkBeginTime,DistributeTime){
	//子类的新的成员的初始化
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //工作时长
}

//薪资计算函数
Salary ProducePerson::CalTotalMoney() {
	//总薪资 = 日薪 * 工作天数
	return DaySalary.getPay() * WorkDays;
}

//信息输出
void ProducePerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\t员工信息" << endl;
	cout << "员工类型：生产线员工" << endl;
	cout << "工号：" << getWorkNo() << "\t" << "姓名：" << getName() << endl
	     << "工作时间:" <<WorkDays<<"天"<< endl;
	cout << "工作日薪:" << DaySalary.getPay() << endl;
	cout << "总薪资:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//销售员
//默认构造函数
SalesPerson::SalesPerson():Employee(),WorkDays(0),SalesNum(0) {
}
//隐式类型转换构造函数
SalesPerson::SalesPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum) :Employee(WorkNo,Name,WorkBeginTime,DistributeTime),SalesNum(SalesNum){
	//工作天数
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //工作时长
	this->SalesNum = SalesNum;
}
//薪资计算
Salary SalesPerson::CalTotalMoney() {
	return DaySalary.getPay() * WorkDays + SalesNum * SaleSalary.getPay(); //每销售一件产品提成50
}

void SalesPerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\t员工信息" << endl;
	cout << "员工类型：销售员工" << endl;
	cout << "工号：" << getWorkNo() << "\t" << "姓名：" << getName() << endl
	     << "工作时间:" <<WorkDays<<"天"<<endl; 
	cout << "工作日薪:" << DaySalary.getPay() << endl;
	cout << "每销售一件的提成:" << SaleSalary.getPay() << endl;
	cout << "销售件数:" << SalesNum << endl;
	
	cout << "总薪资:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//咨询员工
//默认构造函数
ConsultPerson::ConsultPerson() :Employee(),ConsultTimes(0) {
}
/*隐式类型转换构造函数-注意这里日期的初始化
（因为咨询顾问是以次数为计算单位，因此设开始工作时间和发放工资时间均为0。初始化时需要调用Date的默认初始化）*/
ConsultPerson::ConsultPerson(string WorkNo, string Name, int ConsultTimes):Employee(WorkNo,Name,Date(),Date()),ConsultTimes(ConsultTimes) {
}

//薪资计算
Salary ConsultPerson::CalTotalMoney() {
	return ConsultSalary.getPay() * ConsultTimes;
}

void ConsultPerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\t员工信息" << endl;
	cout << "员工类型：咨询员工" << endl;
	cout << "工号：" << getWorkNo() << "\t" << "姓名：" << getName() << endl;
	cout << "每次咨询薪资:" << ConsultSalary.getPay() << endl;
	cout << "咨询次数：" << ConsultTimes << endl;
	cout << "总薪资:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//销售咨询员工
//构造函数
SalesConsultPerson::SalesConsultPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum,int ConsultTimes):Employee(WorkNo,Name,WorkBeginTime,DistributeTime){
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //工作时长
	this->SalesNum = SalesNum;
	this->ConsultTimes = ConsultTimes;
}

SalesConsultPerson::SalesConsultPerson():Employee(){
	this->SalesNum = 0;
	this->ConsultTimes = 0;
}
//工资计算
Salary SalesConsultPerson::CalTotalMoney(){
	return WorkDays*DaySalary.getPay()+SalesNum*SaleSalary.getPay()+ConsultTimes*ConsultSalary.getPay();
}
//信息显示
void SalesConsultPerson::Information(){
	cout << "--------------------------------" << endl;
	cout << "\t员工信息" << endl;
	cout << "员工类型：销售咨询员工" << endl;
	cout << "工号：" << getWorkNo() << "\t" << "姓名：" << getName() << endl
		<< "工作时间:" <<WorkDays<<"天"<<endl; 
	cout << "工作日薪:" << DaySalary.getPay() << endl;
	cout << "每销售一件的提成:" << 50 << endl;
	cout << "销售件数:" << SalesNum << endl;
	cout << "每次咨询薪资:" << ConsultSalary.getPay() << endl;
	cout << "咨询次数：" << ConsultTimes << endl;
	cout << "总薪资:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}


//工资管理员
//获取总工资
Salary SalaryManager::getTotalSalary(){
	Salary Total;
	//遍历动态数组(指针数组)
	for(int i=0;i<Workers.size();i++){
		Total = Total + Workers[i]->CalTotalMoney();
	}
	
	return Total;
}

//输出所有员工的信息
void SalaryManager::getAllInfo(){
	for(int i=0;i<Workers.size();i++){
		Workers[i]->Information();
		cout<<endl;
	}
	return;
}
