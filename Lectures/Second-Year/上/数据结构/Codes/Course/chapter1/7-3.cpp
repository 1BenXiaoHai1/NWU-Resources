#include<iostream>
using namespace std;

typedef struct _polynomia {
	int coefficient[100] = {0}; //系数
	int X[100] = {0}; //幂次矩阵

} Polynomia;

void Sum(Polynomia &Res, Polynomia  a, Polynomia  b) {
	//根据幂次是否存在进行判断系数计算
	//幂次
	for (int i = 0; i < 100; i++) {
		if (a.X[i] == 1 && b.X[i] == 1) { //a、b该位置系数均存在
			Res.X[i] = 1; //求和后的多项式该幂次存在
			Res.coefficient[i] = a.coefficient[i] + b.coefficient[i]; //系数等于a、b之和
		} else if (a.X[i] == 1 && b.X[i] != 1) { //a存在,b不存在
			Res.X[i] = 1;
			Res.coefficient[i] = a.coefficient[i];
		} else if (a.X[i] != 1 && b.X[i] == 1) { //a不存在,b存在
			Res.X[i] = 1;
			Res.coefficient[i] = b.coefficient[i];
		} else { //都不存在
			continue;
		}
	}
}

int main() {
	Polynomia a, b;
	//输入
	//a
	int a_coe = 0, a_x = 0;
	cin >> a_x >> a_coe;
	while (!(a_coe == -1 && a_x == -1)) {
		if (a_coe == 0 || a_x < 0) {
			continue;
		}
		a.X[a_x] = 1; //该幂次存在
		a.coefficient[a_x] = a_coe; //保存对应系数——对应幂次位置
		cin >> a_x >> a_coe;
	}
	//b
	int b_coe = 0, b_x = 0;
	cin >> b_x >> b_coe;
	while (!(b_coe == -1 && b_x == -1)) {
		if (b_coe == 0 && b_x < 0) {
			continue;
		}
		b.X[b_x] = 1; //该幂次存在
		b.coefficient[b_x] = b_coe; //保存对应系数——对应幂次位置
		cin >> b_x >> b_coe;
	}
	//求和
	Polynomia Res;
	Sum(Res, a, b);
	//输出第一个高次幂
	int pos = 0;
	for (int i = 99; i >= 0; i--) {
		if (Res.X[i] != 0) {
			if (i != 0 && i != 1) {
				pos = i;
				cout << Res.coefficient[i] << "x" << i ;
				break;
			} else if (i == 1) {
				pos = i;
				cout << Res.coefficient[i] << "x";
				break;
			} else {
				cout << Res.coefficient[i];//只有常数项
				return 0;
			}
		}

	}
	//输出后面的数据
	for (int i = pos - 1; i >= 0; i--) {
		if (Res.X[i] != 0) { //幂次存在
			if (i != 0 && i != 1) {
				if (Res.coefficient[i] < 0) { //负数
					cout << "-" << Res.coefficient[i] << "x" << i ;
				} else if (Res.coefficient[i] > 0) {
					cout << "+" << Res.coefficient[i] << "x" << i ;
				} else {
					continue;
				}
			} else if (i == 1) {
				if (Res.coefficient[i] < 0) { //负数
					cout << "-" << Res.coefficient[i] << "x" ;
				} else if (Res.coefficient[i] > 0) {
					cout << "+" << Res.coefficient[i] << "x";
				} else {
					continue;
				}
			} else {
				if (Res.coefficient[i] < 0) { //负数
					cout << "-" << Res.coefficient[i];
				} else if (Res.coefficient[i] > 0) {
					cout << "+" << Res.coefficient[i];
				} else {
					continue;
				}

			}

		}
	}


	return 0;
}
