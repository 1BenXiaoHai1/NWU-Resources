#include<iostream>

using namespace std;

void menuPrint();//�˵���ӡ����
void login();
void gamePlay();//��ʼ��Ϸ
void gameEnd();//������Ϸ
void rank();

int main(void)
{
	menuPrint();
	
	
	return 0;
}

void menuPrint()
{
	cout<<"��ӭ��������������Ϸ"<<endl<<"��ѡ�����ѡ��:"<<endl;
	cout<<"0.��ʼ��Ϸ\t1.���а�\t2.�˳���Ϸ"<<endl;
}
