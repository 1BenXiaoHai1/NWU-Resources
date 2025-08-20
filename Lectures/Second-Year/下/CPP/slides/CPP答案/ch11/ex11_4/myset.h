/*
 * myset.h
 *
 *  ch11
 *  4. 设计并实现一个通用集合类。
 */

#ifndef MYSET_H_
#define MYSET_H_
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;
template<class Type> class MySet {
public:
	MySet() = default;
	~MySet() = default;
	MySet(const MySet<Type>& s) :elements(s.elements) {}
	MySet& operator=(const MySet<Type>& s) = default;
	void add(Type val);
	void remove(Type val);
	bool contain(Type val);
	MySet<Type> trans(MySet<Type>& s);
	MySet<Type> merge(MySet<Type>& s);
	void listAll(ostream& os = cout);
private:
	list<Type> elements;
};
template<class Type> void MySet<Type>::add(Type val) {
	if (contain(val))
		return;
	else
		elements.push_back(val);
}
template<class Type> void MySet<Type>::remove(Type val) {
	auto it = find(elements.begin(), elements.end(), val);
	if (it != elements.end()) {
		elements.erase(it);
	}
}

template<class Type> bool MySet<Type>::contain(Type val) {
	auto it = find(elements.begin(), elements.end(), val);
	if (it != elements.end())
		return true;
	else
		return false;
}

template<class Type> MySet<Type> MySet<Type>::trans(MySet<Type>& s) {
	MySet<Type> result;
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		if (s.contain(*it))
			result.add(*it);
	}
	return result;
}

template<class Type> MySet<Type> MySet<Type>::merge(MySet<Type>& s) {
	MySet<Type> result;
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		result.add(*it);
	}
	for (auto it = s.elements.begin(); it != s.elements.end(); ++it) {
		result.add(*it);
	}
	return result;
}

template<class Type> void MySet<Type>::listAll(ostream& os) {
	os << "\n";
	for (auto it = elements.begin(); it != elements.end(); ++it) {
		os << *it << "\t";
	}
	os << "\n";
}

#endif /* MYSET_H_ */
