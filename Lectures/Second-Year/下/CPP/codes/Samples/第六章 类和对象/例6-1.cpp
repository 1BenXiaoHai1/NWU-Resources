#include<iostream>

using namespace std;

//�ඨ��
struct SalesData{
	//���ݳ�Ա
	string productNo;
	double price = 0.0;//���ڳ�ʼ��
	unsigned unitSold = 0;
	//��Ա����(���ڶ���)
	double totalRevenue(){return price*unitSold;}
	void read(){cin>>productNo>>price>>unitSold;}
	void print(){cout<<productNo<<":"<<price<<" "<<unitSold<<" "<<totalRevenue()<<endl;}
};

int main()
{
	SalesData a;
	
	cout<<"Enter Data:"<<endl;
	a.read();
	a.print();
}
