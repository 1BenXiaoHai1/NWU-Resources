/*
 * ex3_17.cpp
 *
 *      17. ��д���򣬴�ӡ����ͼ��ʾ�ľžų˷���
 */
#include <iostream>
using namespace std;
int main()
{
	for(int i=1; i<=9; ++i){
		for(int j = 1; j<=i; ++j)
			cout<<j<<"*"<<i<<"="<<j*i<<"\t";
		cout<<"\n";
	}
}

