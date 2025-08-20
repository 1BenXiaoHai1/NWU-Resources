#include"Basic.h"

using namespace std;

//Date��
//Ĭ�Ϲ��캯��
Date::Date() {
	Year = 0;
	Month = 0;
	Day = 0;
}
//��ʽ����ת�����캯��
Date::Date(int _year, int _month, int _day): Year(_year), Month(_month), Day(_day) {
}
//�������캯��-ǳ����
Date::Date(const Date& a): Year(a.Year), Month(a.Month), Day(a.Day) { //��ʼ���б��ʼ��
}

//������
int Date::getYear() {
	return Year;
}
int Date::getMonth() {
	return Month;
}
int Date::getDay() {
	return Day;
}
//�޸���
void Date::setYear(int Year) {
	if (Year <= 0 || Year > 2022) {
		cout << "������������Զ�����Ĭ�ϳ�ʼ��" << endl;
		return;
	} else {
		this->Year = Year;
		cout << "����޸ĳɹ�" << endl;
		return;
	}

}
void Date::setMonth(int Month) {
	if (Month >= 1 && Month <= 12) {
		this->Month = Month;
		cout << "�·��޸ĳɹ�" << endl;
		return;
	} else {
		cout << "�·����������Զ�����Ĭ�ϳ�ʼ��" << endl;
		return;
	}
}
void Date::setDay(int Day) {
	if (Day >= 1 && Day <= 30) { //����Ĭ��ÿ���¾�Ϊ30��
		this->Day = Day;
		cout << "�����޸ĳɹ�" << endl;
		return;
	} else {
		cout << "�������������Զ�����Ĭ�ϳ�ʼ��" << endl;
		return;
	}
}
//�����ֵ�������������(��Ԫ�����) ����ֵΪDate�� Date���еĳ�Ա����
const Date operator-( Date& left, Date& right) {
	int YearGap = left.getYear() - right.getYear();
	int MonthGap, DayGap;
	if (YearGap == 0) { //�����ͬһ�꣬�·�ֱ������ͺ�
		MonthGap = left.getMonth() - right.getMonth();
	} else { //�������ͬһ�꣬�����һ��ݣ�ͬʱ����һ���
		//���������ʱ��������ȿ�ʼ��������ֱ������
		if (left.getMonth() >= right.getMonth()) {
			MonthGap = left.getMonth() - right.getMonth(); //���С
		} else {
			MonthGap = left.getMonth() + 12 - right.getMonth(); //����ݽ�һ��
			YearGap -= 1; //��ݲ��һ��
		}
	}
	//���ʼ������·�Ϊ��λ,ֻ�����ڲ�Ϊ��ֵ��ʱ��Ż�Ӱ���·ݲ�
	DayGap = left.getDay() - right.getDay();
	if (DayGap < 0) {
		MonthGap -= 1; //MonthGap��1 ��Ϊû�дﵽԭ����MonthGap
		DayGap = right.getDay() - left.getDay();
	}

	return Date(YearGap, MonthGap, DayGap);
}

//Salary��
//Ĭ�Ϲ��캯�������޲�
Salary::Salary() {
	Pay = 0;//Ĭ��Ϊ0Ԫ
}
//��ʽ����ת�����캯��
Salary::Salary(int Pay) {
	this->Pay = Pay;//��this�������ǳ�Ա����
}
//�������캯��(��Salary����г�ʼ��)
Salary::Salary(const Salary &a) {
	Pay = a.Pay;
}

//������
int Salary:: getPay() {
	return Pay;
}
//�޸���
void Salary:: setPay(int Pay) {
	if (Pay <= 200) {
		cout << "ÿ�¹��ʽ�����������Ԫ�����Զ�Ĭ��Ϊ2000Ԫÿ��" << endl;
		return;
	}
	cout << "ÿ�¹����޸ĳɹ�" << endl;
	this->Pay = Pay;
	return;
}
//���������(��Ԫ���������Ա����)
//+��������ء�������ֵΪconst Salary����
const Salary Salary::operator +(const Salary& right) const {
	return Salary(Pay + right.Pay);
}
//-���������
const Salary Salary::operator -(const Salary&right) const {
	return Salary(Pay - right.Pay);
}

