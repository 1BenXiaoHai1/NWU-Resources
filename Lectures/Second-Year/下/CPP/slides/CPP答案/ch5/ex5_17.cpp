/*
 * ex5_1.cpp
 *
 *  17. �ٶ�С����һ���¾��ܳ��ɴ����ӣ���һ�Դ�����ÿ���¶�������һ��С���ӡ�
 *  ����������һ��С���ӣ��ʵ����ʱ�ж��ٶ����ӣ��õݹ麯�����������⡣
 *
 */

#include <iostream>
using namespace std;

int rabbit(int big, int small, int month)
{
	if(month == 0)
		return big+small;
	else
		return rabbit(big+small, big, month-1);
}

int main()
{
	cout<<rabbit(0,1,12)<<endl;
}

