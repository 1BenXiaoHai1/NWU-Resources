/*
 * ex4_16.cpp
 *
 * 16. �ļ�data.txt����һ�����������ѭ�������ļ��е��������ж����ܷ�3��5��7������
 * ����ÿ������������ܱ�3��5��7�е��ĸ�����Щ������
 *
 *
 */
#include<vector>
#include<fstream>
#include<iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ifstream file("data.txt");
	if(!file.is_open()){
		cerr << "Error while open file data.txt." << endl;
		exit(1);
	}
	int number;
	const unsigned char three = 0B01;
	const unsigned char five = 0B010;
	const unsigned char seven = 0B0100;

	while(file >> number){
		unsigned char flag = 0x00;
		if(number % 3 == 0)
			flag |= three;
		if(number % 5 == 0)
			flag |= five;
		if(number % 7 == 0)
			flag |= seven;

		if(flag == 0B0111)
			cout << number << " can be divisible by 3, 5 and 7." << endl;
		else if(flag == 0B0101)
			cout << number << " can be divisible by 3 and 7." << endl;
		else if(flag == 0B0100)
			cout << number << " can be divisible by 7." << endl;
		else if(flag == 0B011)
			cout << number << " can be divisible by 3 and 5." << endl;
		else if(flag == 0B010)
			cout << number << " can be divisible by 5." << endl;
		else if(flag == 0B01)
			cout << number << " can be divisible by 3." << endl;
		else
			cout << number << " can be divisible by none." << endl;
	}

	file.close();


	return 0;
}



