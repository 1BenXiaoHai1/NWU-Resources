/*
 * ex12_6.cpp
 *
 *
 *      6. 编写程序，按照字典序列出一个文件中的所有不同单词及其出现次数。
 */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<string, int> dic;
	string filename, word;
	cout<<"Please input filename:";
	cin>>filename;
	ifstream file(filename.c_str());
	while (file>>word) { dic[word] += 1; }
	cout<<"There are "<<dic.size()<<" different words in file "<<filename<<endl;
	map<string, int>::iterator p;
	for(p = dic.begin(); p!=dic.end(); p++)
		cout << p->first << "\t" << p->second << endl;
}
