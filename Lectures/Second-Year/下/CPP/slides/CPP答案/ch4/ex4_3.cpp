/*
 * ex4_3.cpp
 *
 * 3. 将1～100共一百个自然数，放入一个有99个元素的数组a[99]中，编写程序找出没有被放入数组中的数。
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
	//....a中放入1~100

	for(int i=0; i<99; ++i)
		flag[a[i]] = true;

	for(int i=1; i<=100; ++i)
		if(!flag[i])
			cout<<i<<"\t";
}


