/*
 * ex5_16.cpp
 *
 *  16. �õݹ���ǵݹ����ַ�ʽʵ��void display(int n) ��������ӡ����ͼ�Σ�
 *
 */


#include <iostream>
using namespace std;

void display1(int n)
{//�ݹ�
	if(n>=1)
	{
		for(int i=1; i<=n; i++)
			cout<<n<<" ";
		cout<<"\n";
		display1(n-1);
	}
	else
		return;

}
void display2(int n)
{//�ǵݹ�
	for(int i=n; i>=1; --i){
		for(int j=i; j>=1; --j)
			cout<<i<<" ";
		cout<<"\n";
	}
}
int main()
{
	cout<<"please input n:"<<endl;
	int n;
	cin>>n;
	display1(n);
	display2(n);
}

