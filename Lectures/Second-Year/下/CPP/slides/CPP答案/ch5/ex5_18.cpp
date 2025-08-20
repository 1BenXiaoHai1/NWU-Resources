/*
 * ex5_18.cpp
 *
 *  18. 用递归和非递归两种方法编写求最大公约数的函数gcd(m,n)。
 *  求最大公约数的递归方法为：如果m%n 为0，那么gcd(m,n)的值为n；否则，gcd(m,n)就是gcd(n, m%n)。
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

