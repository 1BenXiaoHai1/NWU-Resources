/*
 * ex7_4.cpp
 *
 *  4. ���һ����ΪIntStack��ջ�࣬���ڴ洢������ջ�ԡ�����ȳ����ķ�ʽ��ȡԪ�ء�
 �����Ӧ�ð�����
 ��1����Ϊelement�������򣬱���ջ�е�intֵ��element�����Ϳ���ʹ��vector���ڶ��Ϸ���Ķ�̬���飻
 ��2����Ϊsize�������򣬱���ջ��Ԫ�صĸ�����
 ��3����Ϊcapacity�������򣬱���ջ��������Ĭ��Ϊ16��
 ��4��Ĭ�Ϲ��캯������Ĭ�ϵ�ջ����ֵ��ʼ��IntStack����
 ��5����һ�����Ͳ����Ĺ��캯��������ָ��������ջ�ĳ�ʼ����������������ʽ����ת�������ָ���Ĳ���ֵС��16�����ʼ��Ϊ16��
 ��6����ջ����void push(int value)����value����ջ�У�һ��ջ�е�Ԫ�ظ��������˵�ǰ�������ͽ�ջ������������
 ��7����ջ���� int pop()��ɾ��ջ����Ԫ�ز����䷵�أ�pop�������ı�ջ��������
 ��8���ж�ջ�Ƿ�Ϊ�յĲ���bool empty()�����ջΪ�գ�����true��
 ��9����Ա����size_t getSize()������ջ��Ԫ�صĸ�����
 ��10�����ݣ�2����ѡ������ݽṹ�������Ҫ�Ŀ������Ƴ�Ա��
 ��д���Գ�������IntStack������������������������
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



