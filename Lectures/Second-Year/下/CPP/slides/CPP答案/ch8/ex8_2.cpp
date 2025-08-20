/*
 * ex8_2.cpp
 *
 *  2．为第6 章习题中的复数类ComplexNumber 定义运算符函数，
 *  使得ComplexNumber的对象看起来可以像基本数据类型一样进行算术运算。
 *
 *
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class ComplexNumber{
public:
	ComplexNumber(double r = 0, double i = 0): real(r), imag(i){}

	double getImaginary() const;
	double getReal() const;

	ComplexNumber operator+(const ComplexNumber& c)const;
	ComplexNumber operator-(const ComplexNumber& c)const;
	ComplexNumber operator*(const ComplexNumber& c)const;
	ComplexNumber operator/(const ComplexNumber& c)const;

	friend ostream& operator<<(ostream& os, const ComplexNumber& c);
	friend istream& operator>>(istream& is, ComplexNumber& c);

private:
	double real = 0;
	double imag = 0;

	string toString()const;
};

double ComplexNumber::getImaginary() const {
	return imag;
}

double ComplexNumber::getReal() const {
	return real;
}

string ComplexNumber::toString() const {
	ostringstream os;
	if(real == 0){
		if(imag == 0)
			os << 0;
		else
			os << imag << "i";
	}
	else{
		if(imag == 0)
			os << real;
		else if(imag  > 0)
			os << real << "+" << imag << "i";
		else
			os << real << imag << "i";
	}

	return os.str();
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& c) const {
	return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& c) const {
	return ComplexNumber(real - c.real, imag - c.imag);
}
//(a+bi) * (c+di) = (ac-bd) + (bc + ad)i
//(a+bi) / (c+di) = (ac+bd)/(c2+d2) + (bc-ad)i/(c2+d2)
ComplexNumber ComplexNumber::operator*(const ComplexNumber& c) const {
	ComplexNumber cn;
	cn.real = real * c.real - imag * c.imag;
	cn.imag = imag * c.real + real * c.imag;
	return cn;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& c) const {
	ComplexNumber cn;

	double cds = c.real * c.real + c.imag * c.imag;

	cn.real = (real * c.real + imag * c.imag) / cds;
	cn.imag = (imag * c.real - real * c.imag) / cds;

	return cn;
}

ostream& operator<<(ostream& os, const ComplexNumber& c){

	os << c.toString();

	return os;

}
istream& operator>>(istream& is, ComplexNumber& c){
	is >> c.real >> c.imag;
	return is;
}

//------------------------------

int main()
{
	ComplexNumber c1(1, 2), c2(3, 4), c3(-3, 2), c4(2, -4), c5(-1, -2), c6;

	cout <<"c1: " << c1 << endl;
	cout <<"c2: " << c2 << endl;
	cout <<"c3: " << c3 << endl;
	cout <<"c4: " << c4 << endl;
	cout <<"c5: " << c5 << endl;
	cout <<"c6: " << c6 << endl;

	cout <<"c1 + c2 = " << c1 + c2 << endl;
	cout <<"c3 + c2 = " << c3 + c2 << endl;
	cout <<"c4 + c2 = " << c4 + c2 << endl;

	cout <<"c1 - c2 = " << c1 - c2 << endl;
	cout <<"c1 * c2 = " << c1 * c2 << endl;
	cout <<"c1 / c2 = " << c1 / c2 << endl;

	cout << "Enter a complex number: (real imaginary): " ;
	cin >> c6;
	cout << c6 << endl;
	return 0;
}





