#include <iostream>
#include"car.h"

//按值组合 组合关系

int main(int argc, char** argv) {
	
	
	Car benz;//对客户程序隐藏了benz内部的构成
	benz.Run();//隐藏了run是如何完成的
	benz.Stop();

	return 0;
}
