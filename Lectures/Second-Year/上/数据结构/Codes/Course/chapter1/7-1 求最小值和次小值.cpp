//7-1 求最小值和次小值
#include<iostream>

using namespace std;

void Quicksort(int nums[], int low, int high) {
	if (low >= high) {
		return;
	}
	int first = low;
	int last = high;
	int key = nums[first];
	while (first < last) {
		//从右往左找一个比arr[left]小的值
		while (first < last && nums[last] >= key) {
			--last;
		}
		nums[first] = nums[last];
		//从左往右找一个比arr[left]要大的值
		while (first < last && nums[first] <= key) {
			++first;
		}
		nums[last] = nums[first];
	}
	nums[first] = key;
	Quicksort(nums, low, first - 1);    //排左边
	Quicksort(nums, last + 1, high);    //排右边
}

int main() {
	int n;
	cin >> n;
	int nums[n];
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	if (n < 2) { //输入数据少于两个
		cout << "Invalid Input";
	} else {
		//quicksort (small - big)
		Quicksort(nums, 0, n - 1);
		int min = nums[0], sub_min;
		bool flag = true;
		//查找次最小值
		for (int i = 1; i < n; i++) {
			sub_min = nums[i];
			if (sub_min != min) { //存在次最小值
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "There is no second smallest element";
		} else {
			cout << min << " " << sub_min << endl;
		}
	}

	return 0;
}
