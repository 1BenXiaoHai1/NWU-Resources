/*
 * ex3_9.cpp
 *
 *  9. 利用switch-case结构完成此题：
 *  判断学生成绩等级，学习成绩≥90分输出“优秀”，80分≤学生成绩＜90分输出“良好”，
 *  60分≤学生成绩＜80分输出“及格”，学习成绩＜60分输出“不及格”。
 */
#include<iostream>
using namespace std;

int main()
{
	int score;
	cout << "Enter score: ";
	cin >> score;

	switch(score / 10){
	case 10: case 9:
		cout << "优秀" << endl;
		break;
	case 8:
		cout << "良好" << endl;
		break;
	case 7: case 6:
		cout << "及格" << endl;
		break;
	case 5: case 4: case 3: case 2: case 1: case 0:
		cout << "不及格" << endl;
		break;
	default:
		cerr << "invalid score." << endl;

	}


	return 0;
}






