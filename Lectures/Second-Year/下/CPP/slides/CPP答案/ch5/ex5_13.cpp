/*
 * ex5_13.cpp
 *
 *  13. ��д����������ַ����Ƿ�����Ч���롣
 *  �ٶ���Ч�������Ϊ�������������8λ�ַ��������������ĸ�����֣����������������������֣������е���ĸ�����д�д��Сд��
 *  ��д���Գ�����ʾ�û�����Ҫ�������룬������Ϲ�����ʾ����Ч���롱��������ʾ����Ч���롱��
 *
 */


#include <string>
#include <cctype>
#include <iostream>
using namespace std;

bool validate(const string& pswd){

	//��������8λ�ַ�
	if (pswd.size() < 8)
		return false;

	//��������ĸ������
	bool hasOther = false;
	for(auto e : pswd)
		if(!isalnum(e)){
			hasOther = true;
			break;
		}
	if(hasOther)
		return false;

	//��ĸ�����д�д
	bool hasUpper = false;
	for(auto e : pswd)
		if(isupper(e)){
			hasUpper = true;
			break;
		}
	if(!hasUpper)
		return false;

	//��ĸ������Сд
	bool hasLower = false;
	for(auto e : pswd)
		if(islower(e)){
			hasLower = true;
			break;
		}
	if(!hasLower)
		return false;


	//�������������������
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

