/*
 * test.cpp
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */
#include "delistfunc.h"
#include "delist.h"
#include <iostream>
using namespace std;

//------------------
int main(){
	//functions
	int a = 10;
	Node<int>* dl = createList(a);
	print(dl);
	dl = insertNode(dl,9);
	dl = insertNode(dl,8);
	print(dl);
	dl = delNode(dl, 9);
	print(dl);
	dl = delNode(dl,8);
	print(dl);
	dl = delNode(dl,10);
	print(dl);
	releaseList(dl);
	print(dl);
	//class
	Delist<int> dlst;
	dlst.print();
	dlst.insertFront(1);
	dlst.print();
	dlst.insertFront(2);
	dlst.insertBack(3);
	dlst.print();
	dlst.delNode(2);
	dlst.print();
	dlst.delFront();
	dlst.print();
	dlst.delBack();
	dlst.print();

}
