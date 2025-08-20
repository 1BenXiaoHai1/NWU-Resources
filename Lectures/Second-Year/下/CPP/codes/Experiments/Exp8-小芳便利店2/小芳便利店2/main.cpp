#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"Store.h"

using namespace std;


//商店商品信息读入——文件读入
void StoreGoodsInput(Store &oneStore) {
	//从文件中读取数据并存入Store对象中的goods
	ifstream fin("StoreGoods.txt");

	//未到达文件最后一行 一直读取
	while (!fin.eof()) {
		string buffer;
		getline(fin, buffer); //读取一个商品的信息
		if (buffer.empty()) { //如果读进来的为空行 则略过
			continue;
		}
		istringstream is(buffer);//利用字符串流逐项提取学生的数据——利用空格进行划分
		string Gname;
		double Gprice;
		is >> Gname >> Gprice;
		Goods one(Gname, Gprice);
		oneStore.addGoods(one);//向商店的商品清单中添加商品
	}

	fin.close();
}

//判断输入的号码为哪个商品
Goods SearchBuyGood(Store & oneStore, int no) {
	vector<Goods> StoreGoods = oneStore.getStoreGoods();

	for (int i = 0; i < StoreGoods.size(); i++) {
		if (i + 1 == no) {
			return StoreGoods[i];
		}
	}
}

int main(int argc, char** argv) {

	Store XiaoFang;//定义一个小芳便利店
	Basket List_XiaoFang;//定义小芳便利店的清单
	vector<Goods> GoodsSheet;

	//读取商店菜单
	StoreGoodsInput(XiaoFang);
	//购物
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
				goto loop;//输入错误 跳转到loop处 重新输入
		}
	}




	return 0;
}
