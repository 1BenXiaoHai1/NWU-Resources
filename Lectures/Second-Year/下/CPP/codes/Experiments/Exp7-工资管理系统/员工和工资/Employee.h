//���ֳ��������
#ifndef PEOPLE_H_INCLUDE
#define PEOPLE_H_INCLUDE
#include<iostream>
#include<string>
#include"Basic.h"

using namespace std;

class Employee {
	private:
		string WorkNo;//����
		string Name;
		Date WorkBeginTime;//��ʼ����ʱ��
		Date DistributeTime;//�ᷢ����ʱ��
		Date WorkTime;//ʵ�ʹ���ʱ��
	public:
		//��Ա����
		//���캯��
		Employee();//Ĭ�Ϲ��캯��
		Employee(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime); //��ʽ����ת�����캯��
		Employee(const Employee&a);//�������캯��
		//���������޸���
		string getWorkNo();
		void setWorkNo(string WorkNo);
		string getName();
		void setName(string Name);
		Date getWorkBeginTime();
		void setWorkBeginTime(Date WorkBeginTime);
		Date getDistributeTime();
		void setDistributeTime(Date DistributeTime);
		Date getWorkTime();
		
		
		//�麯������ϣ�����า�ǵĺ���
		virtual void Information();//��ʾ��Ϣ����const��Ա�������Զ����޸�
		virtual	Salary CalTotalMoney();//�����ܹ���
};


#endif

