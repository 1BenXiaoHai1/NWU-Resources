/*
 * ex4_10.cpp
 *
 * 10. ��д������ʾ�û�����һ���������ҳ�������С������
 *
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> numbers;
	int n;
	cout << "enter integers: ";
	while (cin >> n)
		numbers.push_back(n);

	//����һ
	int min = numbers[0];
	for(size_t i = 1; i < numbers.size(); ++i)
		if(numbers[i] < min)
			min = numbers[i];

	cout << "The least integer is: " << min << endl;

	//�����������ñ�׼�㷨����
	sort(numbers.begin(), numbers.end());
	cout << "The least integer is: " << numbers[0] << endl;

	return 0;
}



