//����ʽ��߽�����ʽ����
//ʵ�����Խ�����ʽ����
#include <iostream>

using namespace std;

int detCalculate(int n, int a, int b, int c); //����ʽ���㺯��

int main(void) {

	int n;//���Խ�����ʽ�Ľ���

	int a, b, c; //���Խ�����ʽ��Ԫ�ص�ֵ

	cout << "���������������Խ�����ʽ�Ľ�����" ;
	cin >> n;
	cout << "���������Խ�Ԫ��a��ֵ��";
	cin >> a ;
	cout << "�������϶Խ���Ԫ��b��ֵ��";
	cin >> b;
	cout << "�������¶Խ���Ԫ��c��ֵ��";
	cin >> c;

	//����ʽ����
	int det = detCalculate(n, a, b, c);

	cout << "����" << n << "������ʽ��ֵΪ" << det << endl;

	return 0;
}

/*�㷨˼·
	�����Խ�����ʽ���л���õݹ鹫ʽ���������ʽ�ļ�����Բ��õݹ���㡣
*/
int detCalculate(int n, int a, int b, int c) {
	if (n == 1 || n == 2) { //��ֹ����������n=1��n=2
		//��ֹ�������ߵķ���ֵ��ͬ �����Ҫ�����ж�
		if (n == 1) {
			return a;//����һ������ʽ����ֵ
		} else {
			return a * a - b * c; //���ض�������ʽ����ֵ
		}
	} else {
		return a * detCalculate(n - 1, a, b, c) - b * c * detCalculate(n - 2, a, b, c);//�ݹ鹫ʽ
	}
}
