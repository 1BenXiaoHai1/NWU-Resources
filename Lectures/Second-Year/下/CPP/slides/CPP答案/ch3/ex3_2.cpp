/*
 * ex3_2.cpp
 * 2. ��д���򣬶�ȡһ��0~1000֮��������������������ĸ�λ������ӡ�
 * ���磬��������372����λ����֮��Ϊ12��
 */

#include<iostream>
using namespace std;
int main()
{
	cout << " enter a number between 0 and 1000: " << endl;
	int number;
	cin >> number;
	int sum = 0;
	//����һ��1000����
	sum += number % 10;			// ��λ
	sum += (number / 10) % 10;	// ʮλ
	sum += number / 100;		// ��λ

//������ѭ���⣺�κ�������
//	for(int k = number; k > 0; k /= 10) sum += k%10;
//
	cout << "sum of digits in " << number << " is: " << sum << endl;
	return 0;
}



