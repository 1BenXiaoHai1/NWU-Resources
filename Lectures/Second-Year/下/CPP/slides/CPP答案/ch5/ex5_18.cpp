/*
 * ex5_18.cpp
 *
 *  18. �õݹ�ͷǵݹ����ַ�����д�����Լ���ĺ���gcd(m,n)��
 *  �����Լ���ĵݹ鷽��Ϊ�����m%n Ϊ0����ôgcd(m,n)��ֵΪn������gcd(m,n)����gcd(n, m%n)��
 *
 */


#include<iostream>
using namespace std;

int gcd(int m, int n){
	int d = (m < n) ? m : n;
	while (d >= 1){
		if((m % d == 0) && (n % d == 0))
			break;
		--d;
	}
	return d;
}
//recursive
int gcdR(int m, int n){
	if(m % n == 0)
		return n;
	else
		return gcd(n, m%n);
}

int main()
{
	cout << "Enter 2 integers: " << endl;
	int m, n;
	cin >> m >> n;

	cout << "gcd(" << m << "," << n << ") = " << gcd(m, n) << endl;
	cout << "gcd(" << m << "," << n << ") = " << gcdR(m, n) << endl;

	return 0;
}

