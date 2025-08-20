#include<iostream>
#include<cstdlib>
#include<cmath>
#define MaxSize 20//���λ20�׾���

using namespace std;

void MatrixCreate(int sizeM, double a[MaxSize][MaxSize]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < sizeM; i++) {
		for (int j = 0; j < sizeM; j++) {
			a[i][j] = rand() % 5;
		}
	}
}

void MatrixPrint(int sizeM, double a[MaxSize][MaxSize]) {
	for (int i = 0; i < sizeM; i++) {
		for (int j = 0; j < sizeM; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}
//ʹ�ø�˹��Ԫ���Ծ����������(���ȱ任��)
void Gaussian_elimination(int sizeM, double a[MaxSize][MaxSize]) {
	int i, j, k;
	double W[sizeM][2 * sizeM], result[sizeM][sizeM];
	double tem_1, tem_2, tem_3;

	// �Ծ����Ұ벿�ֽ������������������
	for (i = 0; i < sizeM; i++) {
		for (j = 0; j < 2 * sizeM; j++) {
			if (j < sizeM) {
				W[i][j] =  a[i][j];
			} else {
				//����ľ���ΪsizeM�׵�λ��
				W[i][j] =  (j - sizeM == i ? 1 : 0);
			}
		}
	}

	for (i = 0; i < sizeM; i++) {
		// �жϾ����һ�е�һ�е�Ԫ���Ƿ�Ϊ0����Ϊ0�������жϵڶ��е�һ��Ԫ�أ�ֱ����Ϊ0������ӵ���һ��
		if ( ((int) W[i][i]) == 0) {
			for (j = i + 1; j < sizeM; j++) {
				if ( ((int) W[j][i]) != 0 ) break;
			}
			if (j == sizeM) {
				cout << "����������������" << endl;
				break;
			}
			//��ǰ��Ϊ0���м��Ϻ���ĳһ��
			for (k = 0; k < 2 * sizeM; k++) {
				W[i][k] += W[j][k];
			}
		}

		//��ǰ������λԪ����1
		tem_1 = W[i][i];
		for (j = 0; j < 2 * sizeM; j++) {
			W[i][j] = W[i][j] / tem_1;
		}

		//��������������λԪ����Ϊ0
		for (j = i + 1; j < sizeM; j++) {
			tem_2 = W[j][i];
			for (k = i; k < 2 * sizeM; k++) {
				W[j][k] = W[j][k] - tem_2 * W[i][k];
			}
		}
	}

	// ������ǰ�벿�ֱ�׼��
	for (i = sizeM - 1; i >= 0; i--) {
		for (j = i - 1; j >= 0; j--) {
			tem_3 = W[j][i];
			for (k = i; k < 2 * sizeM; k++) {
				W[j][k] = W[j][k] - tem_3 * W[i][k];
			}
		}
	}

	//�ó������
	for (i = 0; i < sizeM; i++) {
		for (j = sizeM; j < 2 * sizeM; j++) {
			result[i][j - sizeM] = W[i][j];
		}
	}

	cout << "�����Ϊ" << endl;
	cout.precision(3);
	for (i = 0; i < sizeM; i++) {
		for (j = 0; j < sizeM; j++) {

			cout << result[i][j] << '\t';
		}
		cout << endl;
	}


}

int main() {
	double a[MaxSize][MaxSize] = {0};

	MatrixCreate(4, a);
	MatrixPrint(4, a);
	Gaussian_elimination(4, a);

	return 0;
}
