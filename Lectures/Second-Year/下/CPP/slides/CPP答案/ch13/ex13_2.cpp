/*
 * ex13_2.cpp
 *
 *
 *      2. �Ӽ�������10 �������������������ʱ��������Ӧ����ʾ������ʾ�������룬
 *      ��������ɺ��ҵ���������е����������С����
 */

#include <iostream>
#include <vector>
using namespace std;
class Error{
public:
	Error(int v):value(v){}
	void message(){cout<<"You have entered a wrong number:"<<value<<endl;}
private:
	int value;
};
bool validate(int number)
{
	if(number>0)
		return true;
	else
		throw Error(number);
}

int main()
{
	cout<<"Please input ten positive numbers:"<<endl;
	vector<int> numbers;
	int count = 1;
	do{
		try
		{
			int num;
			cout<<"number "<<count<<":";
			cin>>num;
			if(validate(num))
			{
				numbers.push_back(num);
				count++;
			}
		}
		catch(Error eobj)
		{
			eobj.message();
			continue;
		}
	}while(count<=10);
	int maxnum ,minnum ;
	maxnum = minnum = numbers[0];
	for(unsigned int i=1; i<numbers.size();i++){
		if(maxnum<numbers[i])
			maxnum = numbers[i];
		if(minnum>numbers[i])
			minnum = numbers[i];
	}
	cout<<"Ten numbers you have entered:\n";
	for(unsigned int i=0; i<numbers.size(); i++)
		cout<<numbers[i]<<"\t";
	cout<<"\n the max value is:"<<maxnum<<endl;
	cout<<"the min value is:"<<minnum<<endl;
}
