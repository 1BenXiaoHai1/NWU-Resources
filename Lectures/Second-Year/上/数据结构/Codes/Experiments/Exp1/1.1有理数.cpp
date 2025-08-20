#include<iostream>

using namespace std;

class Rational_Num {
		int Numerator;
		int Denominator;
	public:
		//默认构造函数
		Rational_Num(): Numerator(0), Denominator(1) {}
		//构造函数
		Rational_Num(int Numerator, int Denominator) {
			this->Numerator = Numerator;
			//分母不能为零
			if (Denominator != 0) {
				this->Denominator = Denominator;
			} else {
				cout << "Invalid Input.分母不能为0" << endl;
				cout << "请重新输入分母:";
				cin >> this->Denominator;
			}
		}
		Rational_Num(const Rational_Num & Num): Numerator(Num.Numerator), Denominator(Num.Denominator) {}
		~Rational_Num() {
		}
		void setNumerator(int Numerator) {
			this->Numerator = Numerator;
		}
		void setDenominator(int Denominator) {
			if (Denominator != 0) {
				this->Denominator = Denominator;
			} else {
				cout << "Invalid Input.分母不能为0" << endl;
			}
		}
		int getNumerator() {
			return Numerator;
		}
		int getDenominator() {
			return Denominator;
		}
		//运算符重载技术（非成员函数）——双目运算符要给出两个运算数
		//有理数加法
		friend Rational_Num operator + (Rational_Num left, Rational_Num right) {
			int a = left.Numerator;
			int b = left.Denominator;
			int c = right.Numerator;
			int d = right.Denominator;
			//分数统一
			int num = a * d + b * c;//求和后的分子
			int den = b * d;//分母
			//化简
			Rational_Num Res(num, den);
			Res.Fraction();//化简结果
			return Res;
		}
		friend Rational_Num operator - (Rational_Num left, Rational_Num right) {
			//减法转加法
			//右操作数转相反数
			right.Denominator = -right.Denominator;//分母取反
			return Rational_Num(left + right);
		}
		friend Rational_Num operator * (Rational_Num left, Rational_Num right) {
			Rational_Num Res(left.Numerator * right.Numerator, left.Denominator * right.Denominator);
			Res.Fraction();//化简结果
			return Res;
		}
		friend Rational_Num operator / (Rational_Num left, Rational_Num right) {
			//除法转乘法
			//被除数颠倒
			int temp = right.Numerator;
			right.Numerator = right.Denominator;//分母翻到上面
			right.Denominator = temp;
			return Rational_Num(left * right);
		}
		Rational_Num& operator = (Rational_Num num) {
			//自赋值检测
			if (this == &num) {
				return *this;
			}
			Numerator = num.Numerator;
			Denominator = num.Denominator;
			return *this;
		}
		//分数化简——辗转相除法
		void Fraction() {
			int a = Numerator;
			int b = Denominator;
			int temp;
			while (a % b != 0) {
				temp = a % b;
				a = b;
				b = temp;
			}
			Numerator = Numerator / b;
			Denominator = Denominator / b;
		}
};

void Menu() {
	cout << "-------1.有理数加法-------" << endl;
	cout << "-------2.有理数减法-------" << endl;
	cout << "-------3.有理数乘法-------" << endl;
	cout << "-------4.有理数除法-------" << endl;
}


int main() {
	Rational_Num Res;
	cout << "-------有理数运算程序------" << endl;
	cout << "输入两个有理数" << endl;
	cout << "请输入第一个有理数的分子和分母:";
	int num1_Num, num1_Den;
	cin >> num1_Num >> num1_Den;
	Rational_Num num1(num1_Num, num1_Den);
	cout << "请输入第二个有理数的分子和分母:";
	int num2_Num, num2_Den;
	cin >> num2_Num >> num2_Den;
	Rational_Num num2(num2_Num, num2_Den);
loop:
	Menu();
	int flag = -1;
	cin >> flag;
	switch (flag) {
		case 1:
			Res = num1 + num2;
			cout << "加法运算结果为" << Res.getNumerator() << "/" << Res.getDenominator();
			break;
		case 2:
			Res = num1 - num2;
			cout << "减法运算结果为" << Res.getNumerator() << "/" << Res.getDenominator();
			break;
		case 3:
			Res = num1 * num2;
			cout << "乘法运算结果为" << Res.getNumerator() << "/" << Res.getDenominator();
			break;
		case 4:
			Res = num1 / num2;
			cout << "除法运算结果为" << Res.getNumerator() << "/" << Res.getDenominator();
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			goto loop;
			break;
	}

	return 0;
}
