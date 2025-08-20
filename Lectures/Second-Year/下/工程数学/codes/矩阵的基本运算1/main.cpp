#include <iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>//memset����
using namespace std;

void matrixAdd();//3*3����Խ���Ԫ��֮��
void matrixMultiply();//���������������
void matrixPrint(int *matrix, int row, int column); //�������������ά���鴫����ָ��

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

	cout << "������һ��3 x 3�;���" << endl;
	for (auto i = 0; i < 3; i++) {
		for (auto j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}

	//����Խ���Ԫ��֮��
	int sum = matrix[0][0] + matrix[1][1] + matrix[2][2]+matrix[0][2]+matrix[2][0];
	cout << "�������3x3�;���Խ���Ԫ��֮��Ϊ" << sum << endl;

	return;

}

void matrixMultiply() {
	int row1 = 3, column1 = 4, row2 = 4, column2 = 2;
	int matrix1[row1][column1], matrix2[row2][column2]; //matrix1Ϊ3x4�;��� matrix2Ϊ4x2�;���

	//������ɾ���
	srand((unsigned)time(NULL));//�������������
	//matrix1�����������
	for (auto i = 0; i < row1; i++) {
		for (auto j = 0; j < column1; j++) {
			matrix1[i][j] = rand() % 10;
		}
	}
	//matrix2�����������
	for (auto i = 0; i < row2; i++) {
		for (auto j = 0; j < column2; j++) {
			matrix2[i][j] = rand() % 10;
		}
	}
	//������ɾ������
	cout << "matrix1����Ϊ" << endl;
	matrixPrint(*matrix1, row1, column1);
	cout << "matrix2����Ϊ" << endl;
	matrixPrint(*matrix2, row2, column2);
	//�ж����������ܷ����
	if (column1 == row2) {
		cout << "���������ܹ����" << endl;
	}

	//�������
	int matrix3[row1][column2];
	memset(matrix3, 0, sizeof(matrix3)); //memset�������������������Ԫ�س�ʼ��Ϊ��

	for (auto i = 0; i < row1; i++) {
		for (auto j = 0; j < column2; j++) {
			for (auto k = 0; k < column1; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j]; //A(ik)*B(kj)
			}
		}
	}

	cout << "matrix3����Ϊ" << endl;
	matrixPrint(*matrix3, row1, column2);

}
