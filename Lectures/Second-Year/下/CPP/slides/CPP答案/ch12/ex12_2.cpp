/*
 * ex12_2.cpp
 *
 *  2. 使用迭代器编写程序，从标准输入设备读入若干string 对象，
 *  并将它们存储在一个vector 容器中，
 *  然后逆序输出vector 中所有的元素。
 */

#include<iterator>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string line;
	vector<string> vs;
	cout<<"Enter 10 strings: " << endl;
	for(int i = 0; i < 10; ++i){
		getline(cin, line);
		vs.push_back(line);
	}

	auto rit = vs.rbegin();
	while(rit != vs.rend()){
		cout << *rit << endl;
		++rit;
	}

	return 0;
}


