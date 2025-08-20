#include<iostream>
#include<vector>
using namespace std;

string NumToStr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void _letterCombinations(string &digits,int i,string s,vector<string>&ret)
{
	//递归终止条件——所遍历的数字个数等于输入数字串的长度
	if(i==digits.size())//递归到底后插入到结果字符串中
	{
		cout<<"已达到终止条件"<<endl;
		ret.push_back(s);//把s压入ret
		return ;
	}
	int num=digits[i]-'0';//获得数字字符串中当前字符对应的数字
	string& tmp=NumToStr[num];//获取相应数字所对应的字符串
	for(int j=0;j<tmp.size();j++)
	{
		//取出字符串中的一个字符递归到下一层和下一个数字对应字符串的每一个字符结合
		_letterCombinations(digits,i+1,s+tmp[j],ret);
	}
}


int main()
{
	string digits;
	cout<<"请输入电话号码:";
	cin>>digits;
	vector<string> ret;//存放所有字串
	string s;//存放递归后的字符串
	int i=0;//记录递归的层数
	_letterCombinations(digits,i,s,ret);//递归函数
	cout<<s;
	
	return 0;
}
