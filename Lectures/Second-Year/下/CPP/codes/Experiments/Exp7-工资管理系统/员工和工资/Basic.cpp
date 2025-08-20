#include"Basic.h"

using namespace std;

//Date类
//默认构造函数
Date::Date() {
	Year = 0;
	Month = 0;
	Day = 0;
}
//隐式类型转换构造函数
Date::Date(int _year, int _month, int _day): Year(_year), Month(_month), Day(_day) {
}
//拷贝构造函数-浅拷贝
Date::Date(const Date& a): Year(a.Year), Month(a.Month), Day(a.Day) { //初始化列表初始化
}

//访问器
int Date::getYear() {
	return Year;
}
int Date::getMonth() {
	return Month;
}
int Date::getDay() {
	return Day;
}
//修改器
void Date::setYear(int Year) {
	if (Year <= 0 || Year > 2022) {
		cout << "年份输入有误，自动进行默认初始化" << endl;
		return;
	} else {
		this->Year = Year;
		cout << "年份修改成功" << endl;
		return;
	}

}
void Date::setMonth(int Month) {
	if (Month >= 1 && Month <= 12) {
		this->Month = Month;
		cout << "月份修改成功" << endl;
		return;
	} else {
		cout << "月份输入有误，自动进行默认初始化" << endl;
		return;
	}
}
void Date::setDay(int Day) {
	if (Day >= 1 && Day <= 30) { //这里默认每个月均为30天
		this->Day = Day;
		cout << "日期修改成功" << endl;
		return;
	} else {
		cout << "日期输入有误，自动进行默认初始化" << endl;
		return;
	}
}
//计算差值——运算符重载(二元运算符) 返回值为Date类 Date类中的成员函数
const Date operator-( Date& left, Date& right) {
	int YearGap = left.getYear() - right.getYear();
	int MonthGap, DayGap;
	if (YearGap == 0) { //如果在同一年，月份直接作差就好
		MonthGap = left.getMonth() - right.getMonth();
	} else { //如果不在同一年，需向借一年份，同时减少一年份
		//如果最后结束时间的月数比开始工作的晚，直接作差
		if (left.getMonth() >= right.getMonth()) {
			MonthGap = left.getMonth() - right.getMonth(); //大减小
		} else {
			MonthGap = left.getMonth() + 12 - right.getMonth(); //从年份借一年
			YearGap -= 1; //年份差减一年
		}
	}
	//工资计算以月份为单位,只有日期差为负值的时候才会影响月份差
	DayGap = left.getDay() - right.getDay();
	if (DayGap < 0) {
		MonthGap -= 1; //MonthGap减1 因为没有达到原来的MonthGap
		DayGap = right.getDay() - left.getDay();
	}

	return Date(YearGap, MonthGap, DayGap);
}

//Salary类
//默认构造函数——无参
Salary::Salary() {
	Pay = 0;//默认为0元
}
//隐式类型转换构造函数
Salary::Salary(int Pay) {
	this->Pay = Pay;//用this来区分是成员变量
}
//拷贝构造函数(用Salary类进行初始化)
Salary::Salary(const Salary &a) {
	Pay = a.Pay;
}

//访问器
int Salary:: getPay() {
	return Pay;
}
//修改器
void Salary:: setPay(int Pay) {
	if (Pay <= 200) {
		cout << "每月工资金额不得少于两百元，已自动默认为2000元每月" << endl;
		return;
	}
	cout << "每月工资修改成功" << endl;
	this->Pay = Pay;
	return;
}
//运算符重载(二元运算符、成员函数)
//+运算符重载——返回值为const Salary类型
const Salary Salary::operator +(const Salary& right) const {
	return Salary(Pay + right.Pay);
}
//-运算符重载
const Salary Salary::operator -(const Salary&right) const {
	return Salary(Pay - right.Pay);
}

