/*
 * ex5_4.cpp
 *
 *  4. ��д����ĳ�������Ƿ��������ĺ���bool isPrime(int number)��������������10000���ڵ�����������
 *
 */


#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number){

	if(number == 2)
		return true;
	else if (number < 2)
		return false;

	bool prime = true;
	for(int i = 2; i <= number/2; ++i){
		if(number % i == 0){
			prime = false;
			break;
		}
	}
	return prime;
}

int main()
{
	int count = 0;

	for(int i = 2; i <= 1000; ++i){
		if(isPrime(i)){
			cout << i << "  ";
			++count;
			if(count % 10 == 0)
				cout << "\n";
		}
	}
	cout << "\n number of primes is: " << count << endl;

	return 0;
}

