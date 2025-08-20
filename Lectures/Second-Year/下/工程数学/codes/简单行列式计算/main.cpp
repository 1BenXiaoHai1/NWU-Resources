//简单行列式计算
//输入三阶行列式 输出其行列式的值
#include<iostream>

using namespace std;

int main() {
	int Det[3][3];//定义一个二维数组 用来存放输入的行列式
	int det = 0;

	//行列式的输入
	cout << "请输入一个三阶行列式：" << endl;

	for (int i = 0; i < 3; i++) { //行数
		for (int j = 0; j < 3; j++) { //列数
			cin >> Det[i][j];
		}
	}

	//行列式计算(低阶行列式(二阶三阶)——玫瑰线法则)
	det = Det[0][0] * Det[1][1] * Det[2][2] + Det[0][1] * Det[1][2] * Det[2][0] + Det[1][0] * Det[2][1] * Det[0][2] - (Det[2][0] * Det[1][1] * Det[0][2] + Det[1][0] * Det[0][1] * Det[2][2] + Det[0][0] * Det[1][2] * Det[2][1]);

	//行列式值的输出
	cout << "所输入行列式的值为：" << det << endl;

	return 0;
}
