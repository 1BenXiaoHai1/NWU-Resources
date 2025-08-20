/*
 * ex13_8.cpp
 *
 *    8. 编写一个函数，在程序中至多只能被调用三次，否则会抛出异常。
 */
#include <iostream>
using namespace std;
class Error{
public:
	Error(int c):count(c){}
	void message(){
		cout<<"The function is called "<<count<<" times!"<<endl;
	}
private:
	int count;
};
bool validate(int value)
{
	int static count = 0;
	if(count>=3)
		throw Error(count);
	count++;
	if(value > 0)
		return true;
	else
		return false;
}

int main()
try{
	int num;
	while(true){
		cout<<"Please input a number:";
		cin>>num;
		cout<<"validate:"<<validate(num)<<endl;
	}
}
catch(Error e){
	e.message();
}
