#include<iostream>
#include<vector>
using namespace std;

vector<string> letterCombinations(string digits) 
{
	vector<string> res;
	//电话号码对应的字符串
	string charmap[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	res.push_back("");
	for (int i = 0; i < digits.size(); i++)
	{
		vector<string> tempres;//tempres存放
		string chars = charmap[digits[i] - '0'];//digits[i] - '0'表示当前的数字，chars表示当前数字的对应字符串		
		for (int c = 0; c < chars.size();c++)
		{
			for (int j = 0; j < res.size();j++)
			{				
				tempres.push_back(res[j]+chars[c]);
			}
		}
		res = tempres;
	}
	return res;
}

int main()
{
	string digits;
	cout<<"请输入电话号码:";
	cin>>digits;
	//定义一个动态数组，存放电话号码
	vector<string> res = letterCombinations(digits);
	
	//输出Vector<string>类型
	for (auto &i : res)//遍历vector 
	{
		for (auto &j : i)//遍历string
			cout << j;
		cout << ' ';
	}
	cout << endl;
}
