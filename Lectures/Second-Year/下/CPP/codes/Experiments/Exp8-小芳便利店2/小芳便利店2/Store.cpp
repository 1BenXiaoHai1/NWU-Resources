#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include"Store.h"

using namespace std;

//Goods类成员函数定义
//构造函数——类内部成员函数可以直接访问类内部私有成员
Goods::Goods(string _name, double _price) {
	name = _name;
	price = _price;
}
//拷贝构造函数——浅拷贝(不考虑指针引用啥的)
Goods::Goods(const Goods & item) {
	name = item.name;
	price = item.price;
}
//访问器和修改器
//姓名
void Goods::setName(string _name) {
	name = _name;
}

string Goods::getName() {
	return name;
}
//价格
void Goods::setPrice(double _price) {
	//输入检查——价格必须不小于零
	if (_price >= 0) {
		price = _price;
	} else {
		cout << "输入不合法" << endl;
	}
}

double Goods::getPrice() {
	return price;
}


//Basket类成员函数定义
//添加商品
void Basket::addGoods(Goods item) {
	goodsList.push_back(item);
}

//判断菜单是否为空
bool Basket::isEmpty() {
	if (goodsList.empty()) {
		return true;
	} else {
		return false;
	}
}
//清空菜单
void Basket::clear() {
	//不为空进行清空
	if (!isEmpty()) {
		goodsList.clear();
	}
}

//获得购物清单总价
double Basket::getTotalPrice() {
	double Total = 0;

	for (int i = 0; i < goodsList.size(); i++) {
		Total += goodsList[i].getPrice();
	}

	return Total;
}

//查看清单
vector<Goods> Basket::getGoodsList() {
	if (!isEmpty()) {
		return goodsList;
	}
}

//Store类成员函数定义
//退出程序
void Store::exit() {
	cout << endl << "Welcome to come again next time" << endl;
}
//确认购物结束
void Store::checkout(Basket List) {
	cout << endl << "===========CHECK OUT==========" << endl << endl;
	vector<Goods> check = List.getGoodsList();
	//输出购物清单
	for (int i = 0; i < check.size(); i++) {
		cout << "\t" << check[i].getName() << "\t" << check[i].getPrice() << endl;
	}
	cout << "=============================" << endl;
	//输出总价
	cout << "Total : $" << List.getTotalPrice() << endl << "Thanks!" << endl << endl;
}
//向商品表中添加商品
void Store::addGoods(Goods item) {
	goods.push_back(item);
}
//菜单输出
void Store::displayMenu() {
	//界面打印
	SetConsoleTitle("XiaoFang Convenience Store");
	system("color 70");
	cout << "*****************************************" << endl;
	cout << "\tXiaoFang Convenience Store" << endl;
	cout << "*****************************************" << endl << endl;
	//遍历动态数组并进行输出
	for (int i = 0; i < goods.size(); i++) {
		cout << "[" << i + 1 << "] " << goods[i].getName() << "\t" << goods[i].getPrice() << endl;
	}
	cout << endl << "[9] checkout" << endl;
	cout << "[0] exit" << endl;
	cout << "-------------------------------------------" << endl;
}
//获取商品清单
vector<Goods> Store::getStoreGoods() {
	return goods;//返回商品单
}
//错误输入
void Store::invalidInput() {
	cout << "Invalid input!!!Please try again." << endl; //错误输入提示
}
