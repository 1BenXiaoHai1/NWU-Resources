/*
 * ex6_15.cpp
 *
 *      15. 完成小芳便利店第二个版本
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//----------------------
class Goods{
public:
	Goods(string n, double p):name(n),price(p){}
	string getName(){return name;}
	double getPrice(){return price;}
	void setName(string n){name = n;}
	void setPrice(double p){price = p;}
private:
	string name;
	double price;
};
class Basket{
public:
	void addGoods(const Goods& g){goodslist.push_back(g);}
	void clear(){goodslist.clear();}
	bool isEmpty() {return goodslist.empty();}
	double getTotalPrice(){
		double total = 0;
		for(vector<Goods>::iterator it=goodslist.begin();
				it!=goodslist.end(); it++)
			total += it->getPrice();
		return total;
	}
	vector<Goods> getGoodslist(){return goodslist;}
private:
	vector<Goods> goodslist;
};
class Store{
public:
	Store();
	void start();
	void exit();
	void displayMenu();
	void select();
	void addGoods(const Goods&);
	void invalidInput();
	void checkOut();

private:
	vector<Goods> allGoods;
	Basket basket;
	static string Header;
	static string Footer;
	static string Error;
	static string Thanks;
	static string Bye;
	static string Checkout;
};
string Store::Header = "*************************************\n"
		"Welcome to XiaoFang Convenience Store\n"
		"****************************************\n";
string Store::Footer = "(9) CHECKOUT\n"
		"(0) EXIT"
		"--------------------------------\n"
		"PLEASE SELECT A NUMBER:\n";
string Store::Error = "SORRY, YOU SELECT A WRONG NUMBER!\n";
string Store::Thanks = "THANK YOU!\nYOU HAVE SELECTED:\t";
string Store::Bye = "-----------------\nGOOD BYE!\n"
		"[PRESS ENTER TO EXIT...]";
string Store::Checkout ="-------Check Out--------\n"
		"total price: ";

Store::Store(){
	allGoods.push_back(Goods("Bread",2.5));
	allGoods.push_back(Goods("Cocacola",3.5));
	allGoods.push_back(Goods("Beer",7.8));
	allGoods.push_back(Goods("Chocalate",9.9));
	allGoods.push_back(Goods("Pencil",1.5));
	allGoods.push_back(Goods("NoteBook",4.5));
}
void Store::start(){
	basket.clear();
	displayMenu();
}
void Store::exit(){
	cout<<Bye;
	basket.clear();
}
void Store::displayMenu(){
	cout<<Header;
	int i=1;
	for(vector<Goods>::iterator it = allGoods.begin(); it!=allGoods.end();it++,i++)	{
		cout<<"("<<i<<")"
				<<it->getName()<<"\t"
				<<it->getPrice()<<endl;
	}
	cout<<Footer;
}
void Store::select(){
	int sel;
	do{
		cin>>sel;
		if(sel == 0){
			break;
		}

		if(sel==9){
			checkOut();
			break;
		}
		if(sel>=1 && sel<=6){
			addGoods(allGoods[sel-1]);
			cout<<"PLEASE SELECT A NUMBER:\n";
			continue;
		}
		invalidInput();
	}while(true);
}
void Store::addGoods(const Goods& g){
	basket.addGoods(g);
}
void Store::invalidInput(){
	cout<<Error;
	cout<<"PLEASE SELECT A NUMBER:\n";
}
void Store::checkOut(){
	cout<<Checkout;
	cout<<basket.getTotalPrice()<<endl;
}
//----------------------

int main()
{
	Store xf;
	xf.start();
	xf.select();
	xf.exit();
}




