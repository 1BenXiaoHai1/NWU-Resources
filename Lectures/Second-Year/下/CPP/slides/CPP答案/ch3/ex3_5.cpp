/*
 * ex3_5.cpp
 *
 *  5. ��д������ʾ�û������������������������ʽ���������������
 */

#include<iostream>
using namespace std;
int main()
{
	cout << "enter 3 numbers: " << endl;
	int a, b, c;
	cin >> a >> b >> c;

	if(a > b){
		int t = a;
		a = b;
		b = t;
	}
	if(c < a){
		cout << c << "\t" << a << "\t" << b << endl;
	}
	else if(c < b){
		cout << a << "\t" << c << "\t" << b << endl;
	}
	else
		cout << a << "\t" << b << "\t" << c << endl;

	return 0;
}




