/*
 * ex3_20.cpp
 *
 *  20. ��д���򣬶���һ��������Ȼ����������ʾ����������С���ӡ�
 *  ���磬��������120�������Ӧ���ǣ�2��2��2��3��5��
 */
#include<iostream>
using namespace std;

int main()
{
	cout << "enter an integer: " << endl;
	int number;
	cin >> number;

	int remain = number;
	while(remain > 1)
	{
		int factor = 2;

		while(factor <= remain){
			if(remain % factor == 0){
				cout << factor << " ";
				remain = remain / factor;
				break;
			}
			else
				++factor;
		}
	}

	return 0;
}



