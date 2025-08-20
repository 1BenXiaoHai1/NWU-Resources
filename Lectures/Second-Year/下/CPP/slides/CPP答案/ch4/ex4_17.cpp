/*
 * ex4_17.cpp
 * 17. 读入一个浮点数文件float.dat，依次用其中的每对浮点数构造一个复数，并输出这些复数。
 *
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void createFile(string filename)
{
	ofstream out(filename.c_str());
	double d;
	while(cin>>d)
		out<<d<<"\t";
	out.close();
}
string formatComplex(double real, double imaginary){
	ostringstream os;
	if(real==0 && imaginary==0)	{
		os << "0";
	}
	if(real!=0)	{
		os << real;
	}
	if(imaginary!=0) {
		if(imaginary>0 && real!=0)
			os << "+";
		os << imaginary << "i" ;
	}
	return os.str();
}

int main(){
//	createFile("float.dat");
	ifstream data("float.dat");
	double r,i;
	while(data>>r>>i){
		cout<<formatComplex(r,i)<<endl;
	}
}


