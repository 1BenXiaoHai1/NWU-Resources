/*
 * ex9p5.cpp
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 *      5. 设计并实现一个通用单链表类。
 */
#include <iostream>
#include "singlelist.h"
using namespace std;

//---------------------------------------------------
//客户程序test.cpp
int main()
{
	slist<char> w;
	w.prepend('A');
	w.prepend('B');
	w.prepend('C');
	w.print();
	w.del();
	w.print();
	slist<int> is;
	is.prepend(1);
	is.prepend(2);
	is.prepend(3);
	is.prepend(4);
	is.print();
}
