/*
 * ex4_11.cpp
 *
 * 11. ��д���򣬲���һ��6��6�ľ����������0��1����ʾ������󣬼���Ƿ�ÿ�к�ÿ�ж���ż����1��
 *
 *
 */
#include<cstdlib>
#include<iostream>
using namespace std;
const int N = 6;
int main()
{
	int matrix[N][N];

	for(auto row = 0; row < N; ++row)
		for(auto col = 0; col < N; ++col)
			matrix[row][col] = rand() % 2;

	for(auto row = 0; row < N; ++row){
		for(auto col = 0; col < N; ++col)
			cout << matrix[row][col] << " ";
		cout << endl;
	}

	bool evenOne = true;
	for(auto row = 0; row < N; ++row){
		int cnt = 0;
		for(auto col = 0; col < N; ++col)
			if(matrix[row][col] == 1)
				++cnt;
		if(cnt % 2 == 0)
			continue;
		else{
			evenOne = false;
			break;
		}
	}

	if(evenOne)
		for(auto col = 0; col < N; ++col){
			int cnt = 0;
			for(auto row = 0; row < N; ++row)
				if(matrix[row][col] == 1)
					++cnt;
			if(cnt % 2 == 0)
				continue;
			else{
				evenOne = false;
				break;
			}
		}

	if(evenOne)
		cout << "Every row and column has even 1." << endl;
	else
		cout << "Some row or column doesn't have even 1." << endl;

	return 0;
}



