/*
 * ex12_5.cpp
 *
  *      5. 编写程序，判断一个句子是否是回文。
 */
#include <string>
#include <iostream>
using namespace std;
bool palindrome(const string& str)
{
	bool pal = true;
	string::const_iterator ps = str.begin();
	string::const_reverse_iterator rs = str.rbegin();
	while(ps!=str.end() && rs!=str.rend()){
		if(*ps == *rs){
			ps++; rs++; continue;
		}
		else
		{
			pal = false;
			break;
		}
	}
	return pal;

}
int main()
{
	cout<<"please input a string:"<<endl;
	string str;
	cin>>str;
	cout<<"Is palindrome? "<<boolalpha<<palindrome(str)<<endl;
}
