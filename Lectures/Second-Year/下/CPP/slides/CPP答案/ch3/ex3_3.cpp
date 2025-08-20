/*
 * ex3_3.cpp
 *
 * 3. 编写程序，提示用户输入两个点（x1，y1）和（x2，y2），计算两点之间的距离并输出。
 * 求a的平方根的库函数为sqrt(a)，要包含标准库<cmath>。
 */

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	cout << "enter point1: x1 y1" << endl;
	double x1, y1;
	cin >> x1 >> y1;
	cout << "enter point2: x2 y2" << endl;
	double x2, y2;
	cin >> x2 >> y2;
	double distance =sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	cout << "distance between ("
			<< x1 << "," << y1 <<") and ("
			<< x2 << "," << y2 <<") is "
			<< distance << endl;

	return 0;
}



