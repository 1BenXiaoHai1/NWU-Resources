/*
 * ex6_3.cpp
 *
 * 3. ���һ��Account�ࣺ
 * ��1��static���ݳ�Աannual��ʾÿ������˵������ʣ�
 * ��2��private���ݳ�Աsavings��ʾ��ǰ���
 * ��3����Ա����calculate()���ڼ�������Ϣ��������Ϣ�ӽ�savings��
 * ��4��static��Ա����modify()�ı�annual��
 * ����������ʵ����������ͬ��Account����saver1��saver2��
 * �˻����ֱ�Ϊ2000.00��3000.00����annual����Ϊ3%��
 * ����ÿ������˵���Ϣ����ӡ������ٽ�annual����Ϊ4%��
 * ���¼���ÿ������˵���Ϣ����ӡ�µĽ����
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


