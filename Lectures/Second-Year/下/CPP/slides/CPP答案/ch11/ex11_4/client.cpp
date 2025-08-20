/*
 * ex11_4.cpp
 *
 *  4. 设计并实现一个通用集合类。
 */
#include "myset.h"
#include <iostream>
using namespace std;
int main()
{
	MySet<char> s;
	s.add('a');
	s.add('b');
	s.listAll();
	MySet<char> s2;
	s2.add('a');
	s2.add('c');
	s2.add('d');
	MySet<char> s3;
	s3 = s.merge(s2);
	s3.listAll();
	s3 = s.trans(s2);
	s3.listAll();
	cout<<s.contain('c')<<endl;
	s2.remove('c');
	s2.listAll();

}
