/*
 * phonebook.h
 *
 *  Created on: 2010-9-26
 *      Author: ibm
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_
#include <map>
#include <string>
#include <iostream>
using namespace std;
class PhoneBook{
public:
	PhoneBook(){}
	~PhoneBook(){}
	void addItem(string name, string number){pb[name] = number;}
	void delItem(string name){pb.erase(name);}
	int size(){return pb.size();}
	string searchByName(string name){
		map<string,string>::iterator it = pb.find(name);
		if(it!=pb.end())
			return it->second;
		else
			return "";
	}
	string searchByNumber(string number){
		map<string,string>::iterator it = pb.begin();
		string name="";
		while(it!=pb.end())
		{
			if(it->second == number){
				name = it->first;
				break;
			}
			it++;
		}
		return name;
	}
	void importFromFile(istream& in){
		string name, number;
		while(in>>name>>number)
			pb[name] = number;
	}
	void exportToFile(ostream& out){
		map<string,string>::iterator it;
		for(it = pb.begin(); it != pb.end(); it++)
			out<<it->first<<" "<<it->second<<"\n";
	}
private:
	map<string,string> pb;
};

#endif /* PHONEBOOK_H_ */
