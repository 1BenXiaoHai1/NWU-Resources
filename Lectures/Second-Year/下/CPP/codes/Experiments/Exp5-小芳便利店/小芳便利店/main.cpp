#include <iostream>
#include<string>
#include<windows.h>
#include"Store.h"

using namespace std;
//初始化
void GoodsInit(Goods &Bread, Goods &Cocacola, Goods &Beer, Goods &Chocalate) {
	Bread.setGoodsName("Bread");
	Bread.setPrice(1.00);
	Bread.setGoodsNo(1);
	Cocacola.setGoodsName("Cocacola");
	Cocacola.setPrice(2.50);
	Cocacola.setGoodsNo(2);
	Beer.setGoodsName("Beer");
	Beer.setPrice(10.00);
	Beer.setGoodsNo(3);
	Chocalate.setGoodsName("Chocalate");
	Chocalate.setPrice(2.50);
	Chocalate.setGoodsNo(4);
}
//价格打印
void PricePrint(Goods commodity) {
	cout << "Thank You!" << endl;
	cout << "You Have Selected [" << commodity.getGoodsName() << "] $" << commodity.getPrice() << endl;
	cout << "-----------------------" << endl;
	cout << "Good Bye!" << endl;
}
//菜单打印
void Menu(Goods Bread, Goods Cocacola, Goods Beer, Goods Chocalate) {
	SetConsoleTitle("XiaoFang Convenience Store");
	system("color 70");
	cout << "Store" << endl;
	cout << "*****************************************" << endl;
	cout << "\tXiaoFang Convenience Store" << endl;
	cout << "*****************************************" << endl;
	cout << "[" << Bread.getGoodsNo() << "]" << Bread.getGoodsName() << " \t$" << Bread.getPrice() << endl;
	cout << "[" << Cocacola.getGoodsNo() << "]" << Cocacola.getGoodsName() << " \t$" << Cocacola.getPrice() << endl;
	cout << "[" << Beer.getGoodsNo() << "]" << Beer.getGoodsName() << " \t$" << Beer.getPrice() << endl;
	cout << "[" << Chocalate.getGoodsNo() << "]" << Chocalate.getGoodsName() << " \t$" << Chocalate.getPrice() << endl;
	cout << "[0]exit" << endl;
	cout << "-------------------------------------------" << endl;

}

int main(int argc, char** argv) {
	Goods Bread, Cocacola, Beer, Chocalate;
	GoodsInit(Bread, Cocacola, Beer, Chocalate);
	Menu(Bread, Cocacola, Beer, Chocalate);
	//选择模块
loop:
	cout << "Please Select A Number:";
	int ChoiceNumber;
	cin >> ChoiceNumber;
	switch (ChoiceNumber) {
		case 0:
			cout << "Good Bye!" << endl;
			cout << "-----------------------" << endl;
			break;
		case 1:
			PricePrint(Bread);
			break;
		case 2:
			PricePrint(Cocacola);
			break;
		case 3:
			PricePrint(Beer);
			break;
		case 4:
			PricePrint(Chocalate);
			break;

		default:
			cout << "Input Error!Please Input Again!" << endl;
			goto loop;
			break;
	}

	return 0;
}
