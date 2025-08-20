/*
 * ex5_22.cpp
 *
 *  22. 完成小芳便利店第一个版本。
 */


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
struct item{
	string name;
	double price;
};
item goods[4] = {
		{"Bread",1.00},
		{"Cocacola", 2.50},
		{"Beer", 10.00},
		{"Chocalate", 2.50}
};

string title = 	"********************************\n"
				"XiaoFang Convenience Store\n"
				"********************************\n";
string selectMsg = "PLEASE SELECT A NUMBER:\n";
string bottom = "--------------------------------\n";
string selectError = "SORRY, YOU SELECT A WRONG NUMBER";
string thanks = "THANK YOU!\nYOU HAVE SELECTED:\t";
string bye = "-----------------\nGOOD BYE!\n[PRESS ENTER TO EXIT...]";
void printMenu()
{
	cout<<title;
	for(int i=0; i<4; i++)
		cout<<"("<<i+1<<")\t"<<goods[i].name<<"\t"
		<<showpoint<<setprecision(3)<<goods[i].price<<endl;
	cout<<"(0)"<<"\t"<<"EXIT"<<endl;
	cout<<bottom;
	cout<<selectMsg;
}
void Store()
{
	printMenu();
	int sel;
	cin>>sel;
	while(sel<0 || sel>4){
		cout<<selectError<<endl;
		cout<<selectMsg;
		cin>>sel;
	}
	if(sel)	{
		cout<<thanks;
		cout<<"["<<goods[sel-1].name<<"]\t"
		<<showpoint<<goods[sel-1].price<<endl;
	}
	cout<<bye<<endl;
	cin.get();
}

int main()
{
	Store();
}


