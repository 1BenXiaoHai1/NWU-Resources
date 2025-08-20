#include<string>
#include<iostream>
using namespace std;

//µÝ¹é
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

//·ÇµÝ¹é
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
	
	cout << 13 << " -> " << dec2Bin(13) << endl;
	cout << 13 << " -> " << dec2BinR(13) << endl;
	
	return 0;
}

