/*
 * ex5_19.cpp
 *
 *  19. 用递归和非递归两种方法编写函数计算下面的数列和：
 *  1/2 + 2/3 + ... + i/(i+1)
 */

#include<iostream>
using namespace std;

double sum(int n){
	double m = 0;
	for(int i = 1; i <= n; ++i){
		m += 1.0 * i / (i + 1);
	}
	return m;

}

double sumR(int n){
	double m = 0;

	if(n > 1)
		m = sumR(n-1) + (1.0 * n /(n + 1));
	else if(n == 1)
		m = 1.0 / 2;

	return m;
}

int main()
{
	cout << "m(1000) = " << sum(1000) << endl;
	cout << "m(1000) = " << sumR(1000) << endl;
	cout << "m(100) = " << sum(100) << endl;
	cout << "m(100) = " << sumR(100) << endl;
	cout << "m(10) = " << sum(10) << endl;
	cout << "m(10) = " << sumR(10) << endl;
	cout << "m(5) = " << sum(5) << endl;
	cout << "m(5) = " << sumR(5) << endl;
	cout << "m(2) = " << sum(2) << endl;
	cout << "m(2) = " << sumR(2) << endl;
	cout << "m(1) = " << sum(1) << endl;
	cout << "m(1) = " << sumR(1) << endl;

	return 0;
}

