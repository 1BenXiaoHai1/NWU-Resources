#include<iostream>

using namespace std;

int main()
{
	int ival = 1024;
	int *pi = &ival;
	cout<<"sizeof(pi):"<<sizeof(pi)<<endl;//指针的大小——四个字节
	cout<<"sizeof(ival):"<<sizeof(ival)<<endl;//ival int型变量的大小
	cout<<"&pi:"<<&pi<<endl;//pi指针变量的地址
	cout<<"pi:"<<pi<<endl;//pi的内容
	cout<<"&ival:"<<&ival<<endl;//ival变量的地址
	cout<<"*pi:"<<*pi<<endl;//指针变量所指的对象
	cout<<"ival"<<ival<<endl;
	
	return 0;
}
