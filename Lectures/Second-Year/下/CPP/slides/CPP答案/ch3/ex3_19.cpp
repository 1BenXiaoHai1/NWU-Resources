/*
 * ex3_19.cpp
 *
 * 19. ��д�����г�������1��2��3��4 ��ɵĻ�����ͬ�����ظ����ֵ���λ����
 */
#include <iostream>
using namespace std;
int main()
{
	for(int i = 1; i<=4; i++){
		for(int j=1; j<=4; j++)
			for(int k=1; k<=4; k++)
				if(i!=j && i!=k && j!=k)
					cout<<i*100+j*10+k<<"\t";
			cout<<"\n";
	}
}


