#include<iostream>
#include<vector>
using namespace std;

string NumToStr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void _letterCombinations(string &digits,int i,string s,vector<string>&ret)
{
	//�ݹ���ֹ�������������������ָ��������������ִ��ĳ���
	if(i==digits.size())//�ݹ鵽�׺���뵽����ַ�����
	{
		cout<<"�Ѵﵽ��ֹ����"<<endl;
		ret.push_back(s);//��sѹ��ret
		return ;
	}
	int num=digits[i]-'0';//��������ַ����е�ǰ�ַ���Ӧ������
	string& tmp=NumToStr[num];//��ȡ��Ӧ��������Ӧ���ַ���
	for(int j=0;j<tmp.size();j++)
	{
		//ȡ���ַ����е�һ���ַ��ݹ鵽��һ�����һ�����ֶ�Ӧ�ַ�����ÿһ���ַ����
		_letterCombinations(digits,i+1,s+tmp[j],ret);
	}
}


int main()
{
	string digits;
	cout<<"������绰����:";
	cin>>digits;
	vector<string> ret;//��������ִ�
	string s;//��ŵݹ����ַ���
	int i=0;//��¼�ݹ�Ĳ���
	_letterCombinations(digits,i,s,ret);//�ݹ麯��
	cout<<s;
	
	return 0;
}
