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
	if(num>=0){//�ж������Ƿ�Ϸ�
		GoodsNo=num;
	}
}

double Goods::getPrice()
{
	return Price;
}

void Goods::setPrice(double newpri)
{
	if(newpri>=0){//�ж������Ƿ�Ϸ�
		Price = newpri;
	}
}
