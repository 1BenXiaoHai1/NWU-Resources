/*
 * test.cpp
 *
 * ch11
 *  6. ���һ��������ģ��Array<T>�����а�������ĳ������������Ͳ��ҵȷ�����
ʹ�ø����͵����ݶ�����в��ԡ�
 */
#include <iostream>
#include "array.h"
using namespace std;
int main()
{
	Array<int> a(10);
	for(int i=0; i<a.size(); i++)
		a[i] = 20-i;
	a.listAll();
	a.sortAll();
	a.listAll();

	Array<double> d(10);
	for(int i=0; i<d.size(); i++)
		d[i] = 20.0/(i+1);
	d.listAll();
	d.sortAll();
	d.listAll();
}

