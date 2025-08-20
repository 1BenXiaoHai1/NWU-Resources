#include <iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>//memset函数
using namespace std;

void matrixAdd();//3*3矩阵对角线元素之和
void matrixMultiply();//任意两个矩阵相乘
void matrixPrint(int *matrix, int row, int column); //矩阵输出——二维数组传二重指针

int main(void) {

	matrixAdd();
	matrixMultiply();

	return 0;
}

void matrixPrint(int *matrix, int row, int column) {
	for (auto i = 0; i < row; i++) {
		for (auto j = 0; j < column; j++) {
			cout << *(matrix + i * column + j) << " ";
		}
		cout << endl;
	}
}

void matrixAdd() {
	int matrix[3][3];

	cout << "请输入一个3 x 3型矩阵" << endl;
	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}

	//计算对角线元素之和
	int sum = matrix[0][0] + matrix[1][1] + matrix[2][2]+matrix[0][2]+matrix[2][0];
	cout << "您输入的3x3型矩阵对角线元素之和为" << sum << endl;

	return;

}

void matrixMultiply() {
	int row1 = 3, column1 = 4, row2 = 4, column2 = 2;
	int matrix1[row1][column1], matrix2[row2][column2]; //matrix1为3x4型矩阵 matrix2为4x2型矩阵

	//随机生成矩阵
	srand((unsigned)time(NULL));//随机数种子生成
	//matrix1矩阵随机生成
	for (auto i = 0; i < row1; i++) {
		for (auto j = 0; j < column1; j++) {
			matrix1[i][j] = rand() % 10;
		}
	}
	//matrix2矩阵随机生成
	for (auto i = 0; i < row2; i++) {
		for (auto j = 0; j < column2; j++) {
			matrix2[i][j] = rand() % 10;
		}
	}
	//随机生成矩阵输出
	cout << "matrix1矩阵为" << endl;
	matrixPrint(*matrix1, row1, column1);
	cout << "matrix2矩阵为" << endl;
	matrixPrint(*matrix2, row2, column2);
	//判断两个矩阵能否相乘
	if (column1 == row2) {
		cout << "两个矩阵能够相乘" << endl;
	}

	//矩阵相乘
	int matrix3[row1][column2];
	memset(matrix3, 0, sizeof(matrix3)); //memset函数——将矩阵的所有元素初始化为零

	for (auto i = 0; i < row1; i++) {
		for (auto j = 0; j < column2; j++) {
			for (auto k = 0; k < column1; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j]; //A(ik)*B(kj)
			}
		}
	}

	cout << "matrix3矩阵为" << endl;
	matrixPrint(*matrix3, row1, column2);

}
