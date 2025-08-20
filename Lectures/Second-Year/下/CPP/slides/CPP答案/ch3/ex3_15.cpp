/*
 * ex3_15.cpp
 *
 *     15. ±‡–¥≥Ã–Ú£¨º∆À„1!+2!+......+10!°£
 */

#include<iostream>
using namespace std;
int main()
{
	long result = 0;
	long factorial = 1;
	for(int num = 1; num <= 10; num++){
		factorial *= num;
		result += factorial;
	}
	cout<<"1!+2!+...+10!="<<result<<endl;

	return 0;
}



