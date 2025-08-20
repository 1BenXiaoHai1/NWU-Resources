/*
 * ex5_10.cpp
 *
 *  10. ��д������������������ַ��������õݹ�ͷǵݹ����ַ���ʵ�֡�
 *
 */

#include <iostream>
#include <string>
using namespace std;
string reverse(const string& str)
{
	string rs;
	auto it = str.rbegin();
	while(it != str.rend())
		rs.push_back(*it++);

	return rs;
}

string reverseR(const string& s)
{
	string rs;
	if(!s.empty()){
		string st(s.begin()+1, s.end());
		rs = reverseR(st);
		rs.push_back(s[0]);
	}
	return rs;
}


int main()
{
	string str;
	cout << "Enter a string: " << endl;
	getline(cin, str);

	cout << reverseR(str) << endl;

	cout<<str<<endl;
	cout << reverse(str) << endl;
}

