#ifndef STORE
#define STORE

#include<string>
#include<vector>
using namespace std;

//类的声明
//Goods类
class Goods {
		string name;
		double price;
	public:
		//成员函数在.h文件中只声明

		//构造函数——初始化类
		Goods() {
			name = "NULL";    //默认构造函数
			price = 0;
		}
		Goods(string _name, double _price); //构造函数
		Goods(const Goods & item);//拷贝构造函数
		//修改器——姓名
		void setName(string _name);
		//访问器——姓名
		string getName();
		//修改器——价钱
		void setPrice(double _price);
		//访问器——价钱
		double getPrice();
		//拷贝构造函数
};

//Basket类
class Basket {
		vector<Goods> goodsList;//清单表
	public:
		void addGoods(Goods item);//添加商品
		void clear();//清空菜单
		double getTotalPrice();//访问器
		bool isEmpty();//判断清单是否为空
		vector<Goods> getGoodsList();//访问器
};

//Store类
class Store {
		vector<Goods> goods;//所有商品
		Basket basket;//菜单
		string Msg_Header;//菜单顶部
		string Msg_Footer;//菜单尾部
	public:
		void Start();
		void exit();
		void checkout(Basket List);//确认购物结束
		void addGoods(Goods item);//向商品菜单中添加商品
		void displayMenu();//打印商品菜单
		void invalidInput();//错误输入
		vector<Goods> getStoreGoods();//获取商品清单
};

#endif
