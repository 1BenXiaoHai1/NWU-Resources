/*
 * ex3_18.cpp
 *
 *      18. ��д���򣬴�ӡ����ͼ��ʾ�ķ���žų˷���
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
