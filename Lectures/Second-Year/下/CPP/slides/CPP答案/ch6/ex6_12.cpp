/*
 * ex6_12.cpp
 *
 * 12. ��Ʋ�ʵ��һ��ObjectCounter�࣬Ҫ��
 * ��1����ϵͳ���ִ�ı���ʵ��������
 * ��2��ÿ��������Ψһ������ID�����մ����Ĵ�������
 * ��3����ȡ��ǰϵͳ�б������ĸ�����
 * ��4����ȡÿ�������ID��
 * ��д���Գ���
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
