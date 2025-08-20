#include<iostream>
#include<utility>
using namespace std;
class HaveAll {
public:
	//默认构造函数——函数无参数
	HaveAll():member(0)
	{
		cout<<"default constructo"<<member<<endl;
	}
	//隐式类型转换构造函数——输入的数据转换为int型
	HaveAll(int n):member(n){
		cout<<"converting constructor"<<member<<endl;
	}
	//拷贝构造函数
	HaveAll(const HaveAll& lh):member(lh.member){
		cout<<"copy constructor"<<member<<endl;
	}
	HaveAll(HaveAll&& rh)noexcept:member(rh.member)
	{
		cout<<"move constructor"<<member<<endl;
	}
	
};
