/*
 * ex6_13.cpp
 *       6. 设计并实现一个集合类IntSet，集合元素范围为1～100，要求：
 *      （1）正确初始化集合；
 *      （2）支持集合的交集、并集运算；
 *      （3）判断一个指定整数是否在集合中；
 *      （4）将给定整数加入集合，加入前应判断数值范围；
 *      （5）从集合中删除指定元素；
 *      （6）集合对象之间的复制；
 *      （7）获得集合元素个数；
 *      （8）输出集合中的所有元素；
 */

#include <iostream>
using namespace std;
//----------------------------------
class IntSet{
public:
	IntSet();
	~IntSet(){}
	IntSet(const IntSet&);
	IntSet trans(const IntSet&)const;
	IntSet merge(const IntSet&)const;
	bool in(int num)const;
	void add(int num);
	void del(int num);
	int count()const;
	void print()const;
private:
	static const int range = 101;
	bool ele[range];
};
//----------
IntSet::IntSet(){
	for(int i=0; i<range; i++)
		ele[i] = 0;
}

IntSet::IntSet(const IntSet& s){
	for(int i=0; i<range; i++)
		ele[i] = s.ele[i];
}
IntSet IntSet::trans(const IntSet& s)const{
	IntSet temp;
	for(int i=0; i<range; i++)
		temp.ele[i] = ele[i] && s.ele[i];
	return temp;
}
IntSet IntSet::merge(const IntSet& s)const{
	IntSet temp;
	for(int i=0; i<range; i++)
		temp.ele[i] = ele[i] || s.ele[i];
	return temp;
}
bool IntSet::in(int num)const{
	if(num<1 || num>100)
		return false;
	else
		return ele[num];
}
void IntSet::add(int num){
	if(num>=1 && num<=100)
		ele[num] = true;
}
void IntSet::del(int num){
	if(num>=1 && num<=100)
		ele[num] = false;
}
int IntSet::count()const{
	int n = 0;
	for(int i=1; i<range; i++)
		if(ele[i])
			n++;
	return n;

}
void IntSet::print()const{
	cout<<"There are "<<count()<<" elements in set:\n";
	for(int i=1; i<range; i++)
		if(ele[i])
			cout<<i<<" ";
	cout<<endl;
}
//--------------------------
int main()
{
	IntSet s1,s2;
	for(int i=1; i<=100; i++){
		if(i%6 == 0)
			s1.add(i);
		if(i%4 == 0)
			s2.add(i);
	}
	IntSet s3;
	s3 = s1.trans(s2);
	s1.print();
	s2.print();
	s3.print();
	s3 = s1.merge(s2);
	s3.print();
	cout<<s3.count()<<endl;
	cout<<"is 12 in s3?"<<s3.in(12)<<endl;
}

