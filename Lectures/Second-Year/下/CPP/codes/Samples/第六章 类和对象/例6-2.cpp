#include<iostream>

using namespace std;

//类定义
struct SalesData{
	//数据成员
	string productNo;
	double price = 0.0;//类内初始化
	unsigned unitSold = 0;
	//成员函数
	double totalRevenue();
	void read();
	void print();
};

//类外成员函数定义与普通函数定义的区别：类成员函数要加类+域解析运算符
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
