/*
 * delistfunc.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef DELISTFUNC_H_
#define DELISTFUNC_H_
//global functions
#include "node.h"
#include <iostream>
using namespace std;
template<class T> Node<T>* createList(T data)
{
	Node<T>* head = new Node<T>;
	head->data = data;
	head -> prev = 0;
	head -> next = 0;
	return head;
}
template<class T> Node<T>* insertNode(Node<T>* h, T data)
{
	Node<T>* n = new Node<T>;
	n->data = data;
	n->next = h;
	n->prev = 0;
	if(h!=0)
		h->prev = n;
	return n;
}
template<class T> Node<T>* delNode(Node<T>* h, T data)
{
	Node<T>* p = h;
	while(p!=0 && p->data!= data)
		p = p->next;
	if(p == 0)	//no such node
		return h;
	if(p == h){  //head
		if(h->next==0){  //only one node
			delete h;
			return 0;
		}
		else {
			h = h->next;
			h->prev = 0;
			delete p;
		}
	}
	else	//middle node
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
	}
	return h;
}
template <class T> void releaseList(Node<T>* h)
{
	Node<T>* p = h;
	while(p!=0){
		h = h->next;
		delete p;
		p = h;
	}
}
template <class T> void print(Node<T>* p)
{
	while(p!=0)
	{
		cout<<p->data<<"->";
		p = p->next;
	}
	cout<<"##"<<endl;
}

#endif /* DELISTFUNC_H_ */
