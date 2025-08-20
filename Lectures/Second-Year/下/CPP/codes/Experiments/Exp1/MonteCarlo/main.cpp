//Monte Carlo�㷨
#include<iostream>
//���������ͷ�ļ�
#include<cstdlib>
#include<ctime>

using namespace std;

//Ͷ�����Ϊ100000��
const int nExper = 100000;

int main()
{
	int cnt=0;//��Ͷ������ ����Բ�ڵĵ���
	double Pi;

	//���������
	unsigned seed;
	seed=time(0);
	srand(seed);

	//ͨ���������Ͷ�����ڲ�ͬ����ĸ��ʣ�����ʾ�����
	for(int i=0;i<nExper;i++){
		//������ɣ�x����0~100 y����0~100��
		int x = rand()%100;
		int y = rand()%100;
		//cout<<"���ɵĵ�Ϊ:"<<x<<' '<<y<<endl;
		//���λ���ж�(����Բ��)
		if((x-50)*(x-50)+(y-50)*(y-50)<=2500){
			cnt++;
		}
	}
	//������ʣ���Pi
	Pi = static_cast<double>(cnt)/nExper*4;//���ʱ�ʾ�����
	cout.precision(3);//���������ʽΪ3λС��
	cout<<"Pi��ֵΪ"<<fixed<<Pi;

	return 0;

}
