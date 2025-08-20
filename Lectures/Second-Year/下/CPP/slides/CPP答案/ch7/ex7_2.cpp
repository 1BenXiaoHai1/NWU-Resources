/*
 * ex7_2.cpp
 *
 *  2. 重新实现6.7节的字符栈类：使用标准库类型vector存储数据，定义所有的拷贝控制成员。
 *
 */
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class ChStack{
	vector<char> stk;
public:
	ChStack();
	ChStack(const ChStack& cs);
	ChStack(ChStack&& cs) noexcept;
	~ChStack();
	ChStack& operator=(const ChStack& cs);
	ChStack& operator=(ChStack&& cs) noexcept;

	void push(char e);
	char pop();
	char top() const;

	int size() const;
	bool empty() const;
};

inline ChStack::ChStack() = default;

inline ChStack::ChStack(const ChStack& cs): stk(cs.stk) {

}

inline ChStack::ChStack(ChStack&& cs) noexcept :stk(cs.stk) {

}

inline ChStack::~ChStack()= default;

ChStack& ChStack::operator =(const ChStack& cs) {
	if(this != &cs)
		stk = cs.stk;

	return *this;
}

ChStack& ChStack::operator =(ChStack&& cs) noexcept {

	stk = cs.stk;
	return *this;
}

void ChStack::push(char e) {
	stk.push_back(e);
}

char ChStack::pop() {
	if(empty())
		return 0;

	char ch = stk.back();
	stk.pop_back();
	return ch;
}

char ChStack::top() const {

	return stk.back();
}

int ChStack::size() const {
	return stk.size();
}

bool ChStack::empty() const {
	return stk.empty();
}

//----------------------------------------

int main()
{
	ChStack cs1;
	cout << "Enter characters: " << endl;
	string str;
	getline(cin, str);

	for(auto e : str)
		cs1.push(e);

	cout << "stack 1: " << cs1.size() << endl;

	ChStack cs2 = cs1;

	cout << "stack 2: " << cs2.size() << endl;

	while(!cs2.empty())
		cout << cs2.pop();

	cout << "\nstack 1: " << cs1.size() << endl;
	cout << "stack 2: " << cs2.size() << endl;

	cs2 = cs1;
	cout << "\nstack 1: " << cs1.size() << endl;
	cout << "stack 2: " << cs2.size() << endl;

	return 0;
}

