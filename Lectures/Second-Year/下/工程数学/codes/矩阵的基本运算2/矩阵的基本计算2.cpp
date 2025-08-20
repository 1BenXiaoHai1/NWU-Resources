#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>

using namespace std;

void matrixTransform();//随机生成矩阵,并输出其转置矩阵
void matrix_ETransform();//生成单位矩阵并输出其转置后的矩阵

int main()
{
	matrixTransform();
	matrix_ETransform();
}

void matrixTransform()
{
	srand(time(NULL));//随机数种子

	int row = rand()%5,column = rand()%5;
	int matrix1[row][column];//原矩阵
	int matrix2[column][row];//转置后矩阵（转置矩阵行列对调）
	//矩阵随机生成
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			matrix1[i][j]=rand()%10;
		}
	}
	cout<<"生成的矩阵为"<<endl;
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			cout<<matrix1[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	//转置
	for(auto i=0;i<row;i++){
		for(auto j=0;j<column;j++){
			matrix2[j][i]=matrix1[i][j];//行列对换
		}
	}
	cout<<"转置后的矩阵为"<<endl;
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
	memset(matrix_E,0,sizeof(matrix_E));//二维矩阵初始化
	//生成单位阵
	for(int i=0;i<size;i++){
		matrix_E[i][i]=1;//对角线元素设为1
	}
	//输出生成的单位阵
	cout<<"生成的单位阵为"<<endl;
	for(auto i=0;i<size;i++){
		for(auto j=0;j<size;j++){
			cout<<matrix_E[i][j]<<"\t";
		}
		cout<<endl;
	}
	//单位阵的转置与其本身相同
	cout<<"转置后的单位阵为"<<endl;
	for(auto i=0;i<size;i++){
		for(auto j=0;j<size;j++){
			cout<<matrix_E[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}
