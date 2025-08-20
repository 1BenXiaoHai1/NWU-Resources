/*
 * ex4_15.cpp
 *
 * 15. 编写程序，提示用户输入一个字符串，显示该字符串中大写字母的数目。
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



