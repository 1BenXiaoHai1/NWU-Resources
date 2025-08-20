/*
 * intStack.h
 *
 *  Created on: 2010-9-24
 *      Author: ibm
 */

#ifndef INTSTACK_H_
#define INTSTACK_H_
#include "stackexception.h"
class IntStack{
public:
	IntStack(); //缺省构造函数
	explicit IntStack(int size) throw(InvalidStackSize); //指定堆栈大小
	IntStack(const int a[],int size) throw(InvalidStackSize); //用字符串初始化堆栈
	~IntStack(); //析构函数
	void clear(); //清空栈
	void push(int e)throw(PushOnFull); //进栈
	int pop()throw(PopOnEmpty); //出栈
	int top_of()throw(TopOfEmpty); //返回栈顶元素
	bool empty(); //判断栈是否为空
	bool full(); //判断栈是否已满
	int capacity(); //返回栈的最大容量
	int size(); //返回栈中元素个数
private:
	int *s; //栈元素存储空间
	int top; //栈顶指示器
	int max_len; //栈的最大长度
	//私有拷贝构造函数，禁止对象复制和按值传递
	IntStack(const IntStack& ); //可以不实现，因为不能访问
};
//---------------------------------------------------


#endif /* INTSTACK_H_ */
