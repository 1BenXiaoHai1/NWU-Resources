/*
 * singlelist.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef SINGLELIST_H_
#define SINGLELIST_H_
#include <cassert>
#include <iostream>
using namespace std;
template<class T> class slistelem;
template<class Type> class slist {
public:
	slist() : h(0) {}
	~slist() { release(); }
	void prepend(Type value);
	void del();
	slistelem<Type>* first() const {return h;}
	void print(ostream& os = cout) const;
	bool contains(Type value) const;
	void release();
private:
	slistelem<Type>* h;
};
template<class T> class slistelem {
public:
	T data;
	slistelem<T>* next;
};
template<class Type> void slist<Type>::prepend(Type value){
	slistelem<Type>* temp = new slistelem<Type>;
	assert(temp != 0);
	temp -> next = h;
	temp -> data = value;
	h = temp;
}
template<class Type> void slist<Type>::del(){
	assert(h);
	slistelem<Type>* temp = h;
	h = h->next;
	delete temp;
}
template<class Type> void slist<Type>::print(ostream& os) const {
	slistelem<Type>* temp = h;
	while (temp != 0) {
		os<<temp->data<<"->";
		temp = temp->next;
	}
	os<<"\n###"<<"\n";
}
template<class Type> bool slist<Type>::contains(Type value) const{
	slistelem<Type>* temp = h;
	while (temp != 0) {
		if (temp->data == value)
			return true;
		temp = temp->next;
	}
	return false;
}
template<class Type> void slist<Type>::release(){
	while (h != 0) del();
}
#endif /* SINGLELIST_H_ */
