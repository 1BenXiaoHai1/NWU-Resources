/*
 * ex13_8.cpp
 *
 *    8. ��дһ���������ڳ���������ֻ�ܱ��������Σ�������׳��쳣��
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
