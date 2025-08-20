/*
 * test.cpp
 *
 * ch11
 *  6. 设计一个数组类模板Array<T>，其中包含数组的常规操作、排序和查找等方法。
使用各类型的数据对其进行测试。
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

