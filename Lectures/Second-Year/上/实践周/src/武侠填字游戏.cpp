#include<iostream>
#include<string>
#include<stdlib.h>
#include <cstring>
#include <ctime>
#include <cstdio>

using namespace std;

typedef struct _user{
	int account;//�˻�
	string password;//����
}User;

#define GAME "D:\\Desktop\\names.dat"
#define PLAYER "D:\\Desktop\\players.dat"
#define N 20

int menuPrint();//�˵���ӡ����
void rulePrint();//�����ӡ

void login();//��¼
void fileWrite();//������Ϸ�ļ�
int gamePlay();//��ʼ��Ϸ
void addPoint();//�ӷֺ���
void Rank();//���а�

char player_name[200];




int main(void)
{
	system("color f0");//���ñ�����ɫΪ��ɫ
	cout<<"\t\t|����������Ϸ|"<<endl<<endl;
	cout<<"��ӭ��������������Ϸ"<<endl;
	rulePrint();//�����Ϸ����
	cout<<"�����ȵ�¼"<<endl;
	login();//��¼
	while(1){
		loop:switch (menuPrint()) {
		case 0:
			gamePlay();
			break;
		case 1:
			Rank();
			break;
		case 2:
			cout<<"��ӭ�´�����";
			break;
			default:
				cout<<"The input is invaluable.Please input again."<<endl;
				goto loop;//goto�����ת�����뻷��
				break;
		}
	}

	
	system("pause");
	return 0;
}

void fileWrite()//������Ϸ�ļ�
{
	//д�ļ����̣����ļ�����д�ļ������ر��ļ�
	FILE* fp = fopen(GAME, "wb+");
	if (fp == NULL) {
		cout << "�ļ���ʧ�ܣ�";
		return;
	}
	fputs("20\n", fp);//С˵����
	
	//����
	fputs("�׷�ħŮ��,������,׿һ��,������,��ɺ��,��ʯ����\n", fp);//1
	fputs("�߽�����ɽ,��δ��,������,ð���,������,�Ż���\n", fp);//2
	fputs("Ƽ����Ӱ¼,�ŵ���,����,�̨����,��ɽ��,ʯ���\n", fp);//3
	fputs("�ƺ���Ե,������,��ʤ��,��֮��,����,����÷\n", fp);//4
	fputs("¹����,ΤС��,����,�½���,����,����\n", fp);//5
	fputs("�����˲�,����,����,����,������,���׷�\n", fp);//6
	fputs("Ц������,�����,��ӯӯ,����ɺ,��ƽ֮,����Ⱥ\n", fp);//7
	fputs("�������,���,С��Ů,½��˫,����ֹ,���ַ���\n", fp);//8
	fputs("���Ӣ�۴�,����,����,�,�����,��ҩʦ\n", fp);//9
	fputs("����������,���޼�,����,������,С��,����\n", fp);//10
	fputs("������,��Ԫƽ,����,���϶�,ŷ����,������\n", fp);//11
	fputs("�𽣵���,����,��С��,��ľ��,�����,�Ϲ���\n", fp);//12
	fputs("ˮ䰴�,�ν�,¬����,����,����ʤ,��ʤ\n", fp);//13
	fputs("�ɺ�����,�����,�����,����Ƽ,���Ʒ�,��С��\n", fp);//14
	fputs("��ϱ�,�Ʒ���,���·�,�����,������,�����\n", fp);//15
	fputs("���齣�����齣,��Ѱ��,����,��С��,���ɶ�,��׷�\n", fp);//16
	fputs("�����㴫��,������,������,�Ž��,������,����\n", fp);//17
	fputs("½С�ﴫ��,½С��,����¥,���Ŵ�ѩ,Ҷ�³�,˾��ժ��\n", fp);//18
	fputs("��������,����,Ԭ��ϼ,����,�����,����\n", fp);//19
	fputs("�������µ�,����ѩ,���Ϸ�,������,������,׿����\n", fp);//20

	
	fclose(fp);
	
}

void login()
{
	//char player_name[200]={0}, str[200]={0};
	char str[200] = { 0 };
	cout << "�������û�����";
	cin >> player_name;
	
	FILE* fp = fopen(PLAYER, "ab+");
	//PLAYER�Ĵ洢��ʽΪ��ÿ�д洢һ�����û���-������
	
	int flag = 0;
	while (fgets(str, 200, fp))
	{
		/*cout << str << endl;*/
		char getname[200] = { 0 };
		for (int k = 0, j = 0; str[k] != '-' && k < strlen(str); k++, j++) //
		{
			getname[j] = str[k];
		}
		//�ж��û��Ƿ�ע���
		if (strcmp(getname, player_name) == 0) {
			cout << "\n��ӭ������" << player_name << "\n��¼�ɹ������ڿ��Կ�ʼ��Ϸ�ˣ�\n" << endl;
			flag = 1;
			break;
		}
	}
	if (!flag)//������û�δע����������ע��
	{
		//fputs("\n", fp);
		fputs(player_name, fp);
		fputs("-0\n", fp);//��ʼ����Ϊ0
		cout << "��ӭ����" << player_name << "���������û�����Ϊ�����ע�ᣡ\n���ڿ��Կ�ʼ��Ϸ�ˣ�" << endl;
	}
	fclose(fp);
	
}

int menuPrint()
{
	cout<<"0.��ʼ��Ϸ\t1.���а�\t2.�˳���Ϸ"<<endl;
	cout<<"���������ѡ��:";
	int flag;
	cin>>flag;
	
	return flag;

}

void rulePrint()
{
	cout << "\n\n�û�ѡ��ʼ��Ϸ������ʼ����������ʾ 5 ���ı���\n"
	<< "��һ���ı�����Ϊ�����������С˵�����֣��ڶ�--�������ı�Ϊ��Ӧ����С˵����Ҫ��ɫ�����֣�\n���Ҫ�����£� \n\n"
	<< "�������ѡ��һ������С˵��������С˵���ֵĳ��ȣ����ȥ�������� 50 % ���ַ�������������Ҳ���Բ���������\n"
	<< "Ȼ���ٴ�������Ӹ�С˵�г�����Ҫ��ɫ������ѡȡ 4 ����ÿ�����������ѡ�� 1 �����á������Ŵ��棬����ʾ��С˵�����·���\n"
	<< "�û����԰���˳�������У���ѡ��ȱʧ�ı���ͼ�Σ�ͨ������ķ�ʽ��С˵���ֺ���Ҫ��ɫ���ֽ��в�ȫ��\n"
	<< "������ɺ����롰submit���������У����ߵ�����ύ����ť�ύ�𰸣�\n"
	<< "�����жϸ������Ƿ���ȷ������ȷ�����Ի�����ʾ�û���ȷ���ٴγ��⣻\n"
	<< "����ȷ�ļ�����ʾ�����ı�����ʾ�û����룬\n\n"
	<< "���δ���󣬳�����ʾ��ȷ�������ʾ�û���Ϸ���������ݴ�Դ�����ʾ�ȶ����ָ������������������˵�" << endl;
}

int gamePlay()
{
	cout<<"\t\t|��ʼ��Ϸ|"<<endl;
	//����Ϸ�����ļ������ȡ
	FILE* fp = fopen(GAME, "rb");
	char str[200] = { 0 };
	//fgets����ÿ�������ȡһ�����ݣ���ͨ��������ɶ�ȡ�ڼ��У���ʵ���ļ������ȡ
	fgets(str, 200, fp);//�ȶ�����һ�е�����N
	fgets(str, 200, fp);
	int n;
	srand((unsigned)time(NULL));//���������
	
	n = rand() % N;//���ѡ��һ������
	for (int i = 0; i < n; i++) {
		fgets(str, 200, fp);
	}//��ȡ����n��
	cout << str << endl;
	string s = str;
	string name = "";
	for (int i = 0; s[i] != ',' && i < s.length(); i++) {
		name += s[i];
	}
	cout << name << endl;//�����ǰ��ȡ����С˵����������
	
	//���ȥ���ַ�
	int len = name.length();
	string sname = name;
	string ch = "��";
	
	int visited[10] = { 0 };	//���ʱ������
	for (int i = 0; i < len / 4; i++) {	//len����4����Ϊÿ����Ҫ�滻2���ַ����ٳ���2�����滻�ַ�����һ����ַ�
		int j = rand() % (len / 4);	//���ѡ��һ��λ��
		if (visited[j]) {	//����Ƿ����滻��
			i--;
			continue;
		}
		else {
			sname = sname.replace(j * 2, 2, ch);//ÿ���滻2���ַ����ܳɹ��滻
			visited[j] = 1;//�Ѿ��滻���ı�visit��ֵ
		}
	}
	cout << sname << endl;
	//��ȡ��������
	string pname[5];
	string qname[5];//qname�����洢û���޸Ĺ���pname
	int k = len;
	for (int j = 0; j < 5; j++) { //������������pname��qname����
		k = k + 1;
		for (; s[k] != ',' && k < s.length() - 1; k++) //�趨��ΧΪlength-1��Ϊ�˲�������ĩβ�Ļس�
		{
			pname[j] += s[k];
			qname[j] += s[k];
		}
		cout << pname[j]<< " " ;
	}
	cout<<endl;
	
	n = rand() % 5;	//���ѡ��һ������ʾ��λ��
	for (int j = 0; j < 5; j++) {
		if (j != n) {
			int r = rand() % (pname[j].length() / 2);	//���ѡ��һ���ֽ��и���
			pname[j] = pname[j].replace(r * 2, 2, ch);//ÿ���滻2���ַ����ܳɹ��滻
			cout << pname[j] << endl;
		}
	}
	
	int loop = 1;//loop��������ѭ������
	while (loop > 0 && loop <= 3)
	{
		cout << "����²±��ڸǵ��֣������������������֣�����Կո���߻س��ָ�����" << endl;
		string input[5];
		for (int i = 0; i < 5; i++) {
			cin >> input[i];
		}
		int flag = 1;
		if (input[0] == name) {
			for (int i = 1, j = 0; i < 5; i++, j++) {
				if (j != n) { //nΪ����ʾ��λ��
					if (input[i] == qname[j]);
					else flag = 0;
				}
				else i--;
			}
		}
		else flag = 0;
		switch (flag)
		{
		case(0):
			if (loop < 3) cout << "����ˣ����������룡" << "�㻹��" << 3 - loop << "�λ��ᣡ\n" << endl;
			else {
				cout << "��Ļ��������ˣ��´������ɣ�" << endl;
				cout << "��ȷ�𰸣�";
				cout << name << "��";
				for (int i = 0, j = 0; i < 5; i++, j++) {
					if (j != n) { //nΪ����ʾ��λ��
						if (n == 4) {
							if (j != 3) cout << qname[i] << "��";
							else cout << qname[i] << endl;
						}
						else {
							if (j != 4) cout << qname[i] << "��";
							else cout << qname[i] << endl;
						}
					}
				}
				cout << "\n\n=====================�����������˵�...=======================\n";
				//cout << "��ѡ��\n1.��ʼ��Ϸ\n2.��Ϸ˵��\n3.���а�\n" << "����������ѡ��";
				//int r;//��¼����ֵ
				//cin >> r;
				return 0;
			}
			loop++;
			break;
		case(1):
			cout << "��ϲ�����ˣ���������һ����ɣ�\n" << endl;
			loop = 0;
			addPoint();	//����Ҽ�1��
			return 1;
			break;
		}
	}

}

void addPoint()
{
	FILE* f = fopen(PLAYER, "rb+");
	char point[200] = { 0 };//point������¼�û�����Ӧ�ķ���
	char str[200] = { 0 };
	while (fgets(str, 200, f))
	{
		char getname[200] = { 0 };
		int k = 0; int j = 0;
		for (k = 0, j = 0; str[k] != '-' && k < strlen(str); k++, j++)
		{
			getname[j] = str[k];
		}
		if (strcmp(getname, player_name) == 0) { //���ļ����ҵ��û���	
			for (k = k + 1, j = 0; str[k] != '\n' && k < strlen(str); k++, j++)
			{
				point[j] = str[k];//��point���浱ǰ�ķ���
			}
			break;
		}
	}
	int len = strlen(point);
	string p = point;
	int n = stoi(p); //�Ѵ洢���ַ����е�����ת��Ϊint
	p = std::to_string(n + 1); //��������1����ת�����ַ���
	for (int k = 0; p[k] != '\0'; k++) //���ַ������Ƶ��ַ�������
	{
		point[k] = p[k];
	}
	fseek(f, -len - 1, SEEK_CUR);
	fputs(point, f);
	
	fclose(f);
}

void Rank()//��ʾ���а�
{
	int max = 0;
	FILE* f = fopen(PLAYER, "rb+");
	char point[200] = { 0 };//point������¼��ǰ�û�����Ӧ�ķ���
	char str[200] = { 0 };
	while (fgets(str, 200, f))
	{
		int k = 0, j = 0;
		while (str[k] != '-') k++; //��λ����ǰ�û����ķ���֮ǰ
		
		for (k = k + 1, j = 0; str[k] != '\n' && k < strlen(str); k++, j++)
		{
			point[j] = str[k];//��point���浱ǰ�ķ���
		}
	}
	string p = point;
	int n = stoi(p); //�Ѵ洢���ַ����е�����ת��Ϊint
	if (n > max) max = n;
	cout << "\n==============���а�=================" << endl;
	cout << "\n��ǰ���в�����Ϸ�û�����߷�Ϊ��" << max << endl;
	cout << "\n......" << endl;
	cout << "\n��������������˵�\n" << endl;
	getchar();
	getchar();
	fclose(f);
}
