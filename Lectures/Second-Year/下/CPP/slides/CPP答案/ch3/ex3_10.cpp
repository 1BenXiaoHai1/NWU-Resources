/*
 * ex3_10.cpp
 *
 *  10. ��д���򣬶��벻���������������ж϶���������͸������ж��ٸ���0��������
 *  Ȼ�������Щ����ֵ���ܺͼ���ƽ��ֵ��������0ʱ��������������
 *
 *  �������ͳ����Ϣ������ƽ��ֵ�Ը�������ʽ��ʾ��2λС����
 */


#include<iostream>
using namespace std;

int main()
{
	int number, sum = 0, neg = 0, pos = 0;
	cout << "enter integers, end with 0" << endl;
	do{
		cin >> number;

		if(number == 0)
			break;
		else if(number > 0)
			++pos;
		else
			++neg;

		sum += number;

	}
	while(number != 0);


	cout << "positive numbers : " << pos << endl;
	cout << "negative numbers : " << neg << endl;
	cout.precision(2);
	if(pos + neg != 0)
		cout << "average value: " << fixed << (sum * 1.0 / (pos + neg))<<endl;
	else
		cout <<  "average value is 0." << endl;

	return 0;
}

