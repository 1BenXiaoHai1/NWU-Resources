#include<iostream>
#include<fstream>
#include<time.h>
#include<cstdlib>

using namespace std;

enum StoneStatus {UP, DOWN}; //ʯͷ״̬

int main() {
	
	ofstream fout("text.txt");//�ѷŷ�����д���ļ���
	int members[50] = {0};//50����Ա��0����û�����ƣ�1�������ƣ�
	int daysCnt = 0;
	int Master = 49;//�ٶ����һ����Ϊ�峤
	StoneStatus stone = UP ;//�ʼʯͷ����
	int AlivePerson = 1;//�峤�ػ��ţ�����ֻ���ж�����49�����Ƿ����

	while (AlivePerson!=49) {
		//���������
		time_t t;
		srand((unsigned)time(&t));//���������
		int OutPerson = int(rand() % (49 - 0 + 1)) + 0; //�����һ���˳�ȥ���磨���ɷ�ΧΪ0-49�����֣�
		//����ɳ�ȥ�������Ϊ�峤
		if (OutPerson == Master) {
			if (stone == UP) { //���ʯͷ���ϣ�˵��û�˳������磬���ʯͷ����ԭ�����ϵ�״̬
				daysCnt++;//����+1
//				fout<<"No one out"<<endl;
			} else { //ʯͷ���£�˵�����˳������硣ʯͷ�����ˣ�������һ�˻���
				daysCnt++;//����+1
				stone = UP;//��ʯͷ��down��Ϊup
				AlivePerson++;//��������1
				if (AlivePerson == 50) {//��������
					fout << "�����˾����ţ��ж������˾����ŵ�����Ϊ" << daysCnt << endl;
					cout << "�����˾����ţ��ж������˾����ŵ�����Ϊ" << daysCnt << endl;
					break;
				} else {//������������
					continue;
				}
			}
		} else { //������˲��Ǵ峤
			if (stone == UP) { //������ϣ�˵����û���˷���ʯͷ��������Է�ʯͷ
				daysCnt++;//����+1
				if (members[OutPerson] == 0) { //���û����ʯͷ������Է�ʯͷ
					stone = DOWN;//�Ӵ峤��UP״̬����DOWN״̬
					members[OutPerson] = 1;//�޸Ĵ���״̬���ѷ���ʯͷ
					fout<<OutPerson + 1<<"turns up to down"<<endl;
				} else { //����ʯͷ�Ͳ�Ҫ��ʯͷ����ͳ�ƹ���
					continue;
				}
			} else { //DOWN�Ͳ�Ҫ��
				daysCnt++;//����+1
				continue;
			}

		}
	}


	return 0;
}
