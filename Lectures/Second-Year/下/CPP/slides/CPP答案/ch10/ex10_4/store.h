/*
 * store.h
  */

#ifndef STORE_H_
#define STORE_H_
#include "goods.h"
#include "basket.h"
#include <vector>
#include <string>
using namespace std;
class Store{
public:
	Store();
	~Store();
	void start();
private:
	void exit();
	double checkOut();
	string getGoodsList();
	int range();
	void addGoodsToBasket(int sel);
	void displayMenu();
	void shopping();
private:
	vector<Goods*> allGoods;
	Basket basket;
	static string Header;
	static string Footer;
	static string Error;
	static string Thanks;
	static string Checkout;
};
#endif /* STORE_H_ */
