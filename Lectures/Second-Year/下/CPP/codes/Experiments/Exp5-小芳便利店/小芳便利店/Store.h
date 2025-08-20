#ifndef STORE_H
#define STORE_H

#include<string>
#include<iostream>

using namespace std;

//商品类
class Goods {	
private:
	//数据成员
	string GoodsName;//商品名
	int GoodsNo;//商品编号
	double Price;//商品价格
	//成员函数
public:
	string getGoodsName();//访问器——访问商品信息
	void setGoodsName(string name);//迭代器——修改商品信息
	int getGoodsNo();
	void setGoodsNo(int num);
	double getPrice();
	void setPrice(double newpri);
};

#endif
