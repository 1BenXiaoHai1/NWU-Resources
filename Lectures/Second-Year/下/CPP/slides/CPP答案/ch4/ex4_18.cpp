/*
 * ex4_18.cpp
 *
 * 18. ��ȡһ���ı��ļ��е���ֵ��������д����һ�����ļ����ɿհ׻������ַ��ֿ������ֱ���Ϊ�ǲ�ͬ����ֵ��
 * ���磬����ļ�����Ϊ����ab7c d234bk jalf 34 78k3j4 a 59jfd45����
 * ��ô��ȡ����ֵ�����ǣ�7��234��34��78��3��4��59��45��
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
	//����תΪ�ַ���
	string content;
	ostringstream os;
	while(getline(in, content))
		os<<content<<' ';
	content = os.str();
	//ɾ�����еķ�����
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
	//����������ֵ�ַ�����
	istringstream is;
	is.str(os.str());
	int value;
	//��ȡ��ֵ�����
	while(is>>value)
	{
		out<<value<<"\t";
	}
}
