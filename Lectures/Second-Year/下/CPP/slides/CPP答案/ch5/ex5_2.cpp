/*
 * ex5_2.cpp
 *
 *  2. ��д����������һ�������ĸ�λ����֮�͡��õݹ�ͷǵݹ����ַ���ʵ�֡�
 *  ����ԭ��Ϊ��int sumDigits(long n);
 */


#include<iostream>
using namespace std;

int sumDigits(long n){
	int sum = 0;
	while(n > 0){
		sum += n % 10;
		n /= 10;
	}

	return sum;

}
//reursive function
int sumDigitsR(long n){

	if (n > 0)
		return (n % 10) + sumDigitsR(n / 10);
	else
		return 0;

}
int main()
{
	long n = 123456780L;
	cout << n << " digits sum = " << sumDigits(n) << endl;
	cout << n << " digits sum = " << sumDigitsR(n) << endl;

	return 0;
}

