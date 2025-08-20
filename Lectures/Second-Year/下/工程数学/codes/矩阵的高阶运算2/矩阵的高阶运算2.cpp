#include<iostream>
#include<ctime>
#include<windows.h>

using namespace std;

//相乘
void matrixMul(int (*A)[4], int (*B)[4], int (*AB)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				AB[i][j] += A[i][k] * B[k][j]; //A(ik)*B(kj)
			}
		}
	}

	return;
}
//相加
void matrixAdd(int (*A)[4], int (*B)[4], int (*ApB)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ApB[i][j] = A[i][j] + B[i][j];
		}
	}
	return;
}

//相减
void matrixSub(int (*A)[4], int (*B)[4], int (*AsB)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			AsB[i][j] = A[i][j] - B[i][j];
		}
	}
	return;
}

//打印
void matrixPrint(int (*A)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

//矩阵生成
void matrixInit(int (*A)[4]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			A[i][j] = rand() % 5;
		}
	}
}

void matrix_EInit(int (*A)[4]) {
	for (int i = 0; i < 4; i++) {
		A[i][i] = 1;
	}
}

void test() {
	int A[4][4] = {0};
	int I[4][4] = {0};
	//矩阵初始化
	matrixInit(A);
	matrix_EInit(I);
	cout << "生成的4x4矩阵A为" << endl;
	matrixPrint(A);
	cout << "生成的单位阵I为" << endl;
	matrixPrint(I);
	//计算(A+I)(A-I)
	//计算A+I和A-I
	int ApI[4][4] = {0}, AsI[4][4] = {0};
	matrixAdd(A, I, ApI);
	matrixSub(A, I, AsI);
	int ApIAsI[4][4] = {0};
	matrixMul(ApI, AsI, ApIAsI); //计算矩阵相乘
	cout << "(A+I)(A-I)为" << endl;
	matrixPrint(ApIAsI);
	//计算A^2-I
	int AA[4][4] = {0}, AAsI[4][4] = {0};
	matrixMul(A, A, AA);
	matrixSub(AA, I, AAsI);
	cout << "A^2-I为" << endl;
	matrixPrint(AAsI);
	//计算左减右
	int LsR[4][4] = {0};
	matrixSub(ApIAsI, AAsI, LsR);
	cout << "左减右为" << endl;
	matrixPrint(LsR);

	return;
}

int main() {
	for (int i = 0; i < 3; i++) {
		system("color 70");//设置背景色为白色
		SetConsoleTitle("矩阵的高阶运算2");
		cout << "\n---------测试" << i + 1 << "---------" << endl;
		test();
		//cmd翻页
		system("pause");
		system("cls");
	}

	return 0;
}
