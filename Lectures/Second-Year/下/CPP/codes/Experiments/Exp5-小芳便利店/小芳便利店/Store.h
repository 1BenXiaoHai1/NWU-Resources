#ifndef STORE_H
#define STORE_H

#include<string>
#include<iostream>

using namespace std;

//��Ʒ��
class Goods {	
private:
	//���ݳ�Ա
	string GoodsName;//��Ʒ��
	int GoodsNo;//��Ʒ���
	double Price;//��Ʒ�۸�
	//��Ա����
public:
	string getGoodsName();//����������������Ʒ��Ϣ
	void setGoodsName(string name);//�����������޸���Ʒ��Ϣ
	int getGoodsNo();
	void setGoodsNo(int num);
	double getPrice();
	void setPrice(double newpri);
};

#endif
