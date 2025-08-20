#include<iostream>
#include<cstdlib>
#include<cmath>
#define MaxSize 20//最高位20阶矩阵

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
//使用高斯消元法对矩阵进行求逆(初等变换法)
void Gaussian_elimination(int sizeM, double a[MaxSize][MaxSize]) {
	int i, j, k;
	double W[sizeM][2 * sizeM], result[sizeM][sizeM];
	double tem_1, tem_2, tem_3;

	// 对矩阵右半部分进行扩增——增广矩阵
	for (i = 0; i < sizeM; i++) {
		for (j = 0; j < 2 * sizeM; j++) {
			if (j < sizeM) {
				W[i][j] =  a[i][j];
			} else {
				//补充的矩阵为sizeM阶单位阵
				W[i][j] =  (j - sizeM == i ? 1 : 0);
			}
		}
	}

	for (i = 0; i < sizeM; i++) {
		// 判断矩阵第一行第一列的元素是否为0，若为0，继续判断第二行第一列元素，直到不为0，将其加到第一行
		if ( ((int) W[i][i]) == 0) {
			for (j = i + 1; j < sizeM; j++) {
				if ( ((int) W[j][i]) != 0 ) break;
			}
			if (j == sizeM) {
				cout << "这个矩阵不能求逆矩阵" << endl;
				break;
			}
			//将前面为0的行加上后面某一行
			for (k = 0; k < 2 * sizeM; k++) {
				W[i][k] += W[j][k];
			}
		}

		//将前面行首位元素置1
		tem_1 = W[i][i];
		for (j = 0; j < 2 * sizeM; j++) {
			W[i][j] = W[i][j] / tem_1;
		}

		//将后面所有行首位元素置为0
		for (j = i + 1; j < sizeM; j++) {
			tem_2 = W[j][i];
			for (k = i; k < 2 * sizeM; k++) {
				W[j][k] = W[j][k] - tem_2 * W[i][k];
			}
		}
	}

	// 将矩阵前半部分标准化
	for (i = sizeM - 1; i >= 0; i--) {
		for (j = i - 1; j >= 0; j--) {
			tem_3 = W[j][i];
			for (k = i; k < 2 * sizeM; k++) {
				W[j][k] = W[j][k] - tem_3 * W[i][k];
			}
		}
	}

	//得出逆矩阵
	for (i = 0; i < sizeM; i++) {
		for (j = sizeM; j < 2 * sizeM; j++) {
			result[i][j - sizeM] = W[i][j];
		}
	}

	cout << "逆矩阵为" << endl;
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
