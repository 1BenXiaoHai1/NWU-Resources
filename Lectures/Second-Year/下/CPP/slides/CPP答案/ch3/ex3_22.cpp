/*
 * ex3_22.cpp
 *
 *  22. 编写程序，求n3<12000的最大整数n的值。
 */


#include<iostream>
using namespace std;

int main()
{
	int n = 1;
	const int value = 12000;

	do{
		if( n * n * n < value)
		{
			++n;
			continue;
		}
		else
			break;

	}while(true);

	cout << " n = " << n-1 << endl;

	return 0;
}



