#include<iostream>
using namespace std;

#define m 16
#define NULLKEY 0 //单元为空的标记

//哈希表
struct HashTable {
	int  key;
};

void CreateHash(HashTable HT[], int n); //创建哈希表
int SearchHash(HashTable HT[], int key); //查找

void Print(HashTable HT[]) {
	for (int i = 0; i < m; i++) {
		printf("%d ", HT[i].key);
	}
}

int main() {
	int value, key;
	int result;
	int i, j, n;
	HashTable HT[m];//创建哈希表
	//哈希表初始化
	for (i = 0; i < m; i++)
		HT[i].key = 0;
	cin >> n;//有效数据数
	if (n > m) return 0;
	CreateHash(HT, n);
	Print(HT);
	cout << endl;
	cin >> key;
	result = SearchHash(HT, key);
	if (result != -1)
		cout << "search success，The key is located in " << result + 1;
	else
		cout << "search failed";
	return 0;
}


/* 请在这里填写答案 */
//创建-除余法
void CreateHash(HashTable HT[], int n) {
	//输入n个数据
	int key;
	for (int i = 0; i < n; i++) {
		scanf("%d", &key);
		//根据哈希函数计算对应哈希表中的位置并插入元素
		int pos = key % 13 ;
		//判断插入位置是否有冲突——采用线性探测法解决冲突
		while (HT[pos].key != 0) {
			pos = pos + 1; //顺序寻找下一位置
		}
		//已找到插入位置
		HT[pos].key = key;
	}
}

int SearchHash(HashTable HT[], int key) {
	int H0 = key % 13;
	//利用哈希表查找元素
	if (HT[H0].key == NULLKEY) {
		return -1;
	} else if (HT[H0].key == key) {
		return H0;
	} else { //线性探测解决冲突
		for (int i = 1; i <= m - 1; i++) {
			int Hi = (H0 + i) % m; //顺序下一个位置
			if (HT[Hi].key == NULLKEY) {
				return -1;
			} else if (HT[Hi].key == key) {
				return Hi;
			}
		}
		return -1;
	}
}

