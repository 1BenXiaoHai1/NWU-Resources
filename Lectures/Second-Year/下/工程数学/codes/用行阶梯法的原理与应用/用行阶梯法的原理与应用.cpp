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
double workOut(double (*a)[4]) { //计算矩阵行列式的值
	double n = 1;
	for (int i = 0; i < 3; i++)
		//对矩阵进行初等行变换
		//第一次：r4-nr1 r3-nr1 r2-nr1(第四行第一列、第三行第一列、第二列第一行清零)
		//第二次：r4-nr2 r3-nr2(第三行第二列、第四行第二列清零)
		//第三次：r4-nr3(第四行第三列清零)
	{
		for (int k = i + 1; k < 4; k++) { //需要修改的行数从第i+1行开始
			n = a[k][i] / a[i][i]; //比例系数n——第k行除第i行
			for (int j = 0; j < 4; j++) {
				a[k][j] = a[k][j] - n * a[i][j]; //计算第k行第j列化简后的结果
			}
		}
	}
	cout << "利用初等行变换，矩阵转变为：" << endl;
	MatrixPrint(a);
	//计算行列式的值
	double factor = 1;
	for (int i = 0; i < 4; i++) { //计算行列式的值
		factor = factor * a[i][i]; //行阶梯矩阵对角线元素乘积
	}
	return factor;
}


int main() {
	double A[4][4] = {-6, -7, 7, 6, 3, 4, 2, 3, -4, -2, 0, 6, 1, 7, 8, 3};
	double B[4][4] = {-3, 4, -2, 5, -4, -4, 4, 2, -3, 6, 1, 6, 1, 1, -1, 9};

	cout << "矩阵A为" << endl;
	MatrixPrint(A);
	double detA = workOut(A);
	cout << "A的行列式为" << detA << endl;
	cout << "矩阵B为" << endl;
	MatrixPrint(B);
	double detB = workOut(B);
	cout << "B的行列式为" << detB << endl;

	return 0;
}
