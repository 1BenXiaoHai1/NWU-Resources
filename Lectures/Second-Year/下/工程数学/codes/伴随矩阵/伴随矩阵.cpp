#include <stdio.h>
#include <math.h>

float determinant(float matrix[20][20],int order);
float cofactor(float matrix[20][20],int order,int r,int c);
float adjugate_matrix(float matrix[20][20],int order,int r,int c);
void show_adjugate_matrix(float matrix[20][20],int order);
void menu(void);

int main()
{
	float matrix[20][20];
	int r,c,i,j,choice;
	
	//��������
	printf("���������й�ģ:");
	scanf("%d",&r);
	printf("���������й�ģ:");
	scanf("%d",&c);
	printf("����һ�� %d �� %d ����:\n",r,c);
	for(i = 0;i < r;i ++)
		for(j = 0;j < c;j ++)
			scanf("%f",&matrix[i][j]);
	//�ж�����ľ����Ƿ���ڰ������
	if(r != c)
		printf("�Ƿ��󲻴��ڰ������!\n");
	else
		{
			printf("����İ������Ϊ:\n");
			show_adjugate_matrix(matrix,r);
		}
	return 0;
		
}

float determinant(float matrix[20][20],int order)
{
	float result = 0,sign = 1;
	int i;
	
	if(order == 1)
		result = matrix[0][0];
	else
		for(i = 0;i < order;i ++)
	{
		result += sign * matrix[i][0] * cofactor(matrix,order,i,0);
		sign *= -1;
	}
	
	return result;
}

float cofactor(float matrix[20][20],int order,int r,int c)
{
	float result = 0,cofactor[20][20];
	int original_i,original_j,i,j;
	
	for(i = 0;i < order;i ++)
		for(j = 0;j < order;j ++)
	{
		original_i = i;
		original_j = j;
		if(i == r || j == c);
		else
		{
			if(i > r)
				i --;
			if(j > c)
				j --;
			cofactor[i][j] = matrix[original_i][original_j];
			i = original_i;
			j = original_j;
		}
	}
	if(order >= 2)
		result = determinant(cofactor,order - 1);
	
	return result;
}

float adjugate_matrix(float matrix[20][20],int order,int r,int c)
{
	float result = 0;
	
	if(order == 1 && r == 0 && c == 0)
		result = 1;
	else
		result = pow(-1,r + c) * cofactor(matrix,order,c,r);
	if(result <= 0 && result >= -0.0005)
		result = fabs(result);
	
	return result;
}

void show_adjugate_matrix(float matrix[20][20],int order)
{
	int i,j;
	
	for(i = 0;i < order;i ++)
	{
		for(j = 0;j < order;j ++)
			printf("%.3f\t",adjugate_matrix(matrix,order,i,j));
		printf("\n");
	}
}

