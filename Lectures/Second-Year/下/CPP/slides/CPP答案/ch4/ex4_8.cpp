/*
 * ex4_8.cpp
 *
 * 8. ��д���򣬱Ƚ�����string���͵��ַ�����Ȼ���д��һ������Ƚ�����C����ַ�����
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
	cout<<"����C ����ַ��� �����?\t"<<boolalpha<<equal<<endl;

	//C++ string
	string string1,string2;
	cout<<"Please input C++ string 1:"<<endl;
	cin>>string1;
	cout<<"Please input C++ string 2:"<<endl;
	cin>>string2;
	cout<<"����string �����?\t"<<boolalpha<<(string1==string2)<<endl;

}




