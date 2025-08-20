/*
 * ex4_20.cpp
 *
 * 20. 编写程序，提示用户分别输入两个文件file1和file2的名字，合并两个文件的内容。如果文件不存在，给出错误信息。
 *
 *
 */
#include<string>
#include<fstream>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
	cout << "Enter file name 1: " << endl;
	string filename1;
	cin >> filename1;
	cout << "Enter file name 2: " << endl;
	string filename2;
	cin >> filename2;

	ofstream file1(filename1, ios::app);
	ifstream file2(filename2);

	char ch;
	while(file2.get(ch))
		file1.put(ch);

	file1.close();
	file2.close();


	return 0;
}



