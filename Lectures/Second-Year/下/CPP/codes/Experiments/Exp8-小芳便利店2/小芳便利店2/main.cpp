#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"Store.h"

using namespace std;


//�̵���Ʒ��Ϣ���롪���ļ�����
void StoreGoodsInput(Store &oneStore) {
	//���ļ��ж�ȡ���ݲ�����Store�����е�goods
	ifstream fin("StoreGoods.txt");

	//δ�����ļ����һ�� һֱ��ȡ
	while (!fin.eof()) {
		string buffer;
		getline(fin, buffer); //��ȡһ����Ʒ����Ϣ
		if (buffer.empty()) { //�����������Ϊ���� ���Թ�
			continue;
		}
		istringstream is(buffer);//�����ַ�����������ȡѧ�������ݡ������ÿո���л���
		string Gname;
		double Gprice;
		is >> Gname >> Gprice;
		Goods one(Gname, Gprice);
		oneStore.addGoods(one);//���̵����Ʒ�嵥�������Ʒ
	}

	fin.close();
}

//�ж�����ĺ���Ϊ�ĸ���Ʒ
Goods SearchBuyGood(Store & oneStore, int no) {
	vector<Goods> StoreGoods = oneStore.getStoreGoods();

	for (int i = 0; i < StoreGoods.size(); i++) {
		if (i + 1 == no) {
			return StoreGoods[i];
		}
	}
}

int main(int argc, char** argv) {

	Store XiaoFang;//����һ��С��������
	Basket List_XiaoFang;//����С����������嵥
	vector<Goods> GoodsSheet;

	//��ȡ�̵�˵�
	StoreGoodsInput(XiaoFang);
	//����
	Goods buy;
	while (1) {
		XiaoFang.displayMenu();
loop:
		cout << "Please select a number:";
		int n;
		cin >> n;
		switch (n) {
			case 0:
				XiaoFang.exit();
				exit(0);
			case 1:
				buy = SearchBuyGood(XiaoFang, 1);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 2:
				buy = SearchBuyGood(XiaoFang, 2);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 3:
				buy = SearchBuyGood(XiaoFang, 3);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 4:
				buy = SearchBuyGood(XiaoFang, 4);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 5:
				buy = SearchBuyGood(XiaoFang, 5);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 6:
				buy = SearchBuyGood(XiaoFang, 6);
				cout << endl << "You have selected " << buy.getName() << ", $" << buy.getPrice() << endl;
				List_XiaoFang.addGoods(buy);
				break;
			case 9:
				XiaoFang.checkout(List_XiaoFang);
				break;
			default:
				XiaoFang.invalidInput();
				goto loop;//������� ��ת��loop�� ��������
		}
	}




	return 0;
}
