#include <iostream>
#include<string>
#include"Basic.h"
#include"Employee.h"
#include"Employees.h"

using namespace std;

int main(int argc, char** argv) {
	const Date timeBegin(2021, 2, 10); //�ϴη�����ʱ��
	const Date timeEnd1(2021, 4, 10); //���η�����ʱ��
	//������Ա��
	ProducePerson Worker1("001", "����", timeBegin, timeEnd1);
	//����Ա��
	SalesPerson Worker2("002", "����", timeBegin, timeEnd1, 50);
	//������Ա��
	ConsultPerson Worker3("003", "����", 40);
	//���۹�����Ա��
	SalesConsultPerson Worker4("004","����",timeBegin, timeEnd1, 50, 40);
	//���ʹ���Ա
	SalaryManager Boss;
	Boss.Workers = {&Worker1,&Worker2,&Worker3,&Worker4};//���鸳ֵ
	Boss.getAllInfo();
	cout<<"����Ա���ܹ���Ϊ:"<<Boss.getTotalSalary().getPay()<<endl;	
	system("pause");

	return 0;
}
