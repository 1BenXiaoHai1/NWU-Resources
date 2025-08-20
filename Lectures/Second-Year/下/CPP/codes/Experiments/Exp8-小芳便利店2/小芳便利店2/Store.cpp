#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include"Store.h"

using namespace std;

//Goods���Ա��������
//���캯���������ڲ���Ա��������ֱ�ӷ������ڲ�˽�г�Ա
Goods::Goods(string _name, double _price) {
	name = _name;
	price = _price;
}
//�������캯������ǳ����(������ָ������ɶ��)
Goods::Goods(const Goods & item) {
	name = item.name;
	price = item.price;
}
//���������޸���
//����
void Goods::setName(string _name) {
	name = _name;
}

string Goods::getName() {
	return name;
}
//�۸�
void Goods::setPrice(double _price) {
	//�����顪���۸���벻С����
	if (_price >= 0) {
		price = _price;
	} else {
		cout << "���벻�Ϸ�" << endl;
	}
}

double Goods::getPrice() {
	return price;
}


//Basket���Ա��������
//�����Ʒ
void Basket::addGoods(Goods item) {
	goodsList.push_back(item);
}

//�жϲ˵��Ƿ�Ϊ��
bool Basket::isEmpty() {
	if (goodsList.empty()) {
		return true;
	} else {
		return false;
	}
}
//��ղ˵�
void Basket::clear() {
	//��Ϊ�ս������
	if (!isEmpty()) {
		goodsList.clear();
	}
}

//��ù����嵥�ܼ�
double Basket::getTotalPrice() {
	double Total = 0;

	for (int i = 0; i < goodsList.size(); i++) {
		Total += goodsList[i].getPrice();
	}

	return Total;
}

//�鿴�嵥
vector<Goods> Basket::getGoodsList() {
	if (!isEmpty()) {
		return goodsList;
	}
}

//Store���Ա��������
//�˳�����
void Store::exit() {
	cout << endl << "Welcome to come again next time" << endl;
}
//ȷ�Ϲ������
void Store::checkout(Basket List) {
	cout << endl << "===========CHECK OUT==========" << endl << endl;
	vector<Goods> check = List.getGoodsList();
	//��������嵥
	for (int i = 0; i < check.size(); i++) {
		cout << "\t" << check[i].getName() << "\t" << check[i].getPrice() << endl;
	}
	cout << "=============================" << endl;
	//����ܼ�
	cout << "Total : $" << List.getTotalPrice() << endl << "Thanks!" << endl << endl;
}
//����Ʒ���������Ʒ
void Store::addGoods(Goods item) {
	goods.push_back(item);
}
//�˵����
void Store::displayMenu() {
	//�����ӡ
	SetConsoleTitle("XiaoFang Convenience Store");
	system("color 70");
	cout << "*****************************************" << endl;
	cout << "\tXiaoFang Convenience Store" << endl;
	cout << "*****************************************" << endl << endl;
	//������̬���鲢�������
	for (int i = 0; i < goods.size(); i++) {
		cout << "[" << i + 1 << "] " << goods[i].getName() << "\t" << goods[i].getPrice() << endl;
	}
	cout << endl << "[9] checkout" << endl;
	cout << "[0] exit" << endl;
	cout << "-------------------------------------------" << endl;
}
//��ȡ��Ʒ�嵥
vector<Goods> Store::getStoreGoods() {
	return goods;//������Ʒ��
}
//��������
void Store::invalidInput() {
	cout << "Invalid input!!!Please try again." << endl; //����������ʾ
}
