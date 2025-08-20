/*
 * ex5_1.cpp
 *
 *  21. 编写函数，将字符串形式的二进制数转换为十进制数。用递归和非递归两种方法实现。
 *  函数原型：int bin2Dec(string binary);
 *
 */


#include<string>
#include<iostream>
using namespace std;

int bin2Dec(string binary){
	int dec = 0;
	for(auto d : binary)
		dec = dec * 2 + (d - '0');
	return dec;
}

int bin2DecR(string binary){
	int dec;
	if(binary.compare("0") == 0)
		dec = 0;
	else if(binary.compare("1") == 0)
		dec = 1;
	else
		if(binary.size() > 1){
			string rs(binary.begin(), binary.end()-1);
			dec = bin2DecR(rs) * 2 + (binary[binary.size()-1] - '0');
		}

	return dec;
}

int main()
{
	cout << "10101 -> " << bin2DecR("10101") << endl;
	cout << "10101 -> " << bin2Dec("10101") << endl;

	cout << "11 -> " << bin2DecR("11") << endl;
	cout << "11 -> " << bin2Dec("11") << endl;

	cout << "100 -> " << bin2DecR("100") << endl;
	cout << "100 -> " << bin2Dec("100") << endl;

	cout << "0110 -> " << bin2DecR("0110") << endl;
	cout << "0110 -> " << bin2Dec("0110") << endl;

	return 0;
}

