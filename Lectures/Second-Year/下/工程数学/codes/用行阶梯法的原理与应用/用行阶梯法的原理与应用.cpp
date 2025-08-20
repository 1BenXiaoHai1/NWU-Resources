#include<iostream>

using namespace std;

void MatrixPrint(double (*a)[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
double workOut(double (*a)[4]) { //�����������ʽ��ֵ
	double n = 1;
	for (int i = 0; i < 3; i++)
		//�Ծ�����г����б任
		//��һ�Σ�r4-nr1 r3-nr1 r2-nr1(�����е�һ�С������е�һ�С��ڶ��е�һ������)
		//�ڶ��Σ�r4-nr2 r3-nr2(�����еڶ��С������еڶ�������)
		//�����Σ�r4-nr3(�����е���������)
	{
		for (int k = i + 1; k < 4; k++) { //��Ҫ�޸ĵ������ӵ�i+1�п�ʼ
			n = a[k][i] / a[i][i]; //����ϵ��n������k�г���i��
			for (int j = 0; j < 4; j++) {
				a[k][j] = a[k][j] - n * a[i][j]; //�����k�е�j�л����Ľ��
			}
		}
	}
	cout << "���ó����б任������ת��Ϊ��" << endl;
	MatrixPrint(a);
	//��������ʽ��ֵ
	double factor = 1;
	for (int i = 0; i < 4; i++) { //��������ʽ��ֵ
		factor = factor * a[i][i]; //�н��ݾ���Խ���Ԫ�س˻�
	}
	return factor;
}


int main() {
	double A[4][4] = {-6, -7, 7, 6, 3, 4, 2, 3, -4, -2, 0, 6, 1, 7, 8, 3};
	double B[4][4] = {-3, 4, -2, 5, -4, -4, 4, 2, -3, 6, 1, 6, 1, 1, -1, 9};

	cout << "����AΪ" << endl;
	MatrixPrint(A);
	double detA = workOut(A);
	cout << "A������ʽΪ" << detA << endl;
	cout << "����BΪ" << endl;
	MatrixPrint(B);
	double detB = workOut(B);
	cout << "B������ʽΪ" << detB << endl;

	return 0;
}
