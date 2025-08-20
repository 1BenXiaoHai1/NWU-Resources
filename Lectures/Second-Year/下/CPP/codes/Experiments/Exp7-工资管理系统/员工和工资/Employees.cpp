//�����Ա��������
#include"Employees.h"

using namespace std;

//������Ա��

//���캯��
//Ĭ��
ProducePerson::ProducePerson():Employee() {
	this->WorkDays = 0;
}
//��ʽ����ת��
ProducePerson::ProducePerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime) :Employee(WorkNo,Name,WorkBeginTime,DistributeTime){
	//������µĳ�Ա�ĳ�ʼ��
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //����ʱ��
}

//н�ʼ��㺯��
Salary ProducePerson::CalTotalMoney() {
	//��н�� = ��н * ��������
	return DaySalary.getPay() * WorkDays;
}

//��Ϣ���
void ProducePerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\tԱ����Ϣ" << endl;
	cout << "Ա�����ͣ�������Ա��" << endl;
	cout << "���ţ�" << getWorkNo() << "\t" << "������" << getName() << endl
	     << "����ʱ��:" <<WorkDays<<"��"<< endl;
	cout << "������н:" << DaySalary.getPay() << endl;
	cout << "��н��:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//����Ա
//Ĭ�Ϲ��캯��
SalesPerson::SalesPerson():Employee(),WorkDays(0),SalesNum(0) {
}
//��ʽ����ת�����캯��
SalesPerson::SalesPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum) :Employee(WorkNo,Name,WorkBeginTime,DistributeTime),SalesNum(SalesNum){
	//��������
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //����ʱ��
	this->SalesNum = SalesNum;
}
//н�ʼ���
Salary SalesPerson::CalTotalMoney() {
	return DaySalary.getPay() * WorkDays + SalesNum * SaleSalary.getPay(); //ÿ����һ����Ʒ���50
}

void SalesPerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\tԱ����Ϣ" << endl;
	cout << "Ա�����ͣ�����Ա��" << endl;
	cout << "���ţ�" << getWorkNo() << "\t" << "������" << getName() << endl
	     << "����ʱ��:" <<WorkDays<<"��"<<endl; 
	cout << "������н:" << DaySalary.getPay() << endl;
	cout << "ÿ����һ�������:" << SaleSalary.getPay() << endl;
	cout << "���ۼ���:" << SalesNum << endl;
	
	cout << "��н��:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//��ѯԱ��
//Ĭ�Ϲ��캯��
ConsultPerson::ConsultPerson() :Employee(),ConsultTimes(0) {
}
/*��ʽ����ת�����캯��-ע���������ڵĳ�ʼ��
����Ϊ��ѯ�������Դ���Ϊ���㵥λ������迪ʼ����ʱ��ͷ��Ź���ʱ���Ϊ0����ʼ��ʱ��Ҫ����Date��Ĭ�ϳ�ʼ����*/
ConsultPerson::ConsultPerson(string WorkNo, string Name, int ConsultTimes):Employee(WorkNo,Name,Date(),Date()),ConsultTimes(ConsultTimes) {
}

//н�ʼ���
Salary ConsultPerson::CalTotalMoney() {
	return ConsultSalary.getPay() * ConsultTimes;
}

void ConsultPerson::Information() {
	cout << "--------------------------------" << endl;
	cout << "\tԱ����Ϣ" << endl;
	cout << "Ա�����ͣ���ѯԱ��" << endl;
	cout << "���ţ�" << getWorkNo() << "\t" << "������" << getName() << endl;
	cout << "ÿ����ѯн��:" << ConsultSalary.getPay() << endl;
	cout << "��ѯ������" << ConsultTimes << endl;
	cout << "��н��:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}

//������ѯԱ��
//���캯��
SalesConsultPerson::SalesConsultPerson(string WorkNo, string Name, Date WorkBeginTime, Date DistributeTime, int SalesNum,int ConsultTimes):Employee(WorkNo,Name,WorkBeginTime,DistributeTime){
	this->WorkDays = getWorkTime().getYear() * 365 + getWorkTime().getMonth() * 30 + getWorkTime().getDay(); //����ʱ��
	this->SalesNum = SalesNum;
	this->ConsultTimes = ConsultTimes;
}

SalesConsultPerson::SalesConsultPerson():Employee(){
	this->SalesNum = 0;
	this->ConsultTimes = 0;
}
//���ʼ���
Salary SalesConsultPerson::CalTotalMoney(){
	return WorkDays*DaySalary.getPay()+SalesNum*SaleSalary.getPay()+ConsultTimes*ConsultSalary.getPay();
}
//��Ϣ��ʾ
void SalesConsultPerson::Information(){
	cout << "--------------------------------" << endl;
	cout << "\tԱ����Ϣ" << endl;
	cout << "Ա�����ͣ�������ѯԱ��" << endl;
	cout << "���ţ�" << getWorkNo() << "\t" << "������" << getName() << endl
		<< "����ʱ��:" <<WorkDays<<"��"<<endl; 
	cout << "������н:" << DaySalary.getPay() << endl;
	cout << "ÿ����һ�������:" << 50 << endl;
	cout << "���ۼ���:" << SalesNum << endl;
	cout << "ÿ����ѯн��:" << ConsultSalary.getPay() << endl;
	cout << "��ѯ������" << ConsultTimes << endl;
	cout << "��н��:" << CalTotalMoney().getPay() << endl;
	cout << "--------------------------------" << endl;
}


//���ʹ���Ա
//��ȡ�ܹ���
Salary SalaryManager::getTotalSalary(){
	Salary Total;
	//������̬����(ָ������)
	for(int i=0;i<Workers.size();i++){
		Total = Total + Workers[i]->CalTotalMoney();
	}
	
	return Total;
}

//�������Ա������Ϣ
void SalaryManager::getAllInfo(){
	for(int i=0;i<Workers.size();i++){
		Workers[i]->Information();
		cout<<endl;
	}
	return;
}
