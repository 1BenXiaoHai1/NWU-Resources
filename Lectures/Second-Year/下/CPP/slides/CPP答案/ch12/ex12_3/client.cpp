/*
 * client.cpp
 *
 *  Created on: 2010-9-26
 *      Author: ibm
 */

#include "phonebook.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	PhoneBook pb;
	ifstream in("phonebook.txt");
	pb.importFromFile(in);
	pb.exportToFile(cout);
	pb.addItem("LBJ","12-09-887-65");
	cout<<pb.searchByName("LBJ")<<endl;
	cout<<pb.searchByNumber("12-09-887-65")<<endl;
	cout<<pb.size()<<endl;
	pb.delItem("LBJ");
	pb.exportToFile(cout);
	ofstream out("exportedphonebook.txt");
	pb.exportToFile(out);

}
