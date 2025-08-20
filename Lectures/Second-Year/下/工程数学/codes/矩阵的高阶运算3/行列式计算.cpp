#include<iostream>
#include<iomanip>//��ʽ�����ͷ�ļ�
#include<time.h>
#include<cstdlib>

using namespace std;

#define MaxSize 5

//��������
void MatrixCreate(double (*a)[MaxSize],int n)
{

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=rand()%5+1;//����1-5
		}
	}
}
//�����ӡ
void MatrixPrint(double (*a)[MaxSize],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//��������ʽ����ת��Ϊ�����ǽ������
double Det(double (*a)[MaxSize],int n)
{
	double flag = 1;
	for(int i=0;i<n-1;i++){
		for(int k=i+1;k<n;k++){
			flag = a[k][i]/a[i][i];//ע���ж϶Խ���Ԫ���Ƿ�Ϊ��
			for(int j=0;j<n;j++){
				a[k][j]=a[k][j]-flag*a[i][j];
			}
		}
	}
	double factor = 1;
	for(int i=0;i<n;i++){
		factor*=a[i][i];
	}
	return factor;//factorΪ����ʽ
}
//�������
void MatrixAdd(double (*A)[MaxSize], double (*B)[MaxSize], double (*ApB)[MaxSize],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ApB[i][j] = A[i][j] + B[i][j];
		}
	}
	return;
}

//�������桪���������
void MatrixInverse(double (*A)[MaxSize],double (*A_I)[MaxSize],int n,int i_Jump,int J_Jump)
{
	for(int j=0;j<n;j++){//����
		for(int i=0;i<n;i++){
//			A_I[j][i]=pow(-1,i+j)*A[i][j]*Det();
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int n = rand()%5+1;//�������һ��1-5�׾���
	double A[MaxSize][MaxSize],B[MaxSize][MaxSize],ApB[MaxSize][MaxSize]={0};
	//������ɾ���
	MatrixCreate(A,n);
	MatrixCreate(B,n);
	//�������
	cout<<"���ɵľ���AΪ"<<endl;
	MatrixPrint(A,n);
	cout<<"���ɵľ���BΪ"<<endl;
	MatrixPrint(B,n);

	//����A+B
	MatrixAdd(A,B,ApB,n);
	cout<<"���ɵľ���A+BΪ"<<endl;
	MatrixPrint(ApB,n);
	//����A^-1
	
	//����׳ˡ����н��ݽ��л���
	cout<<"|A|Ϊ"<<Det(A,n)<<endl;
	cout<<"|B|Ϊ"<<Det(B,n)<<endl;
	cout<<"|A+B|Ϊ"<<Det(ApB,n)<<endl;
	cout<<"|A|+|B|Ϊ"<<Det(A,n)+Det(B,n)<<endl;
	cout<<"|A||B|Ϊ"<<Det(A,n)*Det(B,n)<<endl;
	
}


