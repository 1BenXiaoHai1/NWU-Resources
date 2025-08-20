/*
 * ex4_16.cpp
 *
 * 16. 文件data.txt中有一组整数，编程循环读入文件中的整数，判断其能否被3、5、7整除，
 * 并对每个整数输出它能被3、5、7中的哪个或哪些整除。
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



