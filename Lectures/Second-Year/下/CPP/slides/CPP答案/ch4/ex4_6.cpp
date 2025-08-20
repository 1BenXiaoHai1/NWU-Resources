/*
 * ex4_6.cpp
 *
 * 6. 利用多维数组编写程序实现以下操作：对给定的两名学生的各三门成绩，输出所有成绩中的最高分和最低分，并输出每个学生的平均分。
 *
 *
 */
#include <iostream>
using namespace std;
const int stu = 2, scr = 3;
int main()
{
	int score[stu][scr] = {
			{80, 95, 86},
			{75, 89, 91}
	};
	double average[stu];
	int min = score[0][0], max = score[0][0];
	for(int i=0; i<stu; i++)
	{
		double sum = 0;
		for(int j=0; j<scr; j++)
		{
			if(min>score[i][j])
				min = score[i][j];
			if(max<score[i][j])
				max = score[i][j];
			sum += score[i][j];
		}
		average[i] = sum/3;
		cout<<"学生 "<<i+1<<"的平均分: "<<average[i]<<endl;
	}
	cout<<"所有成绩中的最低分:"<<min<<endl;
	cout<<"所有成绩中的最高分:"<<max<<endl;
}


