#include<iostream>

using namespace std;

int CalPigs(int day) {
	if (day == 7) { //终止条件——第七天所剩猪的数量为2
		return 2;
	} else {
		return 2 * CalPigs(day + 1) + 2;
		//第六天猪的数量等于第六天所卖猪的数量+第七天剩的猪的数量
	}
}

void PrintPigs(int sum) {
	int Reminder = sum;//Reminder保存当前的数量
	for (int i = 1; i <= 7; i++) {
		int Total = Reminder;//Total保存前天的剩的的猪的数量
		Reminder = Reminder / 2 - 1; //Reminder修改为卖后的猪的数量
		cout << "经过第" << i << "个村子所卖的猪的数量为" << Total - Reminder << "还剩" << Reminder << endl;
	}
}

int main() {
	int sum = CalPigs(1);
	cout << "总数为" << sum << endl;
	PrintPigs(sum);
	return 0;
}
