/*
 * ch13
 * test.cpp
 * 6. 设计并实现一个带异常处理的动态数组类。
 */

#include <iostream>
#include "vect.h"
using namespace std;
int main()
try
{
	int a[]={1,2,3,4,5,6};
	Vect v(a,6);
	for(int i=0; i<v.count();i++)
		cout<<v[i]<<"\t";
	v[0] = 10;
	for(int i=0; i<v.count();i++)
		cout<<v[i]<<"\t";

	Vect v1(v);
	for(int i=0; i<v1.count();i++)
		cout<<v1[i]<<"\t";
	Vect v2;
	v2.copy(v);
	for(int i=0; i<v2.count();i++)
		cout<<v2[i]<<"\t";
	//Vect ve(0);
	v2[100];
}
catch(excp &e){
	e.message();
}
