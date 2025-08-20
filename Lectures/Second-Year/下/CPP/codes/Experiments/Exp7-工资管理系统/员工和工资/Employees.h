//���������
#ifndef EMPLOYS_H_INCLUDE
#define EMPLOYS_H_INCLUDE
#include"Employee.h"
#include<vector>

using namespace std;

//������Ա��
class ProducePerson : public Employee {
protected:
		Salary DaySalary = 500;//��ˮ��Ա��ÿ����н500Ԫ����������ʽ����ת�����캯��
		int WorkDays;//����������
public:
		//���캯��
		ProducePerson();//Ĭ�Ϲ��캯��
		ProducePerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime);
		//���Ǹ���ĺ������麯����
		Salary CalTotalMoney() override;
		void Information() override;
};
//����Ա��
class SalesPerson : virtual public Employee {
protected:
		Salary DaySalary = 400;//����Ա����нΪ400Ԫ
		Salary SaleSalary = 50;//ÿ����һ�����50Ԫ
		int WorkDays;//����������
		int SalesNum;//���۲�Ʒ����
public:
		//���캯��
		SalesPerson();
		SalesPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum);
		//�麯��-���Ǹ���ĺ���
		Salary CalTotalMoney() override;//н�ʼ���-���ǻ���ĺ���
		void Information() override;//��Ϣ��ʾ
};
//����Ա��-�����̳�Employee ��Ϊ����� SalesConsultPersonҪ�̳У����������Ϊ����࣬�ᵼ�¶�����
class ConsultPerson : virtual public Employee {
protected:
		Salary ConsultSalary = 300;//ÿ����ѯ��300Ԫ
		int ConsultTimes;//��ѯ����
public:
		ConsultPerson();
		ConsultPerson(string WorkNo, string Name, int ConsultTimes);
		//���Ǹ���ĺ���
		Salary CalTotalMoney() override;
		void Information() override;
};

//���۹���
class SalesConsultPerson :public SalesPerson,public ConsultPerson {
public:
	SalesConsultPerson();
	SalesConsultPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum,int ConsultTimes);
	Salary CalTotalMoney() override;
	void Information() override;
};


//���ʹ���Ա
class SalaryManager {
public:
	//��Ա����
	vector<Employee*> Workers;//�洢����Ա��������̬���飨��������ת����
	//��Ա����
	SalaryManager(){};
	Salary getTotalSalary();//��ȡ����Ա�����ܹ���
	void getAllInfo();//������Ϣ

};


#endif
