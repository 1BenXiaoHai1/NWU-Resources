//��ӡ�žų˷���
#include <iostream>

using namespace std;

int main() {
	for (int i = 9, row = 1; i > 0; i--, row++) { //������ֱ������),row��Ϊ�˱��ڴ�ӡÿ�п�ͷ�Ŀո�
		//��ӡÿ���ͷ�Ŀո�
		for (int k = 1; k <= row - 1; k++) {
			cout << "\t";
		}

		//��ӡ��ʽ
		for (int j = i; j > 0; j--) { //����ˮƽ�����У�
			cout << i << "x" << j << "=" << i*j << "\t";
		}

		cout << endl;
	}

	return 0;
}
