/*
 * ex7_4.cpp
 *
 *  4. 设计一个名为IntStack的栈类，用于存储整数。栈以“后进先出”的方式存取元素。
 这个类应该包含：
 （1）名为element的数据域，保存栈中的int值；element的类型可以使用vector或在堆上分配的动态数组；
 （2）名为size的数据域，保存栈中元素的个数；
 （3）名为capacity的数据域，保存栈的容量，默认为16；
 （4）默认构造函数，用默认的栈容量值初始化IntStack对象；
 （5）带一个整型参数的构造函数，参数指定所创建栈的初始容量；不能用作隐式类型转换，如果指定的参数值小于16，则初始化为16；
 （6）进栈操作void push(int value)，将value加入栈中；一旦栈中的元素个数超出了当前容量，就将栈的容量翻倍；
 （7）出栈操作 int pop()，删除栈顶的元素并将其返回；pop操作不改变栈的容量；
 （8）判断栈是否为空的操作bool empty()，如果栈为空，返回true；
 （9）成员函数size_t getSize()，返回栈中元素的个数；
 （10）根据（2）中选择的数据结构，设计需要的拷贝控制成员。
 编写测试程序，利用IntStack将输入的整数序列逆序输出。
 *
 */

#include<vector>
#include<iostream>
using namespace std;
class IntStack{
public:
	IntStack();
	explicit IntStack(int cap);

	//copy members
	IntStack(const IntStack&) = default;
	IntStack(IntStack&&) = default;
	IntStack& operator=(const IntStack&) = default;
	IntStack& operator=(IntStack&&) = default;
	~IntStack() = default;

	//stack operations
	void push(int value);
	int pop();
	bool empty()const;
	size_t getSize()const;

private:
	//size and capacity are unnecessary for vector
	int size = 0;
	int capacity = 16;
	vector<int> element;
};

IntStack::IntStack():size(0), capacity(16){
}

IntStack::IntStack(int cap) {
	if(cap < 16)
		capacity = 16;
	else
		capacity = cap;
}

void IntStack::push(int value) {

	element.push_back(value);
}

int IntStack::pop() {
	int top = element.back();
	element.pop_back();
	return top;
}

bool IntStack::empty() const {
	return element.empty();
}

size_t IntStack::getSize() const {
	return element.size();
}

//-----------------------------------
int main()
{
	cout << "Enter capacity for stack: " << endl;
	int cap;
	cin >> cap;
	IntStack is(cap);
	cout << "Enter integers to be pushed into the stack: " << endl;

	for(int i = 0; i < cap; ++i){
		int val;
		cin >> val;
		is.push(val);
	}

	while(!is.empty())
		cout << is.pop() << " ";



	return 0;
}



