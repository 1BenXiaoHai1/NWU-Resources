/*
 * ex6_4.cpp
 *
 * 4.设计一个名为Fan的类表示风扇，要求包括：
 （1）3个名为SLOW、MEDIUM和FAST的常量，值分别为1、2、3，表示风速；
 （2）int类型的私有数据成员speed，表示风扇的速度，默认值为SLOW；
 （3）bool类型的私有数据成员on，表示风扇是否打开，默认值为false；
 （4）double类型的私有数据成员radius，表示风扇的半径，创建后不可修改，默认值5；
 （5）string类型的私有数据成员color，表示风扇的颜色，默认值为white；
 （6）4个数据成员的访问器，非const成员的修改器；
 （7）创建默认风扇的构造函数；
 （8）根据参数值创建风扇的构造函数；
 （9）成员函数status()，返回风扇的状态字符串：
 如果风扇是打开的，字符串中包括风扇的速度、颜色和半径；否则，返回的字符串中包括风扇关闭、颜色和半径。
 编写测试程序，创建三个不同颜色和大小的风扇，进行改变速度、开、关等操作，输出这些风扇的状态。
 *
 */

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Fan{
public:
	Fan();
	Fan(string color, double radius);

	const string& getColor() const;
	void setColor(const string& color = "white");

	bool isOn() const;
	void turnOn();
	void turnOff();

	double getRadius() const;

	int getSpeed() const;
	void setSpeed(int speed = SLOW);

	string status()const;


	static const int SLOW = 1;
	static const int MIDUM = 2;
	static const int FAST = 3;

private:
	int speed = SLOW;
	bool on = false;
	string color = "white";
	const double radius = 5;
};	//end of class definition
//--------------------------------------

Fan::Fan(){}
Fan::Fan(string c, double r) : color(c), radius(r){}

const string& Fan::getColor() const {
	return color;
}

void Fan::setColor(const string& color) {
	this->color = color;
}

bool Fan::isOn() const {
	return on;
}

void Fan::turnOn() {
	on = true;
}
void Fan::turnOff(){
	on = false;
}

double Fan::getRadius() const {
	return radius;
}

int Fan::getSpeed() const {
	return speed;
}

void Fan::setSpeed(int speed) {
	this->speed = speed;
}

string Fan::status()const{

	ostringstream os;

	if(isOn())
		os << "Fan status: " << speed << " " << color << " " << radius;
	else
		os << "Fan is OFF: " << color << " " << radius;

	return os.str();

}

//--------------------------------------
int main()
{
	Fan fan1;
	cout << "fan 1:" << endl;
	cout << fan1.status() << endl;
	fan1.turnOn();
	fan1.setSpeed(Fan::FAST);
	cout << fan1.status() << endl;

	Fan fan2("blue", 8);
	cout << "fan 2:" << endl;
	cout << fan2.status() << endl;
	fan2.turnOn();
	cout << fan2.status() << endl;

	Fan fan3("red", 3);
	cout << "fan 3:" << endl;
	cout << fan3.status() << endl;
	fan3.turnOn();
	fan3.setColor("green");
	cout << fan3.status() << endl;
	fan3.turnOff();
	cout << fan3.status() << endl;
	return 0;
}




