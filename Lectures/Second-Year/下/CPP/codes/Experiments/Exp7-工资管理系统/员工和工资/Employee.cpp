//�����Ա��������
#include"Employee.h"

using namespace std;


//Ĭ�Ϲ��캯��(���ó�ʼ���б��ʼ��)�����������ֱ�ӳ�ʼ���������Ӧ�Ĺ��캯��
Employee::Employee(): WorkNo("NULL"), Name("John Doe"), WorkBeginTime(), DistributeTime() {
}
//��ʽ����ת�����캯��
Employee::Employee(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime) {
	this->WorkNo = WorkNo;
	this->Name = Name;
	this->WorkBeginTime = WorkBeginTime; //����Date��Ŀ������캯��
	this->DistributeTime = DistributeTime;
	//ʵ�ʹ���ʱ�����ڹ��ʷ���ʱ�����ʼ����ʱ��
	this->WorkTime = DistributeTime - WorkBeginTime; //����Date���-����������غ���
//	this->TotalMoney = CalTotalMoney(); //�ܹ����ɺ�������õ�������Salary��Ŀ������캯��
}
//�������캯��
Employee::Employee(const Employee&a) {
	WorkNo = a.WorkNo;
	Name = a.Name;
	WorkBeginTime = a.WorkBeginTime;
	DistributeTime = a.DistributeTime;
	WorkTime = a.WorkTime;
}

//������
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
Date Employee::getWorkTime() { //��ȡʵ�ʹ���ʱ��
	return WorkTime;
}


void Employee::setWorkNo(string WorkNo) {
	this->WorkNo = WorkNo;
	cout << "�����޸ĳɹ�" << endl;
	return;
}
void Employee::setName(string Name) {
	this->Name = Name;
	cout << "�����޸ĳɹ�" << endl;
	return;
}

void Employee::setWorkBeginTime(Date WorkBeginTime) {
	this->WorkBeginTime = WorkBeginTime;
	cout << "��ʼ����ʱ���޸ĳɹ�" << endl;
	return;
}
void Employee::setDistributeTime(Date DistributeTime) {
	this->DistributeTime = DistributeTime;
	cout << "��������ʱ���޸ĳɹ�" << endl;
	return;
}

//������û��ʵ���ô�����Ҫ����������д����

//Ա����Ϣ��ʾ(�麯��-��ͬ�����ӡ����Ϣ��ͬ)
void Employee::Information()  {
	return;
}

//�������ù���(�麯��-��ͬ�����ӡ����Ϣ��ͬ)
Salary Employee:: CalTotalMoney() {
	return 0;
}


