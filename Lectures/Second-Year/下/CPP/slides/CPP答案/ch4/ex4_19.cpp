/*
 * ex4_19.cpp
 *
 * 19. ��д���򣬶����ļ�file1.txt�����кź�������ļ�file2.txt��ͳ�Ʋ�����������������еĳ��ȡ�
 *
 *
 */
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	const int lineSize = 1024;
	int lcnt = 0; //���������
	int max = -1; //��еĳ���
	char inBuf[lineSize];
	ifstream in("file1.txt");
	ofstream out("file2.txt");
	//��ȡ1024 ���ַ����߶������з�
	while ( in.getline( inBuf, lineSize)) {
		int readin = in.gcount(); //ʵ�ʶ�����ַ�
		//ͳ�����������
		lcnt++;
		if (readin > max)
			max = readin;
		out << "Line #" << lcnt;
		out.write( inBuf, readin).put('\n');
	}
	cout << "Total lines read: "<< lcnt << endl;
	cout << "Longest line read: " << max << endl;
}
