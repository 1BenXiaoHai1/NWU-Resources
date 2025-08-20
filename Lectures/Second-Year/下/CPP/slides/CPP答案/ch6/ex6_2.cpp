/*
 * ex6_2.cpp
 *
 * 2. 设计表示时间的Time类，要求：
 * （1）有表示时、分、秒的数据成员；
 * （2）正确的初始化操作，检验数据的合法性；
 * （3）有时、分、秒的get和set函数；
 * （4）以24小时格式或12小时加上午下午的格式输出当前时间。
 *
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

//class declaration
class Time{
	int hour = 0;
	int minute = 0;
	int second = 0;
public:
	Time();
	Time(int h, int m, int s);

	//getter and setter
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	//display
	string toString24()const;
	string toString12()const;

	void display24()const;
	void display12()const;
};
//member functions definition
Time::Time() : hour(0), minute(0), second(0)
{}
Time::Time(int h, int m, int s) : Time(){
	if(h >= 0 && h < 24)
		hour = h;
	if(m >= 0 && m < 60)
		minute = m;
	if(s >= 0 && s < 60)
		second = s;
}

//getter and setter
int Time::getHour() const{
	return hour;
}
int Time::getMinute() const{
	return minute;
}
int Time::getSecond() const{
	return second;
}
void Time::setHour(int h){
	if(h >= 0 && h < 24)
		hour = h;
}
void Time::setMinute(int m){
	if(m >= 0 && m < 60)
		minute = m;
}
void Time::setSecond(int s){
	if(s >= 0 && s < 60)
		second = s;
}
//display
string Time::toString24()const{
	ostringstream os;
	os << hour << ":" << minute << ":" << second;
	return os.str();
}
string Time::toString12()const{
	ostringstream os;

	if(hour > 0 && hour < 12)
		os << hour << ":" << minute << ":" << second << " A.M.";
	else if(hour == 0)
		os << (hour + 12) << ":" << minute << ":" << second << " A.M.";
	else if(hour == 12)
		os << hour << ":" << minute << ":" << second << " P.M.";
	else
		os << (hour - 12) << ":" << minute << ":" << second << " P.M.";

	return os.str();
}

void Time::display24()const{
	cout << toString24();
}
void Time::display12()const{
	cout << toString12();
}


int main()
{
	Time t1(23, 15, 35);
	Time t2(12, 35, 7);
	Time t3(0, 23, 19);
	Time t4;

	cout << t1.toString12() << "\t" << t1.toString24() << endl;
	cout << t2.toString12() << "\t" << t2.toString24() << endl;
	cout << t3.toString12() << "\t" << t3.toString24() << endl;
	cout << t4.toString12() << "\t" << t4.toString24() << endl;

	return 0;
}




