/*
 * ex4_9.cpp
 *
 * 9. 编写程序，生成0~9的100个随机整数，然后显示每一个数出现的次数。
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



