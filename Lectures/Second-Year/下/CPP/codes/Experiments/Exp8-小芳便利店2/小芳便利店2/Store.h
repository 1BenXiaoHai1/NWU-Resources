#ifndef STORE
#define STORE

#include<string>
#include<vector>
using namespace std;

//�������
//Goods��
class Goods {
		string name;
		double price;
	public:
		//��Ա������.h�ļ���ֻ����

		//���캯��������ʼ����
		Goods() {
			name = "NULL";    //Ĭ�Ϲ��캯��
			price = 0;
		}
		Goods(string _name, double _price); //���캯��
		Goods(const Goods & item);//�������캯��
		//�޸�����������
		void setName(string _name);
		//��������������
		string getName();
		//�޸���������Ǯ
		void setPrice(double _price);
		//������������Ǯ
		double getPrice();
		//�������캯��
};

//Basket��
class Basket {
		vector<Goods> goodsList;//�嵥��
	public:
		void addGoods(Goods item);//�����Ʒ
		void clear();//��ղ˵�
		double getTotalPrice();//������
		bool isEmpty();//�ж��嵥�Ƿ�Ϊ��
		vector<Goods> getGoodsList();//������
};

//Store��
class Store {
		vector<Goods> goods;//������Ʒ
		Basket basket;//�˵�
		string Msg_Header;//�˵�����
		string Msg_Footer;//�˵�β��
	public:
		void Start();
		void exit();
		void checkout(Basket List);//ȷ�Ϲ������
		void addGoods(Goods item);//����Ʒ�˵��������Ʒ
		void displayMenu();//��ӡ��Ʒ�˵�
		void invalidInput();//��������
		vector<Goods> getStoreGoods();//��ȡ��Ʒ�嵥
};

#endif
