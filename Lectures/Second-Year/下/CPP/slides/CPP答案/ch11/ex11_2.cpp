/*
 * ex11_2.cpp
 *
 *  2. 设计一个函数模板，对有n 个元素的数组arr 求最大值。
 */


#include<iostream>
#include<string>
using namespace std;

template <typename T> T max(T arr[], int n){
	T maxVal = arr[0];
	for(int index = 1; index < n; ++index){
		if(maxVal < arr[index])
			maxVal = arr[index];
	}
	return maxVal;
}

int main(){
	int ia1[] = {21, 22, 31, 43, 5, 16};
	int ia2[] = {11, 3, 15, 71, 17, 29, 31};
	double da1[] = {8.2, 6.4, 5.6, 7.7, 2.9};
	double da2[] = {7.2, 1.6, 4.5};
	string sa[] = {"ab", "12", "090"};
	cout<<max(ia1, 6)<<endl;
	cout<<max(ia2, 7)<<endl;
	cout<<max(da1, 5)<<endl;
	cout<<max(da2, 5)<<endl;
	cout<<max(sa, 3)<<endl;

}
