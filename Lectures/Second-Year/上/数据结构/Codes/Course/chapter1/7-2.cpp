#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	//输出处理
	cout << nums[0];
	int i, j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (nums[i] == nums[j])
				break;
		if (j == i) { //输出下标相同的
			cout << " " << nums[i];
		}

	}
	return 0;
}
