/*
 * array.h
 *
 *  ch11
 *  6. 设计一个数组类模板Array<T>，其中包含数组的常规操作、排序和查找等方法。
使用各类型的数据对其进行测试。
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include<algorithm>
#include<iostream>
#include<cassert>
using namespace std;
template <class T> class Array{
public:
	Array(int sz);
	Array(const Array<T>&);
	~Array();
	Array<T>& operator=(const Array<T>&);
	T& operator[](int index);
	const T& operator[](int index)const;
	void sortAll();
	int searchEle(T e)const;
	int size(){ return sz; }
	void listAll(ostream& os);
private:
	T* elements;
	int sz;
};

template <class T> Array<T>::Array(int n)
{
	assert (n > 0);
	sz = n;
	elements = new T[sz];
}
template <class T> Array<T>::Array(const Array<T>& arr)
{
	sz = arr.sz;
	elements = new T[sz];
	for(int i=0; i<sz; i++)
		elements[i] = arr.elements[i];
}
template <class T> Array<T>::~Array()
{
	delete[] elements;
}
template <class T> Array<T>& Array<T>::operator=(const Array<T>& arr)
{
	if(this == &arr)
		return *this;
	delete[] elements;
	sz = arr.sz;
	for(int i=0; i<sz; i++)
		elements[i] = arr.elements[i];
	return *this;
}
template <class T> T& Array<T>::operator[](int index)
{
	assert(index>=0 && index<sz);
	return elements[index];
}
template <class T> const T& Array<T>::operator[](int index)const
{
	assert(index>=0 && index<sz);
	return elements[index];
}

template <class T> void Array<T>::sortAll()
{
	sort(elements, elements+sz);
}
template <class T> int Array<T>::searchEle(T e)const
{
	int loc;
	for(loc = sz-1; loc>=0; loc--)
		if (elements[loc] == e)
			return loc;
	return loc;
}

template <class T>void Array<T>::listAll(ostream& os = cout)
{
	os<<"Elements in array:\n";
	for(int i =0; i<sz; i++)
		os<<elements[i]<<"\t";
	os<<"\n";
}
#endif /* ARRAY_H_ */
