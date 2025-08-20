/*
 * ex13_1.cpp
 *
 *  1. 编写一个抛出除数为零异常的程序，捕获并处理该异常。
 */

#include<stdexcept>
#include<iostream>
using namespace std;

int div(int n, int m){
	if(m == 0)
		throw runtime_error("Divide by zero!");

	return n/m;
}
int main(){

	try{

		cout << div(3, 2)<< endl;
		cout << div(2, 0) << endl;
		cout << div(6, 2) << endl;
	}
	catch(runtime_error e){
		cout<<e.what()<<endl;
		return 1;
	}
	return 0;
}




