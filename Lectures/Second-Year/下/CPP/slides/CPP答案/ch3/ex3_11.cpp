/*
 * ex3_11.cpp
 *
 11. ��д������ʾ�û�������������ߣ�Ȼ����ʾ��������ָ����BMI��ֵ������״��˵����
 BMI�ļ��㹫ʽΪ��BMI = weight / height2�����ص�λ�����ߵ�λ�ס�
 ����BMIֵ˵������1��BMI<18.5��ƫ�ݣ���2��18.5��BMI<25.0��������
 ��3��25.5��BMI<30.0�����أ���4��BMI��30.0������
 */

#include<iostream>
using namespace std;

int main()
{
	double weight, height, bmi;

	cout << "Enter your weight in KiloGram: ";
	cin >> weight;
	cout << "Enter you height in Meter: ";
	cin >> height;

	bmi = weight / (height * height);

	cout << "BMI is " << bmi << endl;

	if(bmi < 18.5)
		cout << "Underweight" << endl;
	else if (bmi < 25.0)
		cout << "Normal" << endl;
	else if(bmi < 30)
		cout << "Overweight" << endl;
	else
		cout << "Obese" << endl;

	return 0;
}


