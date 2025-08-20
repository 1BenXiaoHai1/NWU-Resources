/*
 * ex3_20.cpp
 *
 *  20. 编写程序，读入一个整数，然后以升序显示它的所有最小因子。
 *  例如，输入整数120，则输出应该是：2，2，2，3，5。
 */
#include<iostream>
using namespace std;

int main()
{
	cout << "enter an integer: " << endl;
	int number;
	cin >> number;

	int remain = number;
	while(remain > 1)
	{
		int factor = 2;

		while(factor <= remain){
			if(remain % factor == 0){
				cout << factor << " ";
				remain = remain / factor;
				break;
			}
			else
				++factor;
		}
	}

	return 0;
}



