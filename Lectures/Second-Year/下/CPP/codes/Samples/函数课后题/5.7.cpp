#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> list1, vector<int> list2) {
	//�㷨˼�롪����������vector���������ұȽ����������е�Ԫ�أ�����СԪ�ز��뵽������
	vector<int> list;

	auto it_list1 = list1.begin(), it_list2 = list2.begin();
	while (it_list1 != list1.end() && it_list2 != list2.end()) { //�����߶�û����ʱ����������
		if (*it_list1 < *it_list2) {
			list.push_back(*it_list1);//����СԪ��ѹ��list��
			it_list1++;//��ʱlist1���������ƣ���list2���ı䡣�����list1��һ��Ԫ�رȽ�
		} else {
			list.push_back(*it_list2);
			it_list2++;
		}
	}
	//��ʱ�п���Ԫ�ػ�û���루�������Ȳ�һ�£���������Ԫ�ػ�û���룩
	//list1�����ϳ�
	while (it_list1 != list1.end()) {
		list.push_back(*it_list1);
		it_list1++;
	}
	//list2�����ϳ�
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
