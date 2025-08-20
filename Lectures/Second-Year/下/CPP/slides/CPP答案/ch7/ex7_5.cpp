/*
 * ex7_5.cpp
 *
 *  5. ���һ����ΪIntQueue�Ķ����࣬���ڴ洢�����������ԡ��Ƚ��ȳ����ķ�ʽ��ȡԪ�ء������Ӧ�ð�����
 ��1����Ϊelement�������򣬱�������е�intֵ��element�����Ϳ���ʹ��vector���ڶ��Ϸ���Ķ�̬���飻
 ��2����Ϊsize�������򣬱��������Ԫ�صĸ�����
 ��3��Ĭ�Ϲ��캯������Ĭ�ϵĶ�������ֵ��ʼ��IntQueue����
 ��5����һ�����Ͳ����Ĺ��캯��������ָ�����������еĳ�ʼ����������������ʽ����ת�������ָ���Ĳ���ֵС��8�����ʼ��Ϊ8��
 ��6�������в���void enqueue(int value)����value�������β��һ��Ԫ�ظ��������˶�������������������������
 ��7�������в��� int dequeue()��ɾ��������Ԫ�ز����䷵�أ�ԭ���ĵڶ���Ԫ�ر���µĶ�����Ԫ�أ��������ƣ�
 ��8���ж϶����Ƿ�Ϊ�յĲ���bool empty()���������Ϊ�գ�����true��
 ��9����Ա����size_t getSize()�����ض�����Ԫ�صĸ�����
 ��10�����ݣ�2����ѡ������ݽṹ�������Ҫ�Ŀ������Ƴ�Ա��
 ��д���Գ�������IntQueue�����������������У�Ȼ����һ�Ƴ����в������
 *
 */

#include<vector>
#include<iostream>
using namespace std;

class IntQueue{
public:
	IntQueue();
	explicit IntQueue(int cap);

	IntQueue(const IntQueue&) = default;
	IntQueue(IntQueue&&) = default;
	IntQueue& operator=(const IntQueue&) = default;
	IntQueue& operator=(IntQueue&&) = default;
	~IntQueue() = default;

	void enqueue(int val);
	int dequeue();
	bool empty() const;
	size_t getSize() const;

private:
	int size = 0;
	int capacity = 8;
	vector<int> element;
};

IntQueue::IntQueue():size(0), capacity(8) {
}

IntQueue::IntQueue(int cap) {
	size = 0;
	if(cap < 8)
		capacity = 8;
	else
		capacity = cap;
}

void IntQueue::enqueue(int val) {
	element.insert(element.begin(), val);
}

int IntQueue::dequeue() {
	int first = element.back();
	element.pop_back();
	return first;
}

bool IntQueue::empty() const {
	return element.empty();
}

size_t IntQueue::getSize() const {
	return element.size();
}

//-------------------------------------
int main()
{
	cout << "Enter capacity of queue: " << endl;
	int cap;
	cin >> cap;
	IntQueue q(cap);

	cout << "Enter integers to be enqueued: " << endl;

	for(int i = 0; i < cap; ++i){
		int val;
		cin >> val;
		q.enqueue(val);
	}

	while(!q.empty())
		cout << q.dequeue() << " ";


	return 0;
}



