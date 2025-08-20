/*
 * Store.cpp
 *
 */
#include "store.h"
#include <iostream>
#include <sstream>
using namespace std;
Store::Store(){
	allGoods.push_back(new ImportedGoods("Cocacola",3.5));
	allGoods.push_back(new Goods("Bread",4.5));
	allGoods.push_back(new Goods("Chocalate",6.8));
	allGoods.push_back(new ImportedGoods("Beer",8.5));
	allGoods.push_back(new Goods("Pencil",1.5));
	allGoods.push_back(new Goods("Notebook",2.9));
}
Store::~Store(){
	for(unsigned int i=0; i<allGoods.size(); i++)
		delete allGoods[i];
}
void Store::start(){
	displayMenu();
	basket.clear();
	shopping();
}
void Store::exit(){

}
double Store::checkOut(){
	double total = basket.totalPrice();
	basket.clear();
	return total;
}
string Store::getGoodsList(){
	ostringstream os;

	for(unsigned int i=0; i<allGoods.size();i++)
	{
		os<<"("<<i+1<<")";
		os<<allGoods[i]->getName()<<"\t"<<allGoods[i]->getPrice()<<'\n';
	}
	return os.str();
}

void Store::addGoodsToBasket(int sel){
	basket.addGoods(allGoods[sel-1]);
}

string Store::Header = "****************************************\n"
		"Welcome to XiaoFang Convenience Store\n"
		"****************************************\n";
string Store::Footer = "(9)CHECKOUT\n"
		"(0) EIXT\n"
		"---------------------------------------\n"
		"PLEASE SELECT A NUMBER: ";
string Store::Error = "YOU HAVE SELECTED A WRONG NUMBER.\n"
		"PLEASE SELECT A NUMBER: ";
string Store::Thanks = "THANK YOU.\n"
		"[PRESS ANY KEY TO EXIT...]\n";
string Store::Checkout = "Check Out...\n Total price is: ";

void Store::displayMenu()	{
	cout<<Header;
	cout<<getGoodsList();
	cout<<Footer;
}
void Store::shopping(){
	int sel;
	bool finish = false;
	while(!finish)
	{
		cin>>sel;
		switch(sel){
		case 0:
			cout<<Thanks<<endl;
			finish=true;
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			addGoodsToBasket(sel);
			cout<<"PLEASE SELECT A NUMBER: ";
			finish = false;
			break;
		case 9:
			cout<<Checkout;
			cout<<checkOut()<<endl;
			cout<<Thanks<<endl;
			finish = true;
			break;
		default:
			cout<<Error;
			finish = false;
		}
		if(finish)
			break;
		else
			continue;
	}
}

