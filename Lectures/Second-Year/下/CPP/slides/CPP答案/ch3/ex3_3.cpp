/*
 * ex3_3.cpp
 *
 * 3. ��д������ʾ�û����������㣨x1��y1���ͣ�x2��y2������������֮��ľ��벢�����
 * ��a��ƽ�����Ŀ⺯��Ϊsqrt(a)��Ҫ������׼��<cmath>��
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



