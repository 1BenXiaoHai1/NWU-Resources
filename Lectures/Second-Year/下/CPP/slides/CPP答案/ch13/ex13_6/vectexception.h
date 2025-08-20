/*
 * vectexception.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef VECTEXCEPTION_H_
#define VECTEXCEPTION_H_
#include <iostream>
#include <string>
using namespace std;
class excp{
public:
	excp(string str):msg(str){}
	virtual void message(){
		cout<<msg<<endl;
	}
	virtual ~excp(){}
private:
	string msg;

};
class ArraySizeError : public excp{
public:
	ArraySizeError():excp("Wrong array size."){}
};
class BoundaryError : public excp{
public:
	BoundaryError():excp("Access out of boundary."){}
};
#endif /* VECTEXCEPTION_H_ */
