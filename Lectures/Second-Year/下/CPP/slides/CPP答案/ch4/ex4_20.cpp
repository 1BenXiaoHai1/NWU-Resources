/*
 * ex4_20.cpp
 *
 * 20. ��д������ʾ�û��ֱ����������ļ�file1��file2�����֣��ϲ������ļ������ݡ�����ļ������ڣ�����������Ϣ��
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



