/*
 * ex6_12.cpp
 *
 * 12. 设计并实现一个ObjectCounter类，要求：
 * （1）对系统中现存的本类实例计数；
 * （2）每个对象都有唯一的整型ID，按照创建的次序建立；
 * （3）获取当前系统中本类对象的个数；
 * （4）获取每个对象的ID；
 * 编写测试程序。
 *
 *
 */
#include <iostream>
#include <string>
using namespace std;
class ObjectCounter{
public:
	ObjectCounter(string n):oid(++SN),name(n){count++;}
	~ObjectCounter(){count--;}
	ObjectCounter(const ObjectCounter& obj){
		oid = ++SN;
		count++;
	}
	static int getCount(){return count;}
	int getOid(){return oid;}
	string getName(){return  name;}

private:
	static int count;
	static int SN;
	int oid;
	string name;
};
int ObjectCounter::SN = 0;
int ObjectCounter::count = 0;
//----------------------

int main()
{
	ObjectCounter a("a"),b("b"),c("c");
	ObjectCounter *p = new ObjectCounter("d");
	cout<<a.getName()<<"\t"<<a.getOid()<<"\t"<<a.getCount()<<endl;
	cout<<b.getName()<<"\t"<<b.getOid()<<"\t"<<b.getCount()<<endl;
	cout<<c.getName()<<"\t"<<c.getOid()<<"\t"<<c.getCount()<<endl;
	cout<<p->getName()<<"\t"<<p->getOid()<<"\t"<<p->getCount()<<endl;
	delete p;
	cout<<ObjectCounter::getCount()<<endl;

}
