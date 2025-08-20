/*
 * Vect.cpp
 *
 */
#include "vect.h"
#include "vectexception.h"
Vect::Vect(int n)throw(ArraySizeError){
	if(n<=0)

		throw ArraySizeError();
	size = n;
	arr = new int[size];
}
Vect::Vect(int* a, int sz)throw(ArraySizeError){
	if(sz<=0)
		throw ArraySizeError();
	size = sz;
	arr = new int[size];
	for(int i=0; i<sz; i++)
		arr[i] = a[i];
}
Vect::Vect(const Vect& v){
	size = v.size;
	arr = new int[size];
	for(int i=0; i<size; i++)
		arr[i] = v.arr[i];
}
void Vect::copy(const Vect& v){
	if(this == &v)
		return;
	size = v.size;
	delete[] arr;
	arr = new int[size];
	for(int i=0; i<size; i++)
		arr[i] = v.arr[i];
}
int& Vect::operator[](int index)throw(BoundaryError){
	if(index<0 || index>=size)
		throw BoundaryError();
	return arr[index];
}

