#include<iostream>
#include<string>
#include<vector>
#include<windows.h>

using namespace std;

string AA[] = { "��", "һ", "��", "��", "��", "��", "��", "��", "��", "��", "ʮ" };
string BB[] = { "", "ʮ", "��", "ǧ", "��", "ʮ��", "����", "ǧ��", "��" };

//����
void Menu() {
	system("color 70");
	SetConsoleTitle("����ҽ��ת��");
	cout << "\n-------------����ҽ��ת��-------------\n" << endl;
	cout << "��ӭ��������ҽ��ת��" << endl;
	return;
}

//����ת����
int RomanToInt(string s) {
	int n = s.length();//�����������롪���������ֵĳ��ȴ����м����ַ����ַ����Ը�����λ�ý��мӼ�����
	int res = 0;//����������
	int* num = new int[n];//��̬��������
	for (int i = 0; i < n; i++) {
		switch (s[i]) {
			case 'M':
				num[i] = 1000;//M-1000
				break;
			case 'D':
				num[i] = 500;//D-500
				break;
			case 'C':
				num[i] = 100;//C-100
				break;
			case 'L':
				num[i] = 50;//L-50
				break;
			case 'X':
				num[i] = 10;//X-10
				break;
			case 'V':
				num[i] = 5;//V-5
				break;
			case 'I':
				num[i] = 1;//I-1
				break;
			default:
				break;
		}
	}
	//������������
	for (int i = 0; i < n - 1; i++) {
		if (num[i] < num[i + 1])
			//������߱�ǰ�ߴ���ζ��Ҫ�ú����ǰ�Ҳ����ת�������ֺͼӸ�ǰ��ĸ���
			//IV ����ת���� -I+V
			res -= num[i];
		else//ǰ����ڵ��ں��ֱ�Ӽ�
			res += num[i];
	}
	res += num[n - 1];//
	return res;
}
//����ת����
string IntToChinese(int num) {
	string res = "";//�洢������
	string numstr = to_string(num); //ֱ�Ӱ�00123����ǰ���0ȥ����
	int k = numstr.length();//�洢����
	for (int i = 0; i < numstr.length(); i++) {
		int tmp = numstr[i] - '0';//tmp�洢��ǰλ�õ�����
		if (0 == tmp) {//��ǰλ��Ϊ0����һλ��Ҳ���㣬��������������һ��λ��
			if ('0' == numstr[i - 1] || i == numstr.length() - 1)
				continue;
			else
				res = res + AA[tmp];//�������Ӳ�������ת��Ϊ����
		} else {
			res = res + AA[tmp];//�������Ӳ���
			if (numstr.length() == 2 && numstr[0] == '1' && i == 0) {
				res.erase(0); //12����ʮ������1ɾ��
			}
			res = res + BB[k - i - 1];
		}
	}
	return res;
}


int main() {

	string flag;
	do {
		Menu();//�˵���ӡ
		string RomanMoney;//�洢��������
		string ChineseMoney;//�洢��������
		//������������
		cout << "������������:" << endl;
		cin.sync();//���������
		getline(cin, RomanMoney);
		//��������ת����
		int DigitMoney = RomanToInt(RomanMoney);//����ת����
		cout << DigitMoney << endl;
		ChineseMoney = IntToChinese(DigitMoney);//����ת����
		cout << "���Ľ��Ϊ:" << ChineseMoney << endl;
		cout << "�Ƿ��������(continue/quit):";
		cin >> flag;
		system("cls");//��ҳ

	} while (flag != "quit");

	return 0;

}
