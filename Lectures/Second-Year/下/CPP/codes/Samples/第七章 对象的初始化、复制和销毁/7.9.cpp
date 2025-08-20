#include<iostream>
#include<cassert>
#include<utility>

using namespace std;

//IntArray类的定义
class IntArray {
	size_t arrSize=0;//数组大小
	int *ptr = nullptr;//数组首地址
public:
	//成员函数声明
	IntArray();//默认构造函数
	IntArray(const IntArray& ia);//拷贝构造函数
	IntArray(IntArray&& ia)noexcept;//移动构造函数
	IntArray(int ia[],size_t size);
};

//成员函数定义
IntArray::IntArray():arrSize(0),ptr(nullptr){}
IntArray::IntArray(const IntArray& ia):arrSize(ia.arrSize)
{
	//深复制
	ptr = new int[arrSize];//新开辟一片内存
	for(size_t i=0;i<arrSize;i++){
		ptr[i]=ia.ptr[i];
	}
}
//移动构造函数
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
