/*
 * ex5_8.cpp
 *
 *  8. 编写程序hello，对命令行输入的一个或多个名字显示问候语。
 *  例如：命令行输入：hello Ron
 *  则输出为：Hello Ron!
 *  如果输入：hello Harry Ron Hermione
 *  则输出：Hello Harry！
 *  Hello Ron！
 *  Hello Hermione！
 *  提示：使用带参数的main()函数实现。
 *
 */


#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	if(argc <=1)
	{
		cout<<"wrong argument number"<<endl;
		exit(1);
	}
	int n = 1;
	while(n < argc){
		cout<<"Hello,"<<argv[n]<<"!"<<endl;
		n++;
	}
}
