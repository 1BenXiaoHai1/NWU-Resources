/*
 * ex5_1.cpp
 *
 *  1. 编写函数判断两个int数组是否相等，编写程序测试该函数。
 *
 */


#include <iostream>
using namespace std;
bool arrayCompare(int* a, size_t asize, int* b, size_t bsize)
{
	if(asize != bsize)
		return false;

	for(size_t i= 0; i < asize; ++i)
		if(a[i]!=b[i])
			return false;

	return true;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	int b[] = {3,4,5,6,7,8};
	cout << arrayCompare(a,7,b,6) << endl;
	cout << arrayCompare(a,6,b,6) << endl;
	cout << arrayCompare(a+2,5,b,5) << endl;
	cout << arrayCompare(a+2,5,b+1,5) << endl;
}
