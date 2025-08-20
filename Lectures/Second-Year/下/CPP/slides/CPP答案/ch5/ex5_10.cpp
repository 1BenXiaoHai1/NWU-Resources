/*
 * ex5_10.cpp
 *
 *  10. 编写函数，将参数传入的字符串逆序。用递归和非递归两种方法实现。
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

