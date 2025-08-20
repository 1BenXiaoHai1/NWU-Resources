#include<iostream>
#include<vector>
using namespace std;

vector<string> letterCombinations(string digits) 
{
	vector<string> res;
	//�绰�����Ӧ���ַ���
	string charmap[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	res.push_back("");
	for (int i = 0; i < digits.size(); i++)
	{
		vector<string> tempres;//tempres���
		string chars = charmap[digits[i] - '0'];//digits[i] - '0'��ʾ��ǰ�����֣�chars��ʾ��ǰ���ֵĶ�Ӧ�ַ���		
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
	cout<<"������绰����:";
	cin>>digits;
	//����һ����̬���飬��ŵ绰����
	vector<string> res = letterCombinations(digits);
	
	//���Vector<string>����
	for (auto &i : res)//����vector 
	{
		for (auto &j : i)//����string
			cout << j;
		cout << ' ';
	}
	cout << endl;
}
