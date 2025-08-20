/*
 * ex3_16.cpp
 *
  * 16.编写程序， 计算e=1+1/1!+1/2!+1/3！+...+1/n!...的近似值
  * 要求误差小于0.00001。
 */
#include <iostream>
using namespace std;
const double limit = 1e-5;
int main()
{
	double e = 1;
	double factorial = 1;
	int num = 1;
	do{
		factorial /= num++;
		e += factorial;
	}while(factorial > limit);
	cout<<"e="<<e<<endl;
}

