/*
 * ex13_3.cpp
 *
 *  3. 编写一个异常类，用于学生类，目的是控制学生的年龄不能小于15 岁或大于60 岁。
 */

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <exception>
using namespace std;

class age_error : exception{
public:
	age_error(int age){
		ostringstream os;
		os << message << " Invalid Age: " << age << "\n";
		message = os.str();
	}
	const char* what()const noexcept override{
		return message.c_str();
	}

private:
	string message = "Age out of range 15~60.";
};

class student{
	unsigned id;
	string name;
	int age;
public:
	student(unsigned sid, string snm, int sage): id(sid), name(snm){
		if(sage < 15 || sage > 60)
			throw age_error(sage);

		age = sage;
	}

	~student() = default;

	void print()const{
		cout << "Id: " << id << " Name: " << name << " Age: " << age << endl;
	}
};

int main(){
	try{
		student s1(123, "Lily", 28);
		student s2(125, "Harry", 10);
		student s3(128, "Ron", 10);

	}
	catch(age_error& e){
		cout << e.what() << endl;
		exit(1);
	}

	return 0;
}

