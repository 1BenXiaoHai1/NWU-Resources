/*
 * ex3_5.cpp
 *
 *  5. 编写程序，提示用户输入三个整数，以升序的形式输出这三个整数。
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




