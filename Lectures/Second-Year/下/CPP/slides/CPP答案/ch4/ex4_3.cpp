/*
 * ex4_3.cpp
 *
 * 3. ��1��100��һ�ٸ���Ȼ��������һ����99��Ԫ�ص�����a[99]�У���д�����ҳ�û�б����������е�����
 *
 *
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iterator>
using namespace std;
bool flag[101];
int main()
{
	int a[99];
	//....a�з���1~100

	for(int i=0; i<99; ++i)
		flag[a[i]] = true;

	for(int i=1; i<=100; ++i)
		if(!flag[i])
			cout<<i<<"\t";
}


