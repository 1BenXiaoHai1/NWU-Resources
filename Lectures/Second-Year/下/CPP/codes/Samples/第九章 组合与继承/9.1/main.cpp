#include"head.h"

int main()
{
	Head h;
	h.turn();//head类特有的成员函数
	h.nose.smell();//向成员对象发送消息
}
