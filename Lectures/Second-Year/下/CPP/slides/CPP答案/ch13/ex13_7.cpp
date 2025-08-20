/*
 * ex13_7.cpp
 *
 *  7. 已知一个基本的C++程序：
int main(){
//使用C++标准库
}
请修改main()，以捕获C++标准库中的函数所抛出的任何异常。要求异常处理代码在
调用abort()结束main()之前打印出该异常的信息。

 */

#include<exception>
#include<stdexcept>
#include<iostream>
using namespace std;
int main(){
	try{
		//......
		// call standard library functions here...
		//test:
		//throw runtime_error("error!");
		//......

	}
	catch(exception& e){
		cout<< e.what()<<endl;
		throw;
	}

	return 0;
}


