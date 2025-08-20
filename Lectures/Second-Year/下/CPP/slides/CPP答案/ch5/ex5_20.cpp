/*
 * ex5_20.cpp
 *
 *  20. 编写函数，将十进制数转换为二进制数的字符串。用递归和非递归两种方法实现。
 *  函数原型：string dec2Bin(int value);
 *
 */


#include<string>
#include<iostream>
using namespace std;

string dec2BinR(int value){
	string bin;
	if(value == 0)
		bin = "0";
	if(value == 1)
		bin = "1";
	if(value > 1)
		bin = dec2BinR(value / 2) + string(1, value % 2 + '0');

	return bin;

}

string dec2Bin(int value){
	string bin;
	while(value >= 1){
		bin = string(1, value % 2 + '0') + bin;
		value /= 2;
	}

	return bin;
}

int main()
{
	cout << 18 << " -> " << dec2Bin(18) << endl;
	cout << 18 << " -> " << dec2BinR(18) << endl;

	cout << 35 << " -> " << dec2Bin(35) << endl;
	cout << 35 << " -> " << dec2BinR(35) << endl;

	cout << 8 << " -> " << dec2Bin(8) << endl;
	cout << 8 << " -> " << dec2BinR(8) << endl;

	cout << 127 << " -> " << dec2Bin(127) << endl;
	cout << 127 << " -> " << dec2BinR(127) << endl;

	return 0;
}

