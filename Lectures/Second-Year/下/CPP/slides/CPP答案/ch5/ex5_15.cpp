/*
 * ex5_15.cpp
 *
 *  15. ��Ʋ���д����������2����5������������һ��;
 *     ��Ʋ���д����������2����5��������ƽ��ֵ��
 *
 */


#include <limits>
#include <iostream>
using namespace std;
// std::numeric_limits<int>::min()�Ǳ������ܴ������С��intֵ
const int minint = std::numeric_limits<int>::min();
int maxInt(int a,
        int b = minint,
        int c = minint,
        int d = minint,
        int e = minint )
{
  int temp = a > b ? a : b;
  temp = temp > c ? temp : c;
  temp = temp > d ? temp : d;
  return temp > e ? temp : e;
}

double avg(int a, int b)
{
	return (a+b)/2.0;
}
double avg(int a, int b, int c)
{
	return (a+b+c)/3.0;
}
double avg(int a, int b, int c, int d)
{
	return (a+b+c+d)/4.0;
}
double avg(int a, int b, int c, int d, int e)
{
	return (a+b+c+d+e)/5.0;
}

int main()
{
	cout<<maxInt(7)<<endl;
	cout<<maxInt(1,5)<<endl;
	cout<<maxInt(2,5,7)<<endl;
	cout<<maxInt(1,5,7,9)<<endl;
	cout<<maxInt(1,2,5,7,9)<<endl;

	cout<<avg(2,9)<<endl;
	cout<<avg(2,9,6)<<endl;
	cout<<avg(2,3,7,9)<<endl;
	cout<<avg(2,9,7,1,5)<<endl;
}

