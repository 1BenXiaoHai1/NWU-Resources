/*
 * ex3_9.cpp
 *
 *  9. ����switch-case�ṹ��ɴ��⣺
 *  �ж�ѧ���ɼ��ȼ���ѧϰ�ɼ���90����������㡱��80�֡�ѧ���ɼ���90����������á���
 *  60�֡�ѧ���ɼ���80����������񡱣�ѧϰ�ɼ���60������������񡱡�
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
		cout << "����" << endl;
		break;
	case 8:
		cout << "����" << endl;
		break;
	case 7: case 6:
		cout << "����" << endl;
		break;
	case 5: case 4: case 3: case 2: case 1: case 0:
		cout << "������" << endl;
		break;
	default:
		cerr << "invalid score." << endl;

	}


	return 0;
}






