/*
 * ex4_12.cpp
 *
 * 12. 编写程序，提示用户输入两个字符串，检测第二个字符串是否是第一个字符串的子串。
 *
 *
 */
#include<string>
#include<iostream>
using namespace std;

int main()
{
	string s1, s2;
	cout << "Enter string 1: " << endl;
	getline(cin, s1);
	cout << "Enter string 2: " << endl;
	getline(cin, s2);

	//approach 1: use member function of string class

	auto pos = s1.find(s2);

	if(pos != string::npos)
		cout << s2 << " is substring of " << s1 << endl;
	else
		cout << s2 << " is not substring of " << s1 << endl;


	//approach 2:

	int loc = -1;
	auto beg = s1.begin();
	while(beg != s1.end()){
		if((s1.end() - beg) < (s2.end() - s2.begin()))
			break;

		bool flag = true;
		for(auto it2 = s2.begin(), it1 = beg; it2 != s2.end(); ++it2, ++it1){
			if(*it2 != *it1){
				flag = false;
				break;
			}
		}

		if(flag){
			loc = beg - s1.begin();
			break;
		}
		else
			++beg;
	}

	if(loc != -1)
		cout << s2 << " is substring of " << s1 << endl;
	else
		cout << s2 << " is not substring of " << s1 << endl;

	return 0;
}



