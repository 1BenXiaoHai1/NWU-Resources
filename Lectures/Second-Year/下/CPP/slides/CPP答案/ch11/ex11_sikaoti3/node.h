/*
 * node.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef NODE_H_
#define NODE_H_
template <class T> class Node{
public:
	Node():data(){prev = next = 0;}
	Node(T d):data(d){prev = next = 0;}
	T data;
	Node<T> *prev, *next;
};
#endif /* NODE_H_ */
