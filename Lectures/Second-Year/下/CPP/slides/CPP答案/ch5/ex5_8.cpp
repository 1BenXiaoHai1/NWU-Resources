/*
 * ex5_8.cpp
 *
 *  8. ��д����hello���������������һ������������ʾ�ʺ��
 *  ���磺���������룺hello Ron
 *  �����Ϊ��Hello Ron!
 *  ������룺hello Harry Ron Hermione
 *  �������Hello Harry��
 *  Hello Ron��
 *  Hello Hermione��
 *  ��ʾ��ʹ�ô�������main()����ʵ�֡�
 *
 */


#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	if(argc <=1)
	{
		cout<<"wrong argument number"<<endl;
		exit(1);
	}
	int n = 1;
	while(n < argc){
		cout<<"Hello,"<<argv[n]<<"!"<<endl;
		n++;
	}
}
