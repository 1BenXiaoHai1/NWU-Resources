/*
 * ex6_4.cpp
 *
 * 4.���һ����ΪFan�����ʾ���ȣ�Ҫ�������
 ��1��3����ΪSLOW��MEDIUM��FAST�ĳ�����ֵ�ֱ�Ϊ1��2��3����ʾ���٣�
 ��2��int���͵�˽�����ݳ�Աspeed����ʾ���ȵ��ٶȣ�Ĭ��ֵΪSLOW��
 ��3��bool���͵�˽�����ݳ�Աon����ʾ�����Ƿ�򿪣�Ĭ��ֵΪfalse��
 ��4��double���͵�˽�����ݳ�Աradius����ʾ���ȵİ뾶�������󲻿��޸ģ�Ĭ��ֵ5��
 ��5��string���͵�˽�����ݳ�Աcolor����ʾ���ȵ���ɫ��Ĭ��ֵΪwhite��
 ��6��4�����ݳ�Ա�ķ���������const��Ա���޸�����
 ��7������Ĭ�Ϸ��ȵĹ��캯����
 ��8�����ݲ���ֵ�������ȵĹ��캯����
 ��9����Ա����status()�����ط��ȵ�״̬�ַ�����
 ��������Ǵ򿪵ģ��ַ����а������ȵ��ٶȡ���ɫ�Ͱ뾶�����򣬷��ص��ַ����а������ȹرա���ɫ�Ͱ뾶��
 ��д���Գ��򣬴���������ͬ��ɫ�ʹ�С�ķ��ȣ����иı��ٶȡ������صȲ����������Щ���ȵ�״̬��
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




