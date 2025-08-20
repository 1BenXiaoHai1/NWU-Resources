/*
 * ex12_1.cpp
 *
 *  1. 将一组整数存放到list 中并对其按升序排序。
 */

#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main(){
	list<int> ls;
	cout << "Enter integers (end with 0): " << endl;

	while(true){
		int number;
		cin >> number;
		if(number == 0)
			break;
		auto it = ls.begin();
		while(it != ls.end()){
			if(number > *it)
				++it;
			else
				break;
		}

		ls.insert(it, number);
	}

	cout<<"List:"<<endl;
	for(auto n : ls)
			cout << n << " ";
	return 0;
}


