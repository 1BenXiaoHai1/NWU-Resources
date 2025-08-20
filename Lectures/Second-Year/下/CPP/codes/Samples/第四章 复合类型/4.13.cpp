#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct ScoreItem{
	string name;
	vector<int> scores;//��̬���� ���������ж���
};

int main()
{
	vector<ScoreItem> scoreSheet;//����һ����
	//���ļ��ж�ȡ����
	ifstream fin("scores.txt");//����һ���ļ���������
	while(!fin.eof()){
		//��ȡһ��ѧ������Ϣ(һ����Ϣ)
		ScoreItem item;
		string buffer;
		getline(fin,buffer);
		//��������
		if(buffer.empty()){
			continue;
		}
		istringstream is(buffer);//�����ַ�����������ȡѧ���ĳɼ�
		is>>item.name;
		int score;
		while(is>>score){
			item.scores.push_back(score);
		}
		//��ѧ����Ϣ�ŵ�����
		scoreSheet.push_back(item);//ѹ��һ������(���� �ɼ�A �ɼ�B �ɼ�C)
	}
	fin.close();//�ر��ļ�
	
}


