#include<iostream>
#include<iomanip>//格式化输出头文件
#include<time.h>
#include<cstdlib>

using namespace std;

#define MaxSize 5

//矩阵生成
void MatrixCreate(double (*a)[MaxSize],int n)
{

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=rand()%5+1;//生成1-5
		}
	}
}
//矩阵打印
void MatrixPrint(double (*a)[MaxSize],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
//矩阵行列式——转换为上三角进行求解
double Det(double (*a)[MaxSize],int n)
{
	double flag = 1;
	for(int i=0;i<n-1;i++){
		for(int k=i+1;k<n;k++){
			flag = a[k][i]/a[i][i];//注意判断对角线元素是否为零
			for(int j=0;j<n;j++){
				a[k][j]=a[k][j]-flag*a[i][j];
			}
		}
	}
	double factor = 1;
	for(int i=0;i<n;i++){
		factor*=a[i][i];
	}
	return factor;//factor为行列式
}
//矩阵相加
void MatrixAdd(double (*A)[MaxSize], double (*B)[MaxSize], double (*ApB)[MaxSize],int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ApB[i][j] = A[i][j] + B[i][j];
		}
	}
	return;
}

//矩阵求逆——伴随矩阵法
void MatrixInverse(double (*A)[MaxSize],double (*A_I)[MaxSize],int n,int i_Jump,int J_Jump)
{
	for(int j=0;j<n;j++){//先列
		for(int i=0;i<n;i++){
//			A_I[j][i]=pow(-1,i+j)*A[i][j]*Det();
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int n = rand()%5+1;//随机生成一个1-5阶矩阵
	double A[MaxSize][MaxSize],B[MaxSize][MaxSize],ApB[MaxSize][MaxSize]={0};
	//随机生成矩阵
	MatrixCreate(A,n);
	MatrixCreate(B,n);
	//输出矩阵
	cout<<"生成的矩阵A为"<<endl;
	MatrixPrint(A,n);
	cout<<"生成的矩阵B为"<<endl;
	MatrixPrint(B,n);

	//计算A+B
	MatrixAdd(A,B,ApB,n);
	cout<<"生成的矩阵A+B为"<<endl;
	MatrixPrint(ApB,n);
	//计算A^-1
	
	//计算阶乘——行阶梯进行化简
	cout<<"|A|为"<<Det(A,n)<<endl;
	cout<<"|B|为"<<Det(B,n)<<endl;
	cout<<"|A+B|为"<<Det(ApB,n)<<endl;
	cout<<"|A|+|B|为"<<Det(A,n)+Det(B,n)<<endl;
	cout<<"|A||B|为"<<Det(A,n)*Det(B,n)<<endl;
	
}


