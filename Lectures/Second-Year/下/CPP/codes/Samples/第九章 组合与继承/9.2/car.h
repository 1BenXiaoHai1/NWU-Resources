#include"engine.h"
class Car {
	Engine engine;//˽�г�Ա����
public:
	Car() {//���캯��
		
	}
	~Car() {//��������
		
	}
	void Run() {
		engine.Fire();//����Ƕ�����Ĳ���
	}
	
	void Stop()
	{
		engine.stall();//����Ƕ�����Ĳ���
	}
};
