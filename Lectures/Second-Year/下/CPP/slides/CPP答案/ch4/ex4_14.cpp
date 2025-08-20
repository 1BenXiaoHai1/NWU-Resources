/*
 * ex4_1.cpp
 *
 * 14. ��д���򣬽�һ���ļ�file�е����е���word1ȫ���滻Ϊword2��file��word1��word2���û����롣
 *
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
	string filename;
	cout << "Enter file name: ";
	cin >> filename;
	file.open(filename.c_str());
	if(!file.is_open()){
		cerr << "Cannot open file: " << filename << endl;
		exit(1);
	}

	string word1, word2;
	cout << "Enter word 1: ";
	cin >> word1;
	cout << "Enter word 2: ";
	cin >> word2;

	string line;
	ostringstream os;

	while(!file.eof()){
		getline(file, line);

		string::size_type pos =0 ;
		auto a = word1.size();
		auto b = word2.size();
		while((pos = line.find(word1, pos))!= string::npos){
			line.erase(pos, a);
			line.insert(pos, word2);
			pos += b;
		}
		os << line << '\n';
	}
	file.close();

	ofstream output(filename);
	output << os.str();
	output.close();

	return 0;
}



