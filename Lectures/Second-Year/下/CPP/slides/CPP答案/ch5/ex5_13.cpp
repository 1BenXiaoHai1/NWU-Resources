/*
 * ex5_13.cpp
 *
 *  13. 编写函数，检测字符串是否是有效密码。
 *  假定有效密码规则为：密码必须至少8位字符；密码仅包含字母和数字；密码必须包含至少两个数字；密码中的字母必须有大写和小写。
 *  编写测试程序，提示用户输入要检测的密码，如果符合规则，显示“有效密码”，否则显示“无效密码”。
 *
 */


#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool validate(const string& pswd){

	//必须至少8位字符
	if (pswd.size() < 8)
		return false;

	//仅包含字母和数字
	bool hasOther = false;
	for(auto e : pswd)
		if(!isalnum(e)){
			hasOther = true;
			break;
		}
	if(hasOther)
		return false;

	//字母必须有大写
	bool hasUpper = false;
	for(auto e : pswd)
		if(isupper(e)){
			hasUpper = true;
			break;
		}
	if(!hasUpper)
		return false;

	//字母必须有小写
	bool hasLower = false;
	for(auto e : pswd)
		if(islower(e)){
			hasLower = true;
			break;
		}
	if(!hasLower)
		return false;


	//必须包含至少两个数字
	int cntDigits = 0;
	for(auto e : pswd)
		if(isdigit(e))
			++cntDigits;
	if(cntDigits < 2)
		return false;

	return true;
}


int main()
{
	string p1 = "abcd12Cxy9";
	string p2 = "abcd12cxy9";
	string p3 = "abcdEFCxy";
	string p4 = "abDE123";
	string p5 = "abcd$12CX9";
	string p6 = "1AbcD2ccoo";

	cout << boolalpha;
	cout << p1 << " : " << validate(p1) << endl;
	cout << p2 << " : " << validate(p2) << endl;
	cout << p3 << " : " << validate(p3) << endl;
	cout << p4 << " : " << validate(p4) << endl;
	cout << p5 << " : " << validate(p5) << endl;
	cout << p5 << " : " << validate(p6) << endl;

	return 0;
}

