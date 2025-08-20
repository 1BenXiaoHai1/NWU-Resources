/*
 * deList.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef DELIST_H_
#define DELIST_H_
#include "node.h"
#include <iostream>
using namespace std;
template <class T> class Delist{
public:
	Delist(){head = 0;}
	Delist(T data)
	{
		head = new Node<T>(data);
	}
	~Delist(){release();}
	void insertFront(T data){
		Node<T>* p = new Node<T>(data);
		p->data = data;
		p->next = head;
		p->prev = 0;
		if(head != 0)
			head -> prev = p;
		head = p;
	}
	void insertBack(T data){
		if(head == 0){
			head = new Node<T>(data);
			return;
		}
		Node<T> *p = head;
		while(p->next)
			p = p->next;
		Node<T> *n = new Node<T>(data);
		p->next = n;
		n->prev = p;
	}
	void delFront(){
		if(head == 0)
			return;
		if(head->next == 0){
			delete head;
			head = 0;
		}
		else{
			Node<T> *p = head;
			head = head->next;
			head -> prev = 0;
			delete p;
		}
	}
	void delBack(){
		if(head == 0)
			return;
		if(head->next ==0){
			delete head;
			head = 0;
		}
		else{
			Node<T>* p = head;
			while(p->next)
				p = p->next;
			p->prev->next = 0;
			delete p;
		}
	}
	void delNode(T data){
		//empty
		if(head ==0)
			return;
		//search data
		Node<T> *p = head;
		while(p && p->data!= data)
			p = p->next;
		if(!p)	//no such data
			return;
		if(p == head)	//first node
			delFront();
		else if(p->next == 0)	//last node
			delBack();
		else	//middle
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
	}
	void print(ostream& os = cout){
		Node<T> * p = head;
		while(p!=0){
			os<<p->data<<"->";
			p = p->next;
		}
		os<<"##\n";
	}
	void release(){
		Node<T> *p = head;
		while(p){
			head = head->next;
			delete p;
			p = head;
		}
	}
private:
	Node<T>* head;
};
#endif /* DELIST_H_ */
