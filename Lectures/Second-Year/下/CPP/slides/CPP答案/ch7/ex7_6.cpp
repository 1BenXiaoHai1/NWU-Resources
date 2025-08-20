/*
 * ex7_6.cpp
 *
 *  6. 编写一个程序，模拟ATM机。
 *
 */
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;
//----------------------------------------------------
class Account{
public:
	Account();
	Account(unsigned aid);
	Account(unsigned aid, double abalance);
	Account(unsigned aid, string aname);
	Account(unsigned aid, string aname, double abalance);
	Account(const Account&) = default;
	Account& operator=(const Account&) = delete;
	~Account() = default;

	void withdraw(double amount);
	void deposit(double amount);

	double getBalance() const;
	unsigned getId() const;
	const string& getName() const;

private:
	unsigned id = 0;
	string name = "0";
	double balance = 0;
	void setBalance(double balance);

};


Account::Account():Account(0, "0", 0.0) {
}

Account::Account(unsigned aid) : id(aid){
	ostringstream os;
	os << id;
	name = os.str();
	balance = 0;
}

Account::Account(unsigned aid, double abalance) : Account(aid) {
	balance = abalance;
}

Account::Account(unsigned aid, string aname): Account(aid, aname, 0) {
}

Account::Account(unsigned aid, string aname, double abalance) :
												id(aid), name(aname), balance(abalance) {
}
void Account::withdraw(double amount) {
	assert(amount <= balance);
	balance -= amount;
}

void Account::deposit(double amount) {
	assert(amount > 0);
	balance += amount;
}


double Account::getBalance() const {
	return balance;
}

void Account::setBalance(double balance = 0) {
	this->balance = balance;
}

unsigned Account::getId() const {
	return id;
}

const string& Account::getName() const {
	return name;
}
//----------------------------------------------------
class ATM{

public:
	ATM(){}
	ATM(const ATM&) = delete;
	ATM& operator=(const ATM&) = delete;
	~ATM() = default;

	void showIdle()const {
		cout << idleMsg;
	}
	unsigned getInputId(){
		unsigned accId;
		cin >> accId;
		return accId;
	}

	void showMenu() const {
		cout << menuMsg;
	}

	void transaction(Account& acc) const{
		int item = 0;
		while(item != 4){
			showMenu();
			cin >> item;
			switch(item){
			case 1:
				this->checkBalance(acc);
				break;
			case 2:
				this -> withdraw(acc);
				break;
			case 3:
				this -> deposit(acc);
				break;
			case 4:
				this -> exit();
				break;
			}
		}
	}

	void exit()const {
		cout << byeMsg << endl;
	}

	void withdraw(Account& acc)const{
		cout << "Enter amount: ";
		double amount;
		do{
			cin >> amount;
			if(amount > acc.getBalance()){
				cout << "Insufficient Balance." << endl;
				cout << "Enter amount: ";
			}
			else
				break;
		}while(true);

		acc.withdraw(amount);
		cout <<"Account Balance: "<< acc.getBalance() << endl;

	}
	void deposit(Account& acc)const{
		cout << "Enter amount: ";
		double amount;
		do{
			cin >> amount;
			if(amount <= 0){
				cout << "Invalid input." << endl;
				cout << "Enter amount: ";
			}
			else
				break;
		}while(true);
		acc.deposit(amount);
		cout <<"Account Balance: "<< acc.getBalance() << endl;
	}

	void checkBalance(const Account& acc)const{
		cout << "Account balance: "<< acc.getBalance() << endl;
	}

private:
	const string idleMsg = "Enter an id: ";
	const string menuMsg = R"(
------ Main Menu ------
    1. check balance
    2. withdraw
    3. deposit
    4. exit
-----------------------
)";
	const string byeMsg = "Thank you, goodbye!\n";
	void welcome(string name) const {cout << "Welcome " << name << endl;}


};
//----------------------------------------------------
int main()
{
	vector<Account> va;
	for(unsigned i = 0; i < 10; ++i){
		Account acc(i, 1000);
		va.push_back(acc);
	}

	ATM atm;
	do{
		atm.showIdle();
		unsigned accId = atm.getInputId();
		for(size_t i = 0; i < va.size(); ++i)
			if(va[i].getId() == accId){
				atm.transaction(va[i]);
				break;
			}
	}while(true);

	return 0;
}

