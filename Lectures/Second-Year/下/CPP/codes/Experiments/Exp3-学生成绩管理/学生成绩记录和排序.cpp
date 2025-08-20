#include<iostream>
#include<string>
#include<vector>
#include<windows.h>//�޸Ŀ���̨
using namespace std;

enum Gender {Male, Female}; //�����Ա�ö������

typedef struct _student {
	string name;
	string sno;
	int score[3];//����
	Gender sex;
	int sum;//�ܷ�
	_student * pnext;//�ṹ��ָ��
} Student, *StudentLink; //ѧ����� ָ��ѧ���ڵ�Ľṹ��ָ��

void Menu()
{
	system("color 70");
	SetConsoleTitle("ѧ���ɼ�����ϵͳ");
	cout<<"\n-----------ѧ���ɼ�����ϵͳ------------\n\n";
	cout<<"��ӭ����ѧ���ɼ�����ϵͳ��ϵͳ���ܾ�������"<<endl;
	cout<<"[0]ѧ����Ϣ����"<<endl;
	cout<<"[1]�鿴�������ѧ��"<<endl;
	cout<<"[2]�ɼ�����"<<endl;
	cout<<"[3]�˳�����"<<endl;
	
	return;
}

int conti()
{
	cout<<"\n�Ƿ������Y/N��:"<<endl;
	char flag;
	cin>>flag;
	int a = 0;
	if(flag=='Y'){
		a = 1;
	}
	
	return a;
}

StudentLink CreateLink() { //����ѧ������
	//��������ʼ��һ��ͷָ��
	StudentLink stu;
	stu = new Student;//C++ʹ��new��̬�����ڴ�
	if (stu == NULL) {
		cout << "����ʧ��" << endl;
		return 0;
	}
	stu->pnext = NULL;

	return stu;

}

StudentLink StudentInsert(StudentLink stu){
	cout<<"\n-------------ѧ����Ϣ����--------------\n\n";
	//����ѧ����Ϣ(����ѧ����㡢����ѧ����Ϣ�������н������)
	//β�巨
	StudentLink pTail = stu;
	pTail->pnext=NULL ;
	cout<<"������ѧ������"<<endl;
	int studentNum;
	cin>>studentNum;
	for(int i=0;i<studentNum;i++){
		StudentLink newStu = new Student;
		newStu->pnext=NULL;
		cout<<"������ѧ������:";
		cin>>newStu->name;
		cout<<"������ѧ��ѧ��:";
		cin>>newStu->sno;
		int sexn;
		cout<<"������ѧ���Ա�0-Male/1-Female��:";
		cin>>sexn;
		newStu->sex=(Gender)sexn;
		cout<<"�������ĿA����ĿB����ĿC�ɼ�:";
		cin>>newStu->score[0];
		cin>>newStu->score[1];
		cin>>newStu->score[2];
		//���������ܷ�
		newStu->sum=newStu->score[0]+newStu->score[1]+newStu->score[2];
		//�������������
		pTail->pnext = newStu;//�����½���ѧ�������ԭ������������
		pTail = newStu;//�ƶ�pTail	
	}
	
	return stu;

}

void StudentLowerSort(StudentLink stu) {
	cout<<"\n-------------�ɼ�����--------------\n\n";
	//ð�����򡪡��������
	StudentLink pre, cur, next, ptail;
	ptail = NULL;

	while (stu->pnext != ptail) {
		//��ʼ������ָ�� ; �ж��Ƿ񵽴����λ�� ; ����ָ�뼯�����
		for (pre = stu, cur = pre->pnext, next = cur->pnext;  next != ptail;  pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
			if (cur->sum > next->sum) { //��С����
				pre->pnext = next;
				cur->pnext = next->pnext;
				next->pnext = cur;

				//��ʱnext��ǰһ�cur���һ��  ����next cur
				StudentLink temp = cur;
				cur = next;
				next = temp;
			}
		}

		//һ��ѭ������ ���һ���Ѿ��ź� end��ǰһ�� (ð��ԭ��)
		ptail = cur;
	}


}

void StudentFailed(StudentLink stu){
	cout<<"\n-------------�鿴�������ѧ��--------------\n\n";
	StudentLink p = stu->pnext;
	//��ӡ������ɼ���ѧ������Ӧ��Ŀ
	cout<<"\t\t\t������ѧ��"<<endl;
	cout<<"����\tѧ��\t\t�������Ŀ\t�ɼ�"<<endl;
	while(p){
		if(p->score[0]<60||p->score[1]<60||p->score[2]<60){
			if(p->score[0]<60){
				cout<<p->name<<"\t"<<p->sno<<"\t\tA\t"<<p->score[0]<<endl;
			} 
			if(p->score[1]<60){
				cout<<p->name<<"\t"<<p->sno<<"\t\tB\t"<<p->score[1]<<endl;
			}
			if(p->score[2]<60){
				cout<<p->name<<"\t"<<p->sno<<"\t\tC\t"<<p->score[2]<<endl;
			}
		}
		p=p->pnext;//�ƶ�p
	}
}

void StudentPrint(StudentLink stu) { //ѧ����Ϣ��ӡ
	StudentLink p = stu->pnext;//����һ��ָ��(ͷ���)

	//��ӡ
	cout <<endl<< "\t\t\tѧ���ɼ�����" << endl;
	cout << "����\tѧ��\t\t�Ա�\t��ĿA\t��ĿB\t��ĿC\t�ܷ�" << endl;
	while (p) {
		cout << p->name << "\t" << p->sno << "\t";
		if (p->sex == 0) {
			cout << "Male\t";
		} else {
			cout << "Female\t";
		}
		cout << p->score[0] << "\t" << p->score[1] << "\t" << p->score[2] << "\t" << p->sum << endl;
		p = p->pnext;//�ƶ�p
	}
}

int main() {
	StudentLink stu;//����һ��ѧ��������ͷָ��
	int flag = 1;
	
	stu = CreateLink();//��������
	Menu();
	while(flag){
		loop:
			cout<<"���������ѡ��:";
			int choice;
			cin>>choice;
			switch (choice) {
			case 0:
				StudentInsert(stu);
				flag = conti();
				break;	
			case 1:
				StudentFailed(stu);
				flag = conti();
				break;
			case 2:
				StudentLowerSort(stu);
				StudentPrint(stu);
				flag = conti();
				break;
			case 3:
				cout<<"��ӭ�´�ʹ��"<<endl;
				flag = 0;
				break;
				default:
					cout<<"������������������";
					goto loop;
					break;
			}
	}

	return 0;
}
