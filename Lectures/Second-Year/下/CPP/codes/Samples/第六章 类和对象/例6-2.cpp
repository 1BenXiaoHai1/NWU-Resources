#include<iostream>

using namespace std;

//�ඨ��
struct SalesData{
	//���ݳ�Ա
	string productNo;
	double price = 0.0;//���ڳ�ʼ��
	unsigned unitSold = 0;
	//��Ա����
	double totalRevenue();
	void read();
	void print();
};

//�����Ա������������ͨ����������������Ա����Ҫ����+����������
double SalesData::totalRevenue()
{
	return price*unitSold;
}

void SalesData::read()
{
	cin>>productNo>>price>>unitSold;
}

void SalesData::print()
{
	cout<<productNo<<":"<<price<<" "<<unitSold<<" "<<totalRevenue()<<endl;
}

int main()
{
	SalesData a;
	
	cout<<"Enter Data:"<<endl;
	a.read();
	a.print();
}
