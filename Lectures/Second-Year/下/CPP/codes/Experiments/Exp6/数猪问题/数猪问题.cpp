#include<iostream>

using namespace std;

int CalPigs(int day) {
	if (day == 7) { //��ֹ����������������ʣ�������Ϊ2
		return 2;
	} else {
		return 2 * CalPigs(day + 1) + 2;
		//����������������ڵ����������������+������ʣ���������
	}
}

void PrintPigs(int sum) {
	int Reminder = sum;//Reminder���浱ǰ������
	for (int i = 1; i <= 7; i++) {
		int Total = Reminder;//Total����ǰ���ʣ�ĵ��������
		Reminder = Reminder / 2 - 1; //Reminder�޸�Ϊ������������
		cout << "������" << i << "�������������������Ϊ" << Total - Reminder << "��ʣ" << Reminder << endl;
	}
}

int main() {
	int sum = CalPigs(1);
	cout << "����Ϊ" << sum << endl;
	PrintPigs(sum);
	return 0;
}
