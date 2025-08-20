/*
 * ex4_8.cpp
 *
 * 8. 编写程序，比较两个string类型的字符串，然后编写另一个程序比较两个C风格字符串。
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;
const int Len = 128;
int main()
{
	//C const char*
	char str1[Len], str2[Len];
	cout<<"Please input C style string 1:"<<endl;
	cin>>str1;
	cout<<"Please input C style string 2:"<<endl;
	cin>>str2;
	bool equal = true;
	for(int i=0; str1[i]||str2[i];i++){
		if(str1[i]!=str2[i]){
			equal = false;
			break;
		}
	}
	cout<<"两个C 风格字符串 相等吗?\t"<<boolalpha<<equal<<endl;

	//C++ string
	string string1,string2;
	cout<<"Please input C++ string 1:"<<endl;
	cin>>string1;
	cout<<"Please input C++ string 2:"<<endl;
	cin>>string2;
	cout<<"两个string 相等吗?\t"<<boolalpha<<(string1==string2)<<endl;

}




