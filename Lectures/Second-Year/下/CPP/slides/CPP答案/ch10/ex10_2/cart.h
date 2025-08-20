/*
 * cart.h
 *
 */

#ifndef CART_H_
#define CART_H_
#include "goods.h"
#include <vector>
#include <string>
using namespace std;
class Cart{
public:
	Cart(){}
	~Cart(){}
	void addItem(Goods* g){
		items.push_back(g);
	}
	double totalPrice(){
		double total = 0;
		for(unsigned int i=0; i<items.size();i++)
			total += items[i]->getPrice();
		return total;
	}
	string goodsList(){
		string itemslist = "";
		for(unsigned int i=0; i<items.size();i++)
			itemslist += items[i]->getDetails();
		return itemslist;
	}
private:
	vector<Goods*> items;
};

#endif /* CART_H_ */
