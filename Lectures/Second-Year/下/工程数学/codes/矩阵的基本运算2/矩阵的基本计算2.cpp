#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>

using namespace std;

void matrixTransform();//������ɾ���,�������ת�þ���
void matrix_ETransform();//���ɵ�λ���������ת�ú�ľ���

int main()
{
	matrixTransform();
	matrix_ETransform();
}

void matrixTransform()
{
	srand(time(NULL));//���������

	int row = rand()%5,column = rand()%5;
	int matrix1[row][column];//ԭ����
	int matrix2[column][row];//ת�ú����ת�þ������жԵ���
	//�����������
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			matrix1[i][j]=rand()%10;
		}
	}
	cout<<"���ɵľ���Ϊ"<<endl;
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			cout<<matrix1[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	//ת��
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			matrix2[j][i]=matrix1[i][j];//���жԻ�
		}
	}
	cout<<"ת�ú�ľ���Ϊ"<<endl;
	for(auto i=0;i<column;i++){
		for(auto j=0;j<row;j++){
			cout<<matrix2[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
}

void matrix_ETransform()
{
	srand(time(NULL));
	int size = rand()%5;
	int matrix_E[size][size];
	memset(matrix_E,0,sizeof(matrix_E));//��ά�����ʼ��
	//���ɵ�λ��
	for(int i=0;i<size;i++){
		matrix_E[i][i]=1;//�Խ���Ԫ����Ϊ1
	}
	//������ɵĵ�λ��
	cout<<"���ɵĵ�λ��Ϊ"<<endl;
	for(auto i=0;i<size;i++){
		for(auto j=0;j<size;j++){
			cout<<matrix_E[i][j]<<"\t";
		}
		cout<<endl;
	}
	//��λ���ת�����䱾����ͬ
	cout<<"ת�ú�ĵ�λ��Ϊ"<<endl;
	for(auto i=0;i<size;i++){
		for(auto j=0;j<size;j++){
			cout<<matrix_E[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}
