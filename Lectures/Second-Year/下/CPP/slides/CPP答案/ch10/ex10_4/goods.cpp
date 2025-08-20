/*
 * goods.cpp
 *
 */
#include "goods.h"
string Goods::getName()const {
	return name;
}
double Goods::getPrice()const {
	return price;
}
void Goods::setName(const string& nm){
	name = nm;
}
void Goods::setPrice(double pr){
	price = pr;
}
