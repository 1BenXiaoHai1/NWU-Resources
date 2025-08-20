/*
 * intStack.cpp
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

//---------------------------------------------------
//IntStack.cpp
//类实现的源文件
#include <cassert>
#include <iostream>
using namespace std;
#include "IntStack.h"
const int EMPTY = -1;


IntStack::IntStack(int size) throw(InvalidStackSize)
{
	if(size <= 0)
		throw InvalidStackSize(size);
	max_len = size;
	top=EMPTY;
	s = new int[size];
}
IntStack::IntStack(){
	max_len=100;
	top = EMPTY;
	s = new int[100]; //默认栈的大小为100
}
IntStack::IntStack(const int str[],int size)throw(InvalidStackSize)
{
	if(size <= 0)
		throw InvalidStackSize(size);
	max_len = size;
	s = new int[size];
	int i;
	for (i = 0; i<max_len && str[i] != 0; ++i)
		s[i] = str[i];
	top = --i;
}
IntStack::~IntStack() { delete[]s; }
void IntStack::clear() { top = EMPTY; }
void IntStack::push(int c) throw(PushOnFull)
{ if (full())
	throw PushOnFull(c);
s[++top] = c; }
int IntStack:: pop() throw(PopOnEmpty)
{
	if(empty())
		throw PopOnEmpty();
	return s[top--];}
int IntStack::top_of() throw(TopOfEmpty)
{
	if(empty())
		throw TopOfEmpty();
	return s[top]; }
bool IntStack::empty() { return top == EMPTY; }
bool IntStack::full() { return top == max_len - 1; }
int IntStack::capacity() { return max_len; }
int IntStack::size() {return top+1; }
