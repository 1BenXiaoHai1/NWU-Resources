/*
 * ex4_4.cpp
 *
 * 4. 8，64，256都是2的阶次方数（如64是2的6次方），用两种方法编写程序判断一个整数是不是2的阶次方数，并说明哪种方法更好。
 *
 */
#include <iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Please input a number:"<<endl;
	cin >> num;
	//algorithm 1
	int i = num;
	do{
		if(i%2==0)
			i /= 2;
		else
			break;
	}while(i);
	if (i==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	//algorithm 2
	i=num;
	while(i){
		if(!(i&1))
			i>>=1;
		else
			break;
	}
	if (i==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}


