/*
 * ex4_4.cpp
 *
 * 4. 8��64��256����2�Ľ״η�������64��2��6�η����������ַ�����д�����ж�һ�������ǲ���2�Ľ״η�������˵�����ַ������á�
 *
 */
#include <iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Please input a number:"<<endl;
	cin >> num;
	//algorithm 1
	int i = num;
	do{
		if(i%2==0)
			i /= 2;
		else
			break;
	}while(i);
	if (i==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;

	//algorithm 2
	i=num;
	while(i){
		if(!(i&1))
			i>>=1;
		else
			break;
	}
	if (i==1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}


