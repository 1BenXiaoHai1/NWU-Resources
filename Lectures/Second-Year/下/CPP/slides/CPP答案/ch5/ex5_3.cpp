/*
 * ex5_3.cpp
 *
 *  3. 编写函数判断一个整数是不是2的阶次方数，返回bool类型的结果。
 */


#include <iostream>
using namespace std;
bool power1(int n)
{
	do{
		if(n%2==0)
			n /= 2;
		else
			break;
	}while(n);

	return (n == 1);
}

bool power2(int n)
{
	while(n){
		if(!(n&1))
			n>>=1;
		else
			break;
	}

	return (n == 1);
}

bool power3(int n)
{
	if(n==1)
		return true;
	if(n>1 && !(n&1) )
		return power3(n>>1);
	else
		return false;
}
int main()
{
	int num;
	cout<<"Please input a number:"<<endl;
	cin >> num;
	cout<<power1(num)<<endl;
	cout<<power2(num)<<endl;
	cout<<power3(num)<<endl;

}
