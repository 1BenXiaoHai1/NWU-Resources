#include<iostream>
#include<utility>
using namespace std;
class HaveAll {
public:
	//Ĭ�Ϲ��캯�����������޲���
	HaveAll():member(0)
	{
		cout<<"default constructo"<<member<<endl;
	}
	//��ʽ����ת�����캯���������������ת��Ϊint��
	HaveAll(int n):member(n){
		cout<<"converting constructor"<<member<<endl;
	}
	//�������캯��
	HaveAll(const HaveAll& lh):member(lh.member){
		cout<<"copy constructor"<<member<<endl;
	}
	HaveAll(HaveAll&& rh)noexcept:member(rh.member)
	{
		cout<<"move constructor"<<member<<endl;
	}
	
};
