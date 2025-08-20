/*
 * ex7_5.cpp
 *
 *  5. 设计一个名为IntQueue的队列类，用于存储整数。队列以“先进先出”的方式存取元素。这个类应该包含：
 （1）名为element的数据域，保存队列中的int值；element的类型可以使用vector或在堆上分配的动态数组；
 （2）名为size的数据域，保存队列中元素的个数；
 （3）默认构造函数，用默认的队列容量值初始化IntQueue对象；
 （5）带一个整型参数的构造函数，参数指定所创建队列的初始容量；不能用作隐式类型转换，如果指定的参数值小于8，则初始化为8；
 （6）进队列操作void enqueue(int value)，将value加入队列尾；一旦元素个数超过了队列容量，将队列容量翻倍；
 （7）出队列操作 int dequeue()，删除队列首元素并将其返回；原来的第二个元素变成新的队列首元素，依次类推；
 （8）判断队列是否为空的操作bool empty()，如果队列为空，返回true；
 （9）成员函数size_t getSize()，返回队列中元素的个数；
 （10）根据（2）中选择的数据结构，设计需要的拷贝控制成员。
 编写测试程序，利用IntQueue将输入的整数加入队列，然后逐一移出队列并输出。
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



