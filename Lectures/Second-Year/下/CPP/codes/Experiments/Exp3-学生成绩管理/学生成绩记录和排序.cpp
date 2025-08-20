#include<iostream>
#include<string>
#include<vector>
#include<windows.h>//修改控制台
using namespace std;

enum Gender {Male, Female}; //定义性别枚举类型

typedef struct _student {
	string name;
	string sno;
	int score[3];//分数
	Gender sex;
	int sum;//总分
	_student * pnext;//结构体指针
} Student, *StudentLink; //学生结点 指向学生节点的结构体指针

void Menu()
{
	system("color 70");
	SetConsoleTitle("学生成绩管理系统");
	cout<<"\n-----------学生成绩管理系统------------\n\n";
	cout<<"欢迎来到学生成绩管理系统，系统功能具体如下"<<endl;
	cout<<"[0]学生信息插入"<<endl;
	cout<<"[1]查看不及格的学生"<<endl;
	cout<<"[2]成绩排名"<<endl;
	cout<<"[3]退出程序"<<endl;
	
	return;
}

int conti()
{
	cout<<"\n是否继续（Y/N）:"<<endl;
	char flag;
	cin>>flag;
	int a = 0;
	if(flag=='Y'){
		a = 1;
	}
	
	return a;
}

StudentLink CreateLink() { //创建学生链表
	//创建并初始化一个头指针
	StudentLink stu;
	stu = new Student;//C++使用new动态分配内存
	if (stu == NULL) {
		cout << "创建失败" << endl;
		return 0;
	}
	stu->pnext = NULL;

	return stu;

}

StudentLink StudentInsert(StudentLink stu){
	cout<<"\n-------------学生信息插入--------------\n\n";
	//插入学生信息(创建学生结点、插入学生信息、并进行结点连接)
	//尾插法
	StudentLink pTail = stu;
	pTail->pnext=NULL ;
	cout<<"请输入学生数量"<<endl;
	int studentNum;
	cin>>studentNum;
	for(int i=0;i<studentNum;i++){
		StudentLink newStu = new Student;
		newStu->pnext=NULL;
		cout<<"请输入学生姓名:";
		cin>>newStu->name;
		cout<<"请输入学生学号:";
		cin>>newStu->sno;
		int sexn;
		cout<<"请输入学生性别（0-Male/1-Female）:";
		cin>>sexn;
		newStu->sex=(Gender)sexn;
		cout<<"请输入科目A、科目B、科目C成绩:";
		cin>>newStu->score[0];
		cin>>newStu->score[1];
		cin>>newStu->score[2];
		//计算三科总分
		newStu->sum=newStu->score[0]+newStu->score[1]+newStu->score[2];
		//结点与链表连接
		pTail->pnext = newStu;//将该新建的学生结点与原链表连接起来
		pTail = newStu;//移动pTail	
	}
	
	return stu;

}

void StudentLowerSort(StudentLink stu) {
	cout<<"\n-------------成绩排名--------------\n\n";
	//冒泡排序——交换结点
	StudentLink pre, cur, next, ptail;
	ptail = NULL;

	while (stu->pnext != ptail) {
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = stu, cur = pre->pnext, next = cur->pnext;  next != ptail;  pre = pre->pnext, cur = cur->pnext, next = next->pnext) {
			if (cur->sum > next->sum) { //从小到大
				pre->pnext = next;
				cur->pnext = next->pnext;
				next->pnext = cur;

				//此时next变前一项，cur变后一项  交换next cur
				StudentLink temp = cur;
				cur = next;
				next = temp;
			}
		}

		//一轮循环结束 最后一项已经排好 end提前一项 (冒泡原理)
		ptail = cur;
	}


}

void StudentFailed(StudentLink stu){
	cout<<"\n-------------查看不及格的学生--------------\n\n";
	StudentLink p = stu->pnext;
	//打印不及格成绩的学生即对应科目
	cout<<"\t\t\t不及格学生"<<endl;
	cout<<"姓名\t学号\t\t不及格科目\t成绩"<<endl;
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
		p=p->pnext;//移动p
	}
}

void StudentPrint(StudentLink stu) { //学生信息打印
	StudentLink p = stu->pnext;//定义一个指针(头结点)

	//打印
	cout <<endl<< "\t\t\t学生成绩排名" << endl;
	cout << "姓名\t学号\t\t性别\t科目A\t科目B\t科目C\t总分" << endl;
	while (p) {
		cout << p->name << "\t" << p->sno << "\t";
		if (p->sex == 0) {
			cout << "Male\t";
		} else {
			cout << "Female\t";
		}
		cout << p->score[0] << "\t" << p->score[1] << "\t" << p->score[2] << "\t" << p->sum << endl;
		p = p->pnext;//移动p
	}
}

int main() {
	StudentLink stu;//创建一个学生链表——头指针
	int flag = 1;
	
	stu = CreateLink();//创建链表
	Menu();
	while(flag){
		loop:
			cout<<"请输入你的选择:";
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
				cout<<"欢迎下次使用"<<endl;
				flag = 0;
				break;
				default:
					cout<<"输入有误，请重新输入";
					goto loop;
					break;
			}
	}

	return 0;
}
