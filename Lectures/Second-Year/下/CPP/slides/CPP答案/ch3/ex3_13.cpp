/* ex3_13.cpp
 *
 *
 * 13. ��д���򣬴�ӡ����ͼ��ʾ��1 ��9 �Ľ��ݡ�
 */

#include <iostream>
using namespace std;
int main()
{
	const int max = 10;
	cout<<endl;
	for(int num = 1; num<max; num++)
	{
		for(int j = max-num; j>0; j--)
			cout<<" ";
		for(int j = 1; j<=num; j++)
			cout<<num<<" ";
		cout<<endl;
	}
	return 0;
}




