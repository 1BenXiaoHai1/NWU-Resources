/*
 * ex13_5.cpp
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 *      5. 设计并实现一个带异常处理的整型堆栈类。
 */
#include "intStack.h"
#include <iostream>
using namespace std;
int main()
{
	try{
		//IntStack st(-1);
		int a[10]= {1,2,3,4,5,6,7,8,9,10};
		IntStack st1(a,10);
		//st1.push(11);
		st1.clear();
		//cout<<st1.pop();
		//cout<<st1.top_of();
	}
	catch(InvalidStackSize e){
		e.message();
	}
	catch(PushOnFull e){
		e.message();
	}
	catch(PopOnEmpty e){
		e.message();
	}
	catch(TopOfEmpty e){
		e.message();
	}
}
