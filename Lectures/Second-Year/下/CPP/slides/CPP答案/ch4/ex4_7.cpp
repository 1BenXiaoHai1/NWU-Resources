/*
 * ex4_7.cpp
 *
 * 7. 编写程序，判断两个数组是否相等，然后利用vector编写一段类似的程序。
 *
 *
 */
#include <iostream>
#include <vector>
using namespace std;
const int N = 3;
int main()
{
	int a[N], b[N];
	cout<<"Please input array elements:"<< endl;

	cout << "array A: " ;
	for(auto &e : a) cin >> e;

	cout << "array B: " ;
	for(auto &e : b) cin >> e;

	bool equal = true;
	for(int i=0; i<N; i++){
		if(a[i]==b[i])
			continue;
		else
			equal = false;
	}

	cout<<"\n Array A:";
	for(auto e : a) cout<< e <<"  ";
	cout<<"\n Array B:";
	for(auto e : b) cout<< e <<"  ";
	cout<<"\n A == B ? " <<( equal ? "yes" : "no" )<<endl;

	//vector
	cout<<"Please input vector elements:"<<endl;
	vector<int>va(N),vb(N);

	cout << "vector A: ";
	for(auto &e : va) cin >> e;

	cout << "vector B: ";
	for(auto &e : vb) cin >> e;

	cout<<"\nvector A:";
	for(auto e : va) cout << e << "  ";
	cout<<"\nvector B:";
	for(auto e : vb) cout << e << "  ";

	cout<<"\n A == B ? "<<((va==vb)? "yes" : "no") << endl;
}


