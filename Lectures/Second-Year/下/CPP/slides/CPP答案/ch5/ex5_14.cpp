/*
 * ex5_14.cpp
 *
 *  14. ��д�����������������һ��������ֵת��Ϊ���Ľ��Ĵ�д��ʽ��ת�������Ϊ�ַ������ء�
 *  �������Ϊ����ʱ��ֻ��ʾ�������֣�ʡ��С�����֣������"��"�֡�
 *  ��������к���������0ʱ��ֻ��Ҫһ��"��"���ɡ�
 *  ��ע��10�ı�ʾ������110��Ҽ��ҼʰԪ����10��ҼʰԪ����
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string CH[] = {"","Ҽ","��","��","��","��","½","��","��","��"};
string Unit[] = {"Ԫ","ʰ","��","Ǫ","��",
		"ʰ","��","Ǫ","��",
		"ʰ","��","Ǫ","��","��"};
string jiao = "��";
string fen = "��";
string zheng = "��";
string zero = "��";
string yuan = "Ԫ";
string wanyuan = "��";
string yiyuan = "��";
const string transformCH(double money){
	ostringstream os;
	os<<money;
	istringstream is;
	is.str(os.str());

	int integeral,decimal;
	char dc1,dc2;
	char point;

	is>>integeral;
	is.get(point);
	if(point =='.'){
		is.get(dc1);
		is.get(dc2);
		if(dc1>='0'&&dc1<='9'){
			decimal = (dc1-'0')*10;
			if(dc2>='0'&&dc2<='9')
				decimal += dc2-'0';
		}
	}
	else
		decimal = 0;
	string ipart(""),dpart("");
	if(decimal == 0)
	{
		dpart = zheng;
	}
	else
	{
		if(decimal<10){
			dpart += CH[decimal];
			dpart += fen;
		}
		else{
			dpart += CH[decimal/10];
			dpart += jiao;
			if(decimal%10!=0){
				dpart += CH[decimal%10];
				dpart += fen;
			}
		}
	}
	int n = integeral;
	vector<int> number;
	while (n){
		number.push_back(n%10);
		n/=10;
	}
	int pos = 0;
	while(number[pos]==0)
		pos++;

	for(int i=number.size()-1; i>=pos; --i){
		if (number[i]){
			ipart += CH[number[i]];
			ipart += Unit[i];
		}
		else{
			ipart+=zero;
		}
	}
	if(pos>=8)
		ipart += yiyuan;
	if(pos>4&&pos<8)
		ipart += wanyuan;
	if(pos>0)
		ipart += yuan;

	return (ipart+dpart);
}
int main()
{
	double money;
	cout<<"����������ֵ��";
	cin>>money;
	cout<<"���Ľ��:"<<"\t"<<transformCH(money)<<endl;
}
