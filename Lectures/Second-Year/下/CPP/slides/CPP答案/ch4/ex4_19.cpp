/*
 * ex4_19.cpp
 *
 * 19. 编写程序，读入文件file1.txt，加行号后输出到文件file2.txt；统计并输出读入的行数和最长行的长度。
 *
 *
 */
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	const int lineSize = 1024;
	int lcnt = 0; //读入的行数
	int max = -1; //最长行的长度
	char inBuf[lineSize];
	ifstream in("file1.txt");
	ofstream out("file2.txt");
	//读取1024 个字符或者读到换行符
	while ( in.getline( inBuf, lineSize)) {
		int readin = in.gcount(); //实际读入的字符
		//统计行数和最长行
		lcnt++;
		if (readin > max)
			max = readin;
		out << "Line #" << lcnt;
		out.write( inBuf, readin).put('\n');
	}
	cout << "Total lines read: "<< lcnt << endl;
	cout << "Longest line read: " << max << endl;
}
