/*
 * ex3_6.cpp
 *
 *  6. 编写程序，读取三角形的三边长，如果输入值合法，就计算三角形的周长；否则，显示这些输入值不合法。
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



