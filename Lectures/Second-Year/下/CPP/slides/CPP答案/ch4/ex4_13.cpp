/*
 * ex4_13.cpp
 *
 * 13. 编写程序，从一个文本文件中删除所有指定的某个字符串。
 *
 */
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	ifstream file;
	string delstr, filename;
	cout << "Enter file name: ";
	cin >> filename;
	file.open(filename.c_str());
	if(!file.is_open()){
		cerr << "Cannot open file: " << filename << endl;
		exit(1);
	}

	cout << "Enter string to be deleted: ";
	cin >> delstr;

	string line;
	ostringstream os;

	while(!file.eof()){
		getline(file, line);

		string::size_type pos =0 ;
		string::size_type a = delstr.size();
		while((pos = line.find(delstr, pos))!= string::npos){
			line.erase(pos, a);
		}
		os << line << '\n';
	}
	file.close();

	ofstream output(filename);
	output << os.str();
	output.close();

	return 0;
}


