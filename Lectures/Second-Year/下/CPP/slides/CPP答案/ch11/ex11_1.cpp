/*
 * ex11_1.cpp
 *
 *  1. 设计一个函数模板bisearch，对一个有序数组采用二分法查找指定元素，返回下标。
 *
 */

#include<iostream>
#include<string>
#include<iterator>
using namespace std;

template <typename T> int bisearch(T arr[], int size, const T& key){
	int low = 0, high = size-1;

	while(low <= high){
		int mid = (low + high) / 2;

		if(key == arr[mid])
			return mid;
		else if(key < arr[mid]){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return -low-1;	//找不到返回负值下标
}


int main(){

	int ia1[] = {1, 2, 3, 4, 5, 6};
	int ia2[] = {1, 3, 5, 7, 7, 9, 11};
	double da1[] = {1.2, 3.4, 5.6, 8.7, 9.9};
	double da2[] = {1.2, 1.2, 1.2};


	cout <<"bisearch(ia1, 6, 3): "<< bisearch(ia1, 6, 3) << endl;
	cout <<"bisearch(ia1, 6, 8): "<< bisearch(ia1, 6, 8) << endl;
	cout <<"bisearch(ia1, 6, 1): "<< bisearch(ia1, 6, 1) << endl;
	cout <<"bisearch(ia2, 7, 7): "<< bisearch(ia2, 7, 7) << endl;
	cout <<"bisearch(ia2, 7, 6): "<< bisearch(ia2, 7, 6) << endl;
	cout <<"bisearch(ia2, 4, 3): "<< bisearch(ia2, 4, 3) << endl;
	cout <<"bisearch(da1, 5, 8.7): "<< bisearch(da1, 5, 8.7) << endl;
	cout <<"bisearch(da1, 5, 3.1): "<< bisearch(da1, 5, 3.1) << endl;
	cout <<"bisearch(da2, 3, 1.3): "<< bisearch(da2, 3, 1.3) << endl;


	return 0;
}


