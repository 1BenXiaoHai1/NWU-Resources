//行列式与高阶行列式计算
//实现三对角行列式计算
#include <iostream>

using namespace std;

int detCalculate(int n, int a, int b, int c); //行列式计算函数

int main(void) {

	int n;//三对角行列式的阶数

	int a, b, c; //三对角行列式各元素的值

	cout << "请输入所计算三对角行列式的阶数：" ;
	cin >> n;
	cout << "请输入主对角元素a的值：";
	cin >> a ;
	cout << "请输入上对角线元素b的值：";
	cin >> b;
	cout << "请输入下对角线元素c的值：";
	cin >> c;

	//行列式计算
	int det = detCalculate(n, a, b, c);

	cout << "所求" << n << "阶行列式的值为" << det << endl;

	return 0;
}

/*算法思路
	对三对角行列式按行化简得递归公式，因此行列式的计算可以采用递归计算。
*/
int detCalculate(int n, int a, int b, int c) {
	if (n == 1 || n == 2) { //终止条件有两个n=1、n=2
		//终止条件二者的返回值不同 因此需要进行判断
		if (n == 1) {
			return a;//返回一阶行列式计算值
		} else {
			return a * a - b * c; //返回二阶行列式计算值
		}
	} else {
		return a * detCalculate(n - 1, a, b, c) - b * c * detCalculate(n - 2, a, b, c);//递归公式
	}
}
