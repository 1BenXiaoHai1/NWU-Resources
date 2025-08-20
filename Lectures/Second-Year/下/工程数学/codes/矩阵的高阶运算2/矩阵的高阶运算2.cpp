#include<iostream>
#include<ctime>
#include<windows.h>

using namespace std;

//���
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
//���
void matrixAdd(int (*A)[4], int (*B)[4], int (*ApB)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			ApB[i][j] = A[i][j] + B[i][j];
		}
	}
	return;
}

//���
void matrixSub(int (*A)[4], int (*B)[4], int (*AsB)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			AsB[i][j] = A[i][j] - B[i][j];
		}
	}
	return;
}

//��ӡ
void matrixPrint(int (*A)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

//��������
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
	//�����ʼ��
	matrixInit(A);
	matrix_EInit(I);
	cout << "���ɵ�4x4����AΪ" << endl;
	matrixPrint(A);
	cout << "���ɵĵ�λ��IΪ" << endl;
	matrixPrint(I);
	//����(A+I)(A-I)
	//����A+I��A-I
	int ApI[4][4] = {0}, AsI[4][4] = {0};
	matrixAdd(A, I, ApI);
	matrixSub(A, I, AsI);
	int ApIAsI[4][4] = {0};
	matrixMul(ApI, AsI, ApIAsI); //����������
	cout << "(A+I)(A-I)Ϊ" << endl;
	matrixPrint(ApIAsI);
	//����A^2-I
	int AA[4][4] = {0}, AAsI[4][4] = {0};
	matrixMul(A, A, AA);
	matrixSub(AA, I, AAsI);
	cout << "A^2-IΪ" << endl;
	matrixPrint(AAsI);
	//���������
	int LsR[4][4] = {0};
	matrixSub(ApIAsI, AAsI, LsR);
	cout << "�����Ϊ" << endl;
	matrixPrint(LsR);

	return;
}

int main() {
	for (int i = 0; i < 3; i++) {
		system("color 70");//���ñ���ɫΪ��ɫ
		SetConsoleTitle("����ĸ߽�����2");
		cout << "\n---------����" << i + 1 << "---------" << endl;
		test();
		//cmd��ҳ
		system("pause");
		system("cls");
	}

	return 0;
}
