#include<iostream>

using namespace std;

//类定义
struct SalesData{
	//数据成员
	string productNo;
	double price = 0.0;//类内初始化
	unsigned unitSold = 0;
	//成员函数(类内定义)
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
