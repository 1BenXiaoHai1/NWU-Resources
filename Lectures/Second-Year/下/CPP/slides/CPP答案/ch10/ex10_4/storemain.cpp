/*
 * storemain.cpp
 *
 * 4�����С��������������汾���������汾Ҫ��
��1���ڵڶ����汾�Ļ��������ӽ��ڻ�����ImportedGoods��Ҫ���ڽ��ڻ��������
��ӡ�<I>������۸��ڻ�������۸�Ļ���������20����
��2����ʽ���۸����������ٱ�����λС����

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
