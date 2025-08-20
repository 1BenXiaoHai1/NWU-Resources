#include<iostream>

using namespace std;

void menuPrint();//菜单打印函数
void login();
void gamePlay();//开始游戏
void gameEnd();//结束游戏
void rank();

int main(void)
{
	menuPrint();
	
	
	return 0;
}

void menuPrint()
{
	cout<<"欢迎来到武侠填字游戏"<<endl<<"请选择你的选项:"<<endl;
	cout<<"0.开始游戏\t1.排行榜\t2.退出游戏"<<endl;
}
