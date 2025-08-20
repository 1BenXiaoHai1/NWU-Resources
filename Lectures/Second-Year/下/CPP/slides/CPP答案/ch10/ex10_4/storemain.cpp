/*
 * storemain.cpp
 *
 * 4．完成小芳便利店第三个版本。第三个版本要求：
（1）在第二个版本的基础上增加进口货物类ImportedGoods；要求在进口货物的名称
后加“<I>”，其价格在基本货物价格的基础上增加20％。
（2）格式化价格的输出，至少保留两位小数。

 */
#include "store.h"
#include <iostream>
using namespace std;
int main()
{
	Store xf;
	char ch;
	while(true){
		xf.start();
		cout<<"start again?(Yes/No) ";
		cin>>ch;
		if (ch=='Y' || ch=='y')
			continue;
		else
			break;
	}
}
