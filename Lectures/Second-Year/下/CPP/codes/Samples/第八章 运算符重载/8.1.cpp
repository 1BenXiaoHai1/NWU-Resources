//һԪ�����������
#include<iostream>

using namespace std;

class Byte {
	unsigned char b;
public:
	Byte(unsigned char bb=0):b(bb){}
	
	const Byte& operator+() const{//���ŷ��ص�ǰ������
		return *this;
	}
	const Byte operator-() const{//���ŷ��ص�ǰ������෴��
		return Byte(-b);
	}
	const Byte operator~() const{//��λȡ��
		return Byte(~b);
	}
	
	bool Byte operator!() const{//�������
		return !b;
	}
	//�и����õ����������Ϊ��const��Ա����
	const Byte operator++(){//ǰ׺++ ���� ���������ٷ���
		b++;
		return *this;
	}
	const Byte operator++(int){//��׺++ ���� ���������ٷ��ء�������ǰ��׺ �������ڼ�int����ǰ׺�ͺ�׺����
		Byte before(b);//ֱ�ӳ�ʼ��
		b++;
		return before;
	}
	const Byte& operator--(){//ǰ׺--
		--b;
		return *this;
	}
	const Byte operator--(int){//��׺--
		Byte before(b);
		--b;
		return before;
	}
	
};

int main()
{
	Byte b;
	+b;
	-b;
	~b;
	!b;
	++b;
	b++;
	--b;
	b--;
}
