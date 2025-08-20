/*
 * basket.h
 *

 */

#ifndef BASKET_H
#define BASKET_H
#include <vector>
#include "goods.h"
using std::vector;
class Basket{
public:
	Basket();
	void addGoods(Goods* g);
	void clear();
	double totalPrice();
private:
	vector<Goods*> selected;
};
#endif //BASKET_H
