/*
 * ex4_1.cpp
 *
 *	1. ��д������ʾ�û�����һ��ʮ����������Ȼ�������Ӧ�Ķ�����ֵ��
 *
 */

////����һ��ʹ��vector
//#include<iostream>
//#include<vector>
//using namespace std;

//int main()
//{
//	int n = 0;
//	cout << "Enter an integer in decimal: " ;
//	cin >> n;
//	vector<char> digits;
//
//	while(n != 0){
//		digits.push_back((n % 2) + '0');
//		n /= 2;
//	}
//
//	cout << "Binary: ";
//	for(auto it = digits.rbegin(); it != digits.rend(); ++it)
//		cout << *it;
//
//	return 0;
//}

//��������ʹ��string
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n = 0;
	cout << "Enter an integer in decimal: " ;
	cin >> n;
	string digits;

	while(n != 0){
		digits.push_back((n % 2) + '0');
		n /= 2;
	}

	cout << "Binary: ";
	for(auto it = digits.rbegin(); it != digits.rend(); ++it)
		cout << *it;

	return 0;
}


