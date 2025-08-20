/*
 * Vect.h
 *6. 设计并实现一个带异常处理的动态数组类。
 */

#ifndef VECT_H_
#define VECT_H_
#include "vectexception.h"
class Vect{
public:
	explicit Vect(int n=10)throw(ArraySizeError);
	Vect(int* a, int sz)throw(ArraySizeError);
	Vect(const Vect& v);
	~Vect(){delete[]arr;}
	void copy(const Vect& v);
	int& operator[](int index) throw(BoundaryError);

	int count(){return size;}
private:
	int size;
	int* arr;
};

#endif /* VECT_H_ */
