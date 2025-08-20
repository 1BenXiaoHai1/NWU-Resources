/*
 * Vect.h
 *6. ��Ʋ�ʵ��һ�����쳣����Ķ�̬�����ࡣ
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
