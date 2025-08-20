/*
 * goods.h
 *
 */

#ifndef GOODS_H_
#define GOODS_H_
#include <string>
using std::string;
class Goods{
public:
	Goods(string nm, double pr):name(nm),price(pr){}
	virtual ~Goods(){}
	virtual string getName()const ;
	virtual double getPrice()const ;
	virtual void setName(const string& nm);
	virtual void setPrice(double pr);
private:
	string name;
	double price;
};
//------------------------------
class ImportedGoods : public Goods{
public:
	ImportedGoods(string nm, double pr):Goods(nm, pr){}
	~ImportedGoods(){}
	string getName()const {return Goods::getName()+"<I>"; }
	double getPrice()const {return Goods::getPrice()*1.2;}
};
#endif /* GOODS_H_ */
