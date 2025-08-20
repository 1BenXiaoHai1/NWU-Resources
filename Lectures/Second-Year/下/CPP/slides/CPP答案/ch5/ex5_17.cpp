/*
 * ex5_1.cpp
 *
 *  17. 假定小兔子一个月就能长成大兔子，而一对大兔子每个月都会生出一对小兔子。
 *  如果年初养了一对小兔子，问到年底时有多少对兔子？用递归函数解决这个问题。
 *
 */

#include <iostream>
using namespace std;

int rabbit(int big, int small, int month)
{
	if(month == 0)
		return big+small;
	else
		return rabbit(big+small, big, month-1);
}

int main()
{
	cout<<rabbit(0,1,12)<<endl;
}

