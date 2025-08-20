/*
 * ex3_14.cpp
 *
 *  14. 编写程序，打印100以内的素数。
 *
 */

#include <iostream>
using namespace std;
int main()
{
	const int max = 100;
	int num = 0;
	int i,j;
	for(i=2; i<=max; i++){
		for(j = 2; j<i; j++){
			if(i%j)
				continue;
			else
				break;
		}
		if(j==i){
			cout<<i;
			num++;
			cout<<((num%5)?"\t":"\n");
		}
	}
}



