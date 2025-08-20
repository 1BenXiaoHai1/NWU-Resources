/*
 * ex4_18.cpp
 *
 * 18. 提取一个文本文件中的数值，将它们写入另一个新文件，由空白或其他字符分开的数字被认为是不同的数值。
 * 例如，如果文件内容为：“ab7c d234bk jalf 34 78k3j4 a 59jfd45”，
 * 那么提取的数值依次是：7，234，34，78，3，4，59，45。
 *
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	if(argc<3){
		cout<<"Inadequate arguments."<<endl;
		exit(1);
	}
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	//内容转为字符串
	string content;
	ostringstream os;
	while(getline(in, content))
		os<<content<<' ';
	content = os.str();
	//删除其中的非数字
	string::iterator pos;
	os.str("");
	for(pos = content.begin(); pos!=content.end(); pos++)
	{
		if (*pos <'0' || *pos >'9')
		{
			os<<" ";
		}
		else
		{
			os<<*pos;
		}
	}
	//构造输入数值字符串流
	istringstream is;
	is.str(os.str());
	int value;
	//提取数值，输出
	while(is>>value)
	{
		out<<value<<"\t";
	}
}
