/*
 * ex5_9.cpp
 *
 *  9. ��ʹ�ÿ⺯������д�ַ����ȽϺ������ַ�����ȷ���0������ȷ���-1��
 *  ����ԭ��Ϊ��int strcmp(char *source,char *dest);
 *
 */


#include <iostream>
using namespace std;

int strcmp(char* source, char* dest)
{
	while(*source && *dest){
		if(*source++ != *dest++)
			return -1;
	}
	if(*source != *dest)
		return  -1;
	else
		return 0;
}
int main()
{
	char str1[1024], str2[1024];
	cout<<"Please input string 1:"<<endl;
	cin>>str1;
	cout<<"Please input string 2:"<<endl;
	cin>>str2;
	cout<<strcmp(str1, str2)<<endl;
}
