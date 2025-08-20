#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

struct ScoreItem{
	string name;
	vector<int> scores;//动态数组 分数可能有多种
};

int main()
{
	vector<ScoreItem> scoreSheet;//定义一个表
	//从文件中读取数据
	ifstream fin("scores.txt");//定义一个文件流输入类
	while(!fin.eof()){
		//读取一个学生的信息(一行信息)
		ScoreItem item;
		string buffer;
		getline(fin,buffer);
		//跳过空行
		if(buffer.empty()){
			continue;
		}
		istringstream is(buffer);//利用字符串流逐项提取学生的成绩
		is>>item.name;
		int score;
		while(is>>score){
			item.scores.push_back(score);
		}
		//将学生信息放到表中
		scoreSheet.push_back(item);//压入一个数组(姓名 成绩A 成绩B 成绩C)
	}
	fin.close();//关闭文件
	
}


