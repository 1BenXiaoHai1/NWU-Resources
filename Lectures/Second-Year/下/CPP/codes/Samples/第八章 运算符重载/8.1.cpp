//一元运算符的重载
#include<iostream>

using namespace std;

class Byte {
	unsigned char b;
public:
	Byte(unsigned char bb=0):b(bb){}
	
	const Byte& operator+() const{//正号返回当前对象本身
		return *this;
	}
	const Byte operator-() const{//负号返回当前对象的相反数
		return Byte(-b);
	}
	const Byte operator~() const{//按位取反
		return Byte(~b);
	}
	
	bool Byte operator!() const{//非运算符
		return !b;
	}
	//有副作用的运算符定义为非const成员函数
	const Byte operator++(){//前缀++ —— 先自增，再返回
		b++;
		return *this;
	}
	const Byte operator++(int){//后缀++ —— 后自增，再返回——区分前后缀 在括号内加int区分前缀和后缀运算
		Byte before(b);//直接初始化
		b++;
		return before;
	}
	const Byte& operator--(){//前缀--
		--b;
		return *this;
	}
	const Byte operator--(int){//后缀--
		Byte before(b);
		--b;
		return before;
	}
	
};

int main()
{
	Byte b;
	+b;
	-b;
	~b;
	!b;
	++b;
	b++;
	--b;
	b--;
}
