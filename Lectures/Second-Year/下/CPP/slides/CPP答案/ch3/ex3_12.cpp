/*
 * ex3_12.cpp
 *
 *  12. ����ĳ��ѧ�����ѧ��Ϊ5000Ԫ��ѧ�ѵ���������Ϊ5%��
 *   ��д���򣺣�1������10����ѧ�ѣ���2�����������ѧ������4�깲������ѧ�ѣ���3������ѧ�ѷ�һ����Ҫ���ꡣ
 */

#include<iostream>
using namespace std;

int main()
{
	double tuitionNow = 5000;
	double rate = 0.05;

	double tuitionAfter10years = tuitionNow;
	for(int i = 0; i < 10; ++i)
		tuitionAfter10years = tuitionAfter10years * ( 1 + rate);

	double tuition4years = 0, fee = tuitionNow;
	for(int i = 0; i < 4; ++i){
		tuition4years = tuition4years + fee;
		fee = fee * ( 1 + 0.05);
	}

	int years = 0;
	fee = tuitionNow;
	while(fee < tuitionNow * 2){
		fee = fee * (1 + 0.05);
		++years;
	}

	cout << "Tuition after 10 years: " << tuitionAfter10years << endl;
	cout << "Total tuition 4 years: " << tuition4years << endl;
	cout << "Tuition will double after " << years << " years." << endl;

	return 0;
}


