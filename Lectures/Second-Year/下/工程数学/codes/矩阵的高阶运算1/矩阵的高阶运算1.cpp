#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>

#define  Row 3

using namespace std;
//相乘
void matrixMul(int (*A)[3],int (*B)[3],int (*ApB)[3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				ApB[i][j] += A[i][k] * B[k][j]; //A(ik)*B(kj)
			}
		}
	}
	
	return;
}
//相加
void matrixAdd(int (*A)[3],int (*B)[3],int (*ApB)[3])
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			ApB[i][j] = A[i][j] + B[i][j];
		}
	}	
	return;
}
//转置
void matrixTrs(int (*A)[3],int (*A_T)[3])
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			A_T[j][i]=A[i][j];//行列对换
		}
	}
	return;
}
//打印
void matrixPrint(int (*A)[3])
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
//结论1
void text1(int A[3][3],int B[3][3],int C[3][3]){
	//计算B+C
	int BpC[3][3]={0};
	matrixAdd(B,C,BpC);
	//计算A（B+C）
	cout<<"A(B+C)"<<endl;
	int AmBpC[3][3]={0};
	matrixMul(A,BpC,AmBpC);
	matrixPrint(AmBpC);
	//计算AB
	int AB[3][3]={0};
	matrixMul(A,B,AB);
	//计算AC
	int AC[3][3]={0};
	matrixMul(A,C,AC);
	//计算AB+AC
	cout<<"AB+AC"<<endl;
	int ABpAC[3][3]={0};
	matrixAdd(AB,AC,ABpAC);
	matrixPrint(ABpAC);

	return;
}
//结论2
void text2(int A[3][3],int B[3][3],int C[3][3]){
	int AB[3][3]={0},BC[3][3]={0},ABmC[3][3]={0},AmBC[3][3]={0};
	//矩阵AB
	matrixMul(A,B,AB);
	//矩阵(AB)C
	matrixMul(AB,C,ABmC);
	matrixPrint(ABmC);
	//矩阵BC
	matrixMul(B,C,BC);

	//矩阵A(BC)
	matrixMul(A,BC,AmBC);
	cout<<"A(BC)为"<<endl;
	matrixPrint(AmBC);
	
	return;
}
//结论3
void text3(int A[3][3],int B[3][3],int C[3][3]){
	int ABC[3][3]={0},ABC_T[3][3],A_T[3][3],B_T[3][3],C_T[3][3],C_TmB_TmA_T[3][3]={0};
	//计算ABC
	int AB[3][3]={0};
	matrixMul(A,B,AB);
	matrixMul(AB,C,ABC);
	//计算ABC转置
	matrixTrs(ABC,ABC_T);
	cout<<"矩阵ABC^T"<<endl;
	matrixPrint(ABC_T);
	//计算A的转置
	matrixTrs(A,A_T);
	//计算B的转置
	matrixTrs(B,B_T);
	//计算C的转置
	matrixTrs(C,C_T);
	//计算转置相乘
	cout<<"矩阵C^TB^TA^T"<<endl;
	int C_TmB_T[3][3]={0};
	matrixMul(C_T,B_T,C_TmB_T);
	matrixMul(C_TmB_T,A_T,C_TmB_TmA_T);
	matrixPrint(C_TmB_TmA_T);
	
	return;
}

int main()
{
	int A[3][3],B[3][3],C[3][3];
	srand((unsigned)time(NULL));
	
	//矩阵随机生成
	cout<<"矩阵A"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			A[i][j] = rand()%5;
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"矩阵B"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			B[i][j] = rand()%5;
			cout<<B[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"矩阵C"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			C[i][j] = rand()%5;
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	
	text1(A,B,C);
	text2(A,B,C);
	text3(A,B,C);
	
	system("pause");
	return 0;
}
