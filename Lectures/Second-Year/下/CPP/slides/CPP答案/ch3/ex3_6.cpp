/*
 * ex3_6.cpp
 *
 *  6. ��д���򣬶�ȡ�����ε����߳����������ֵ�Ϸ����ͼ��������ε��ܳ���������ʾ��Щ����ֵ���Ϸ���
 */

#include<iostream>
using namespace std;
int main()
{
	cout << "enter 3 sides of triangle :" << endl;
	double a, b, c;
	cin >> a >> b >> c;

	if(a < 0 || b < 0 || c <0 ||
			a+b <= c || b+c <= a || a+c <= b
			|| a-b >= c || b-c >= a || c-a >= b)
	{
		cout << "invalid sides. " << endl;
		return 1;
	}

	cout <<"perimeter is: " << a + b + c << endl;
	return 0;
}



