/*
 * ex6_3.cpp
 *
 * 3. 设计一个Account类：
 * （1）static数据成员annual表示每个存款人的年利率；
 * （2）private数据成员savings表示当前存款额；
 * （3）成员函数calculate()用于计算月利息，并将利息加进savings；
 * （4）static成员函数modify()改变annual；
 * 在主程序中实例化两个不同的Account对象saver1和saver2，
 * 账户余额分别为2000.00和3000.00，将annual设置为3%，
 * 计算每个存款人的月息并打印结果，再将annual设置为4%，
 * 重新计算每个存款人的月息并打印新的结果。
 *
 *
 */
#include<iostream>
using namespace std;
class Account{
public:
	Account(double s):savings(s){}
	static void modify(double newAnnual){
		annual += newAnnual;
	}
	double caculate(){
		double interest = savings*annual/12;
		savings+=  interest;
		return interest;
	}
	double getSavings(){return savings;}
private:
	double savings;
	static double annual;
};
double Account::annual = 0.03;

int main()
{
	Account saver1(2000),saver2(3000);
	cout<<saver1.getSavings()<<"\t"<<saver1.caculate()<<endl;
	cout<<saver2.getSavings()<<"\t"<<saver2.caculate()<<endl;
	Account::modify(0.04);
	cout<<saver1.getSavings()<<"\t"<<saver1.caculate()<<endl;
	cout<<saver2.getSavings()<<"\t"<<saver2.caculate()<<endl;
}


