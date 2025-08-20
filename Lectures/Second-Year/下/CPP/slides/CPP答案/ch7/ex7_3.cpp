/*
 * ex7_2.cpp
 *
 *  3. 重新实现6.7节的字符串类：使用shared_ptr类管理动态存储空间，定义所有的拷贝控制成员。
 *
 */
#include <memory>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class MyString{
	int sz = 0;
	shared_ptr<char> content = nullptr;
public:
	MyString();
	explicit MyString(int len);
	MyString(const char* cstr);
	MyString(const MyString& ls);
	MyString(MyString&& rs)noexcept;
	MyString& operator=(const MyString& ls);
	MyString& operator=(MyString&& rs)noexcept;
	~MyString();

	int size()const;
	void print()const;
	char get(int index)const;
	char& get(int index);

};

MyString::MyString() {
	content = nullptr;
	sz = 0;
}

MyString::MyString(int len): sz(len),
		content(new char[sz], [](char* p){ delete[] p; }) {
}

MyString::MyString(const char* cstr) {
	sz = strlen(cstr);
	shared_ptr<char> st(new char[sz], [](char *p){delete[] p;});
	char *pc = st.get();
	for(int i = 0; i < sz; ++i)
		pc[i] = cstr[i];
	content.swap(st);
}

//deep copy
MyString::MyString(const MyString& ls) {
	sz = ls.sz;
	shared_ptr<char> st(new char[sz], [](char *p){delete[] p;});
	char *pc = st.get();
	for(int i = 0; i < sz; ++i)
		pc[i] = ls.get(i);

	content.swap(st);
}

//shallow copy
MyString::MyString(MyString&& rs) noexcept {
	sz = rs.sz;
	content = rs.content;
}
//deep copy
MyString& MyString::operator =(const MyString& ls) {
	if(this != &ls){
		sz = ls.sz;
		shared_ptr<char> st(new char[sz], [](char *p){delete[] p;});
		char *pc = st.get();
		for(int i = 0; i < sz; ++i)
			pc[i] = ls.get(i);

		content.swap(st);
	}
	return *this;
}
//shallow copy
MyString& MyString::operator =(MyString&& rs) noexcept {
	sz = rs.sz;
	content = rs.content;
	return *this;
}

MyString::~MyString() {

}

int MyString::size() const {
	return sz;
}

void MyString::print() const {

	for(int i = 0; i < sz; ++i)
		cout << get(i);
	cout << endl;
}

char MyString::get(int index) const {
	assert(index >= 0 && index < size());
	char*p = content.get();
	return p[index];
}

char& MyString::get(int index) {
	assert(index >= 0 && index < size());
	char* p = content.get();
	return p[index];
}


int main()
{
	MyString s1("abcd"), s2("1234");

	s1.print();
	s2.print();

	MyString s3(s1);
	s1.print();
	s3.print();

	s3.get(2) = 'X';
	s1.print();
	s3.print();

	s3 = s2;
	s2.print();
	s3.print();

	s3.get(2) = 'X';
	s2.print();
	s3.print();

	return 0;
}



