#include<stdio.h>

int n, m, K; //哈希函数关键字
int Nums[100];

//哈希函数
int Hash(int key) {
	return key % K;
}

//创建哈希表
void CreateHash(int HT[]) {
	for (int i = 0; i < n; i++) {
		int key;
		scanf("%d", &key);
		Nums[i] = key; //把有效数值保存起来
		//根据哈希函数计算对应哈希表中的位置并插入元素
		int pos = Hash(key) ;
		//判断插入位置是否有冲突——采用线性探测法解决冲突
		while (HT[pos] != 0) {
			pos = (pos + 1) % m; //顺序寻找下一位置
		}
		//已找到插入位置
		HT[pos] = key;
	}
}

//查找成功
double SearchSucc(int HT[]) {
	//求和
	int sum = 0;
	//遍历每个有效元素，计算其比较次数，并求和
	for (int i = 0; i < n; i++) {
		int H0 = Hash(Nums[i]);
		sum++;//有效次数+1
		if (HT[H0] != Nums[i]) { //一次未找到，采用线性探测再散列解决冲突
			for (int k = 1; k < m - H0; k++) {
				sum++;//比较次数+1
				int Hi = (H0 + k) % m;//线性探测再散列下一次查找位置——顺序
				//相等跳出查找
				if (HT[Hi] == Nums[i]) {
					break;
				}
			}
		}
	}

	return (double)sum / n;
}

//查找失败
double SearchUnSucc(int HT[]) {
	int sum = 0;
	//对于哈希表中每个元素都需要计算
	//查找失败的时候，需要一直查到第一个为空的地址
	for (int i = 0; i < m; i++) {
		if (HT[i] == 0) { //第一个为空，不需要继续向后查
			sum++;
		} else {
			sum++;//比较次数+1
			for (int k = 1; k < m; k++) {
				sum++;//比较次数+1
				//找到后续元素的第一个为空的
				if (HT[(i + k) % m] == 0) {
					break;
				}
			}
		}
	}

	return (double)sum / m;
}

void Print(int HT[]) {
	for (int i = 0; i < m; i++) {
		printf("%d ", HT[i]);
	}
}

int main() {
	while (scanf("%d %d %d", &n, &m, &K) != EOF) {
		int HT[100] = {0}; //哈希表
		CreateHash(HT);
		Print(HT);
		printf("\n");
		printf("%.2lf %.2lf", SearchSucc(HT), SearchUnSucc(HT));
	}

	return 0;
}
