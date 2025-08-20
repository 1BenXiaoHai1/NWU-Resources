#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//¼ÆËãĞĞÁĞÊ½(3½×)
int det(int a[][3]) {
	int result = 0;
	result = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1] - a[0][0] * a[1][2] * a[2][1] - a[0][1] * a[1][0] * a[2][2] - a[0][2] * a[1][1] * a[2][0];

	return result;

}
int main() {
	srand(time(NULL));
	int A[3][3] = {0}, B[3][3] = {0};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			A[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			B[i][j] = rand() % 100;
		}

	}
	cout << "A is:" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "B is:" << endl;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}

	int sum[3][3] = {0};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			sum[i][j] = A[i][j] + B[i][j];
		}

	}
	cout << "sum is " << endl;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}

	int detA_B = 0;
	detA_B = det(sum);

	int deta = 0, detb = 0;
	deta = det(A);
	detb = det(B);
	if (detA_B == deta + detb) {
		cout << "det(A+B)=det(A)+det(B)" << endl;
	}
	else
		cout << "det(A+B)!=det(A)+det(B)" << endl;
	if (detA_B == deta * detb) {
		cout << "det(A+B)=det(A)det(B)" << endl;
	}

	else
		cout << "det(A+B)!=det(A)det(B)" << endl;

	int A_[3][3] = {0};
	//°éËæ¾ØÕó¼ÆËã
	A_[0][0] = A[1][1] * A[2][2] - A[1][2] * A[2][1];
	A_[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]);
	A_[0][2] = A[0][1] * A[1][2] - A[0][2] * A[1][1];
	A_[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]);
	A_[1][1] = A[0][0] * A[2][2] - A[0][2] * A[2][0];
	A_[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]);
	A_[2][0] = A[1][0] * A[2][1] - A[1][1] * A[2][0];
	A_[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]);
	A_[2][2] = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	//ÇóÄæ¾ØÕó
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			A_[i][j] = A_[i][j] / det(A);
		}

	}
	int x = 1 / det(A);
	if (det(A_) == x) {
		cout << "det(A)-1=(det(A))-1" << endl;
	}
	else
		cout << "det(A)-1!=(det(A))-1" << endl;
}
