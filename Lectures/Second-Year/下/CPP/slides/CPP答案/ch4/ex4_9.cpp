/*
 * ex4_9.cpp
 *
 * 9. ��д��������0~9��100�����������Ȼ����ʾÿһ�������ֵĴ�����
 *
 *
 */
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
	vector<int> cnt(10, 0);

	for(int i = 0; i < 100; ++i){
		int n = rand() % 10;
		cnt[n]++;
	}

	for(size_t i = 0; i < cnt.size(); ++i)
		cout << i << " : " << cnt[i] << endl;

	return 0;
}



