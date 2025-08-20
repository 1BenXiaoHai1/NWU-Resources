#include<iostream>

using namespace std;

void Insert(int nums[], int n, int X) {
	//查找指定位置——顺序查找
	int pos = n;
	//递增
	for (int i = 0; i < n; i++) {
		if (X <= nums[i]) { //小于时说明找到了插入位置（数组内部）
			pos = i;
			break;
		}
	}
	//元素后移(只有在数组内部才要后移元素)
	if (pos != n - 1) {
		for (int i = n; i >= pos; i--) {
			nums[i + 1] = nums[i];
		}
	}
	//插入元素
	nums[pos] = X;
}

int main() {
	int n;
	cin >> n;
	int nums[100] = {};
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int X;
	cin >> X;
	Insert(nums, n, X);
	//输出
	for (int i = 0; i < n + 1; i++) {
		if (i == n) {
			cout << nums[i];
		} else {
			cout << nums[i] << ",";
		}
	}
	return 0;
}
