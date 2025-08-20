#include<iostream>
#include<string>
#include<vector>
#include<windows.h>

using namespace std;

string AA[] = { "零", "一", "二", "三", "四", "五", "六", "七", "八", "九", "十" };
string BB[] = { "", "十", "百", "千", "万", "十万", "百万", "千万", "亿" };

//界面
void Menu() {
	system("color 70");
	SetConsoleTitle("人民币金额转换");
	cout << "\n-------------人民币金额转换-------------\n" << endl;
	cout << "欢迎来到人民币金额转换" << endl;
	return;
}

//罗马转数字
int RomanToInt(string s) {
	int n = s.length();//罗马数字输入——罗马数字的长度代表有几个字符，字符可以根据其位置进行加减运算
	int res = 0;//阿拉伯数字
	int* num = new int[n];//动态分配数组
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
			case 'M':
				num[i] = 1000;//M-1000
				break;
			case 'D':
				num[i] = 500;//D-500
				break;
			case 'C':
				num[i] = 100;//C-100
				break;
			case 'L':
				num[i] = 50;//L-50
				break;
			case 'X':
				num[i] = 10;//X-10
				break;
			case 'V':
				num[i] = 5;//V-5
				break;
			case 'I':
				num[i] = 1;//I-1
				break;
			default:
				break;
		}
	}
	//计算罗马数字
	for (int i = 0; i < n - 1; i++) {
		if (num[i] < num[i + 1])
			//如果后者比前者大，意味着要用后项减前项，也可以转换成数字和加该前项的负数
			//IV 可以转换成 -I+V
			res -= num[i];
		else//前项大于等于后项，直接加
			res += num[i];
	}
	res += num[n - 1];//
	return res;
}
//数字转中文
string IntToChinese(int num) {
	string res = "";//存储中文名
	string numstr = to_string(num); //直接把00123这种前面的0去掉了
	int k = numstr.length();//存储长度
	for (int i = 0; i < numstr.length(); i++) {
		int tmp = numstr[i] - '0';//tmp存储当前位置的数字
		if (0 == tmp) {//当前位置为0，上一位置也是零，或者最后到数字最后一个位置
			if ('0' == numstr[i - 1] || i == numstr.length() - 1)
				continue;
			else
				res = res + AA[tmp];//进行连接操作——转换为中文
		} else {
			res = res + AA[tmp];//进行连接操作
			if (numstr.length() == 2 && numstr[0] == '1' && i == 0) {
				res.erase(0); //12读作十二，把1删掉
			}
			res = res + BB[k - i - 1];
		}
	}
	return res;
}


int main() {

	string flag;
	do {
		Menu();//菜单打印
		string RomanMoney;//存储罗马数字
		string ChineseMoney;//存储中文数字
		//罗马数字输入
		cout << "请输入罗马金额:" << endl;
		cin.sync();//清除缓冲区
		getline(cin, RomanMoney);
		//罗马数字转数字
		int DigitMoney = RomanToInt(RomanMoney);//罗马转数字
		cout << DigitMoney << endl;
		ChineseMoney = IntToChinese(DigitMoney);//数字转中文
		cout << "中文金额为:" << ChineseMoney << endl;
		cout << "是否继续输入(continue/quit):";
		cin >> flag;
		system("cls");//翻页

	} while (flag != "quit");

	return 0;

}
