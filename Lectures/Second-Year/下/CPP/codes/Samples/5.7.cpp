#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2) {
	//算法思想——遍历两个vector容器，并且比较两个容器中的元素，将较小元素插入到容器中
	vector<int> list;

	auto it_list1 = list1.begin(), it_list2 = list2.begin();
	while (it_list1 != list1.end() && it_list2 != list2.end()) { //当二者都没结束时，遍历容器
		if (*it_list1 < *it_list2) {
			list.push_back(*it_list1);//将较小元素压入list中
			it_list1++;//此时list1迭代器下移，而list2不改变。还需和list1下一个元素比较
		} else {
			list.push_back(*it_list2);
			it_list2++;
		}
	}
	//此时有可能元素还没进入（容器长度不一致，长的容器元素还没插入）
	//list1容器较长
	while (it_list1 != list1.end()) {
		list.push_back(*it_list1);
		it_list1++;
	}
	//list2容器较长
	while (it_list2 != list2.end()) {
		list.push_back(*it_list2);
		it_list2++;
	}

	return list;
}

int main() {
	vector<int> list1 = {1, 3, 4, 7};
	vector<int> list2 = {2, 5, 6, 8, 9};

	vector<int> List = merge(list1, list2);
	for (auto i = List.begin(); i != List.end(); i++) {
		cout << *i << " ";
	}

	return 0;
}
