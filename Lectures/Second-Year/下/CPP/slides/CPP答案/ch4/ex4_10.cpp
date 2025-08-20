/*
 * ex4_10.cpp
 *
 * 10. 编写程序，提示用户输入一组整数，找出其中最小的数。
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

	//方法一
	int min = numbers[0];
	for(size_t i = 1; i < numbers.size(); ++i)
		if(numbers[i] < min)
			min = numbers[i];

	cout << "The least integer is: " << min << endl;

	//方法二：利用标准算法排序
	sort(numbers.begin(), numbers.end());
	cout << "The least integer is: " << numbers[0] << endl;

	return 0;
}



