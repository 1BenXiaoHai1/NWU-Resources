/*
 * ex3_21.cpp
 *
 *  21. 编写程序，求n2>12000的最小整数n的值。
 */

#include<iostream>
using namespace std;

int main()
{
	int n = 1;
	const int value = 12000;

	do{
		if( n * n < value)
		{
			++n;
			continue;
		}
		else
			break;

	}while(true);

	cout << " n = " << n << endl;

	return 0;
}


