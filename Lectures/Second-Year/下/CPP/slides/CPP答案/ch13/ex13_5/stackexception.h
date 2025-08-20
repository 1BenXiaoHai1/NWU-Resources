/*
 * stackexception.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef STACKEXCEPTION_H_
#define STACKEXCEPTION_H_
#include <iostream>
using namespace std;
class InvalidStackSize{
public:
	InvalidStackSize(int sz):size(sz){}
	void message(){
		cout<<"Error when creating a Stack."<<"Wrong size:"<<size<<endl;
	}
private:
	int size;
};
class PushOnFull{
public:
	PushOnFull(int v):value(v){}
	void message(){
		cout<<"push() error:"<<"Push value"<<value<<" on a full stack."<<endl;
		}
private:
	int value;
};
class PopOnEmpty{
public:
	void message(){
		cout<<"pop() error:"<<"Pop on an empty stack."<<endl;
		}
};
class TopOfEmpty{
public:
	void message(){
		cout<<"top_of() error:"<<"Empty stack."<<endl;
		}
};

#endif /* STACKEXCEPTION_H_ */
