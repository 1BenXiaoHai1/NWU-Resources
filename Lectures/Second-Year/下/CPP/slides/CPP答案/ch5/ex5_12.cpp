/*
 * ex5_12.cpp
 *
 *  12. 编写函数，将数值字符串转换为整数。例如：atoi("234")，转换结果为234。
 *  函数原型为：int atoi(const char*);
 *
 */


#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
int atoi2(const char* num)
{
	istringstream is(num);
	int number;
	is>>number;
	return number;
}
int atoi(const char* num)
{
	int value=0,sign=1;
	int len = strlen(num);
	int pos = 0;
	if(num[0]=='-')
	{
		sign = -1;
		pos++;
	}
	for(int i=pos; i<len; ++i)
	{
		if(num[i]>='0'&&num[i]<='9'){
			value = value*10 + num[i]-'0';
			continue;
		}
		else
			break;
	}
	return value*sign;
}

int main()
{
	cout<<"Please input a string:"<<endl;
	char num[20];
	cin>>num;
	cout<<atoi2(num)<<endl;

	cout<<atoi(num)<<endl;

}
