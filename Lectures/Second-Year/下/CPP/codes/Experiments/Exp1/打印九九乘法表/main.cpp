//打印九九乘法表
#include <iostream>

using namespace std;

int main() {
	for (int i = 9, row = 1; i > 0; i--, row++) { //控制竖直方向（行),row是为了便于打印每行开头的空格
		//打印每行最开头的空格
		for (int k = 1; k <= row - 1; k++) {
			cout << "\t";
		}

		//打印算式
		for (int j = i; j > 0; j--) { //控制水平方向（列）
			cout << i << "x" << j << "=" << i*j << "\t";
		}

		cout << endl;
	}

	return 0;
}
