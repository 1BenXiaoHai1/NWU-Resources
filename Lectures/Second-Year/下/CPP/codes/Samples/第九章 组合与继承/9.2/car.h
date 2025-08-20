#include"engine.h"
class Car {
	Engine engine;//私有成员对象
public:
	Car() {//构造函数
		
	}
	~Car() {//析构函数
		
	}
	void Run() {
		engine.Fire();//调用嵌入对象的操作
	}
	
	void Stop()
	{
		engine.stall();//调用嵌入对象的操作
	}
};
