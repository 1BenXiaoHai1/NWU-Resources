/*
 * ex5_14.cpp
 *
 *  14. 编写函数，将参数传入的一个浮点数值转换为中文金额的大写格式，转换结果作为字符串返回。
 *  ·当金额为整数时，只表示整数部分，省略小数部分，并添加"整"字。
 *  ·当金额中含有连续的0时，只需要一个"零"即可。
 *  ·注意10的表示，例如110：壹佰壹拾元整，10：壹拾元整。
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string CH[] = {"","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
string Unit[] = {"元","拾","佰","仟","万",
		"拾","佰","仟","亿",
		"拾","佰","仟","万","兆"};
string jiao = "角";
string fen = "分";
string zheng = "整";
string zero = "零";
string yuan = "元";
string wanyuan = "万";
string yiyuan = "亿";
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
	cout<<"请输入金额数值：";
	cin>>money;
	cout<<"中文金额:"<<"\t"<<transformCH(money)<<endl;
}
