/*
 * ex11_3.cpp
 *
 *  3. 编写一个通用函数，交换同类型的两个变量值。
 */
#include<iostream>
#include<string>
using namespace std;

template <typename T> void exchange(T& val1, T& val2){
	T t = val1;
	val1 = val2;
	val2 = t;
}


int main(){
	string s1="abc", s2 = "123";
	int n1 = 12, n2 = 23;
	double d1 = 1.3, d2 = 7.8;


	cout << "before calling exchage()" << endl;
	cout << s1 << "\t" << s2 << endl;
	cout << n1 << "\t" << n2 << endl;
	cout << d1 << "\t" << d2 << endl;

	exchange(s1, s2);
	exchange(n1, n2);
	exchange(d1, d2);

	cout << "after calling exchange()" << endl;
	cout << s1 << "\t" << s2 << endl;
	cout << n1 << "\t" << n2 << endl;
	cout << d1 << "\t" << d2 << endl;

	return 0;

}



