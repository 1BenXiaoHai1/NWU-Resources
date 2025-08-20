/*
 * ex5_1.cpp
 *
 *  5. ��д������������ʾһ������������reverse(3456)���6543��
 *
 *  ����ԭ��Ϊ��int reverse(int number);
 *
 */


#include<iostream>
using namespace std;

int reverse(int number){
	int rnumber = 0;
	while(number > 0){
		rnumber = rnumber * 10 + number % 10;
		number /= 10;
	}
	return rnumber;
}

int main()
{
	cout << "Enter an integer: " << endl;
	int n;
	cin >> n;
	cout << "reverse(" << n << ") is " << reverse(n) << endl;

	return 0;
}

