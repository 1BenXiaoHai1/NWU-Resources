/*
 * ex3_18.cpp
 *
 *      18. 编写程序，打印如下图所示的反向九九乘法表。
 */
#include <iostream>
using namespace std;
int main()
{
	for(int i=9; i>=1; --i){
		for(int k=9-i; k>=1; k--)
			cout<<"     "<<"\t";
		for(int j = i; j>=1; --j)
			cout<<i<<"*"<<j<<"="<<i*j<<"\t";
		cout<<"\n";
	}
}
