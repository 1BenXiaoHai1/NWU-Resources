#include<iostream>

using namespace std;

int main()
{
	int ival = 1024;
	int *pi = &ival;
	cout<<"sizeof(pi):"<<sizeof(pi)<<endl;//ָ��Ĵ�С�����ĸ��ֽ�
	cout<<"sizeof(ival):"<<sizeof(ival)<<endl;//ival int�ͱ����Ĵ�С
	cout<<"&pi:"<<&pi<<endl;//piָ������ĵ�ַ
	cout<<"pi:"<<pi<<endl;//pi������
	cout<<"&ival:"<<&ival<<endl;//ival�����ĵ�ַ
	cout<<"*pi:"<<*pi<<endl;//ָ�������ָ�Ķ���
	cout<<"ival"<<ival<<endl;
	
	return 0;
}
