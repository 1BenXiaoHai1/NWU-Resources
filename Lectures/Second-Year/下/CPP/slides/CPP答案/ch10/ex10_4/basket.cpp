/*
 * basket.cpp
 */
#include "basket.h"
	Basket::Basket(){}
	void Basket::addGoods(Goods* g){
		selected.push_back(g);
	}
	void Basket::clear(){
		selected.clear();
	}
	double Basket::totalPrice(){
		vector<Goods*>::iterator it;
		double total = 0;
		for(it=selected.begin(); it!=selected.end(); it++)
			total += (*it)->getPrice();
		return total;
	}
