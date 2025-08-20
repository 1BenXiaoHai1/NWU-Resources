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
	IntStack(); //ȱʡ���캯��
	explicit IntStack(int size) throw(InvalidStackSize); //ָ����ջ��С
	IntStack(const int a[],int size) throw(InvalidStackSize); //���ַ�����ʼ����ջ
	~IntStack(); //��������
	void clear(); //���ջ
	void push(int e)throw(PushOnFull); //��ջ
	int pop()throw(PopOnEmpty); //��ջ
	int top_of()throw(TopOfEmpty); //����ջ��Ԫ��
	bool empty(); //�ж�ջ�Ƿ�Ϊ��
	bool full(); //�ж�ջ�Ƿ�����
	int capacity(); //����ջ���������
	int size(); //����ջ��Ԫ�ظ���
private:
	int *s; //ջԪ�ش洢�ռ�
	int top; //ջ��ָʾ��
	int max_len; //ջ����󳤶�
	//˽�п������캯������ֹ�����ƺͰ�ֵ����
	IntStack(const IntStack& ); //���Բ�ʵ�֣���Ϊ���ܷ���
};
//---------------------------------------------------


#endif /* INTSTACK_H_ */
