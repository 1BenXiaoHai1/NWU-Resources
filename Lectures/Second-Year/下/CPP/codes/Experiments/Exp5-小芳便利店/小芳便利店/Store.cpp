#include<iostream>
#include<string>
#include"Store.h"

using namespace std;

string Goods::getGoodsName()
{
	return GoodsName;
}

void Goods::setGoodsName(string name)
{
	GoodsName=name;
}

int Goods::getGoodsNo()
{
	return GoodsNo;
}

void Goods::setGoodsNo(int num)
{
	if(num>=0){//判断数据是否合法
		GoodsNo=num;
	}
}

double Goods::getPrice()
{
	return Price;
}

void Goods::setPrice(double newpri)
{
	if(newpri>=0){//判断数据是否合法
		Price = newpri;
	}
}
