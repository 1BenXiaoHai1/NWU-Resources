/*
 * ex4_15.cpp
 *
 * 15. ��д������ʾ�û�����һ���ַ�������ʾ���ַ����д�д��ĸ����Ŀ��
 *
 *
 */
#include<string>
#include<cctype>
#include<iostream>
using namespace std;

int main()
{
	cout << "Enter a string: " << endl;
	string str;
	getline(cin, str);

	int cnt = 0;
	for(auto e : str)
		if(isupper(e))
			++cnt;

	cout << "Capital letters in string: " << cnt << endl;
	return 0;
}



