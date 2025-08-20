#include<iostream>
#include<cassert>
#include<utility>

using namespace std;

//IntArray��Ķ���
class IntArray {
	size_t arrSize=0;//�����С
	int *ptr = nullptr;//�����׵�ַ
public:
	//��Ա��������
	IntArray();//Ĭ�Ϲ��캯��
	IntArray(const IntArray& ia);//�������캯��
	IntArray(IntArray&& ia)noexcept;//�ƶ����캯��
	IntArray(int ia[],size_t size);
};

//��Ա��������
IntArray::IntArray():arrSize(0),ptr(nullptr){}
IntArray::IntArray(const IntArray& ia):arrSize(ia.arrSize)
{
	//���
	ptr = new int[arrSize];//�¿���һƬ�ڴ�
	for(size_t i=0;i<arrSize;i++){
		ptr[i]=ia.ptr[i];
	}
}
//�ƶ����캯��
IntArray::IntArray(IntArray&& ia)noexcept:arrSize(ia.arrSize),ptr(ia.ptr)
{
	ia.arrSize = 0;
	ia.ptr=nullptr;
}

IntArray::IntArray(int ia[],size_t size)
{
	assert(size>0);
	arrSize=size;
	ptr = new int[arrSize];
	for(size_t i=0;i<arrSize;i++){
		ptr[i]=ia[i];
	}
}
