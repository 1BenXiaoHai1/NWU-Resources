/*
 * ex4_6.cpp
 *
 * 6. ���ö�ά�����д����ʵ�����²������Ը���������ѧ���ĸ����ųɼ���������гɼ��е���߷ֺ���ͷ֣������ÿ��ѧ����ƽ���֡�
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
		cout<<"ѧ�� "<<i+1<<"��ƽ����: "<<average[i]<<endl;
	}
	cout<<"���гɼ��е���ͷ�:"<<min<<endl;
	cout<<"���гɼ��е���߷�:"<<max<<endl;
}


